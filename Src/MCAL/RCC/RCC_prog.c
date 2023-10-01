/**
 * @file RCC_prog.c
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the implementation of
 *        the RCC APIs.
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/STM32F103xx.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/RCC/RCC_private.h"
#include "../../../Inc/MCAL/RCC/RCC_config.h"


void RCC_vidInit(void){
    // set the system clock source
    CLEAR_BIT(RCC_Regs->CFGR, 0);
    CLEAR_BIT(RCC_Regs->CFGR, 1);
    RCC_Regs->CFGR |= (0x3 & SET_SYSTEM_CLOCK_SOURCE);
    // Set the clock security system
    CLEAR_BIT(RCC_Regs->CR, 19);
    RCC_Regs->CR |= (SET_CLOCK_SECURITY_SYSTEM << 19);
    // set the external clock type
#if SET_SYSTEM_CLOCK_SOURCE == RCC_HSE_BYPASS || SET_SYSTEM_CLOCK_SOURCE == RCC_HSE
    // set the external clock to be bypass
    SET_BIT(RCC_Regs->CR, 16); // hse on
    RCC_Regs->CR |= (SET_CLOCK_SECURITY_SYSTEM & 0x4); // set bypass if enabled
    uint32_t RCC_ClkRdyTimeout = 0;
    while (!GET_BIT(RCC_Regs->CR, 17) && RCC_ClkRdyTimeout < 10000)
        RCC_ClkRdyTimeout++;            
#elif SET_SYSTEM_CLOCK_SOURCE == RCC_HSI
    // set the hsi on
    SET_BIT(RCC_Regs->CR, 0);
    // wait until the hsi is stable
    uint32_t RCC_ClkRdyTimeout = 0;
    while (!GET_BIT(RCC_Regs->CR, 0) && RCC_ClkRdyTimeout < 10000)
        RCC_ClkRdyTimeout++;        

#elif SET_SYSTEM_CLOCK_SOURCE == RCC_PLL
#if PLL_SOURCE != PLL_DISABLED
    // set the source of the phase locked loop
    RCC_Regs->CFGR &= ~(BIT_MASK << RCC_CFGR_PLLSRC);
    RCC_Regs->CFGR &= ~(BIT_MASK << RCC_CFGR_PLLXTPRE);
    RCC_Regs->CFGR |= (PLL_SOURCE << RCC_CFGR_PLLSRC);
    // set the value of the phase locked loop
    RCC_Regs->CFGR &= ~(0xf << RCC_CFGR_PLLMUL);
    RCC_Regs->CFGR |= (PLL_MULTIPLICATION_VALUE << RCC_CFGR_PLLMUL);
    // set the system clock to pll clock
    RCC_Regs->CR |= (BIT_MASK << RCC_CR_PLLON);        
    // wait until the PLL is ready and stable
    uint32_t RCC_ClkRdyTimeout = 0;
    while(!GET_BIT(RCC_Regs->CR, 25) && RCC_ClkRdyTimeout < 10000)
        RCC_ClkRdyTimeout++;    
#endif
#endif
// set the mcu clock output source    
    RCC_Regs->CFGR &= ~(7 << 24);
    RCC_Regs->CFGR |= (SET_MCU_CLK_OUTPUT_SRC << 24);
/* set system prescalers */
// AHB bus prescaler
    // clear the bits of the HPRE
    RCC_Regs->CFGR &= ~(0xf << 4);
    // set the value of the prescaler
    RCC_Regs->CFGR |= (SET_AHB_CLOCK_PRESCALER << 4);
// APB1 Bus Prescaler
    // clear the bits of the PPRE1
    RCC_Regs->CFGR &= ~(0x7 << 8);
    // set the value of the prescaler
    RCC_Regs->CFGR |= (SET_APB1_CLOCK_PRESCALER << 8);
// APB2 Bus Prescaler
    // clear the bits of the PPRE2
    RCC_Regs->CFGR &= ~(0x7 << 11);
    // set the value of the prescaler
    RCC_Regs->CFGR |= (SET_APB2_CLOCK_PRESCALER << 11);
// USB Prescaler
    // clear the bits of the USBPRE
    RCC_Regs->CFGR &= ~(0x1 << 22);
    // set the value of the prescaler
    RCC_Regs->CFGR |= (SET_USB_PRESCALER << 22);
// ADC Prescaler
    // clear the bits of the ADCPRE
    RCC_Regs->CFGR &= ~(0x7 << 14);
    // set the value of the prescaler
    RCC_Regs->CFGR |= (SET_ADC_PRESCALER << 14);
}

ErrorStates_t RCC_enuEnablePeripheralClock(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID){
    if(Copy_u8BusID == _AHB_ID_){
        // enable the clock in the AHB bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if(Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->AHBENR |= (BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->AHBENR = AHBENR_ALL_VALUE;
    }else if(Copy_u8BusID == _APB1_ID_){
        // enable the clock in the APB1 bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if(Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->APB1ENR |= (BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->APB1ENR = APB1ENR_ALL_VALUE;
    }else if(Copy_u8BusID == _APB2_ID_){
        // enable the clock in the APB2 bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if(Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->APB2ENR |= (BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->APB2ENR = APB2ENR_ALL_VALUE;
    }else{
        return ES_OUT_OF_RANGE;
    }

    return ES_OK;
}

ErrorStates_t RCC_enuDisablePeripheralClock(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID){
    if(Copy_u8BusID == _AHB_ID_){
        // disable the clock in the AHB bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if(Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->AHBENR &= ~(BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->AHBENR = AHBENR_RESET_VALUE;
    }else if(Copy_u8BusID == _APB1_ID_){
        // disable the clock in the APB1 bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if(Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->APB1ENR &= ~(BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->APB1ENR = APB1ENR_RESET_VALUE;
    }else if(Copy_u8BusID == _APB2_ID_){
        // disable the clock in the APB2 bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if(Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->APB2ENR &= ~(BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->APB2ENR = APB2ENR_RESET_VALUE;
    }else{
        return ES_OUT_OF_RANGE;
    }

    return ES_OK;
}

ErrorStates_t RCC_enuResetPeripheral(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID){
    if(Copy_u8BusID == _APB1_ID_){
        // reset the peripheral {Copy_u8PeripheralID} in the APB1 bus 
        // set the corresponding bit to the peripheral in the APB1RSTR
        if(Copy_u8PeripheralID != _ALL_PERIPHERALS_){
            RCC_Regs->APB1RSTR |= (BIT_MASK << Copy_u8PeripheralID);
            RCC_Regs->APB1RSTR &= ~(BIT_MASK << Copy_u8PeripheralID);
        }else{
            RCC_Regs->APB1RSTR = APB1ENR_ALL_VALUE;
            RCC_Regs->APB1RSTR = 0x00000000;
        }         
    }else if(Copy_u8BusID == _APB2_ID_){
        // reset the peripheral {Copy_u8PeripheralID} in the APB2 bus 
        // set the corresponding bit to the peripheral in the APB2RSTR
        if(Copy_u8PeripheralID != _ALL_PERIPHERALS_){
            RCC_Regs->APB2RSTR |= (BIT_MASK << Copy_u8PeripheralID);
            RCC_Regs->APB2RSTR &= ~(BIT_MASK << Copy_u8PeripheralID);
        }else{
            RCC_Regs->APB2RSTR = APB2ENR_ALL_VALUE;
            RCC_Regs->APB2RSTR = 0x00000000;
        } 
    }else{
        return ES_OUT_OF_RANGE;
    }

    return ES_OK;
}