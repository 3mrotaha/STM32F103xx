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
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

static uint8_t RCC_Au8HCLKPrescaller[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
static uint8_t RCC_Au8PCLKxPrescaller[] = {0, 0, 0, 0, 1, 2, 3, 4};

void RCC_vidInit(void)
{
    // set the external clock type
#if SET_SYSTEM_CLOCK_SOURCE == RCC_HSE_BYPASS || SET_SYSTEM_CLOCK_SOURCE == RCC_HSE
    // set the external clock to be bypass
    SET_BIT(RCC_Regs->CR, 16);                         // hse on
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
    // set the value of the phase locked loop
    RCC_Regs->CFGR &= ~(0xf << RCC_CFGR_PLLMUL);
    RCC_Regs->CFGR |= (PLL_MULTIPLICATION_VALUE << RCC_CFGR_PLLMUL);
    // PLL SRC
    if(PLL_SOURCE == PLL_HIGH_EXTERNAL_DIV2_OSC || PLL_SOURCE == PLL_HIGH_EXTERNAL_OSC){    
        SET_BIT(RCC_Regs->CR, 16);
        // wait until the hse is stable
        uint32_t RCC_ClkRdyTimeout = 0;
        while (!GET_BIT(RCC_Regs->CR, 17))
            RCC_ClkRdyTimeout++;
        // set the source of the phase locked loop
        RCC_Regs->CFGR &= ~(BIT_MASK << RCC_CFGR_PLLSRC);
        RCC_Regs->CFGR &= ~(BIT_MASK << RCC_CFGR_PLLXTPRE);
        RCC_Regs->CFGR |= (PLL_SOURCE << RCC_CFGR_PLLSRC);
    }
    else{
        // wait until the hsi is stable
        SET_BIT(RCC_Regs->CR, 0);
        uint32_t RCC_ClkRdyTimeout = 0;
        while (!GET_BIT(RCC_Regs->CR, 1))
            RCC_ClkRdyTimeout++;
        CLEAR_BIT(RCC_Regs->CR, 16);
    }    
    // set the system clock to pll clock
    RCC_Regs->CR |= (BIT_MASK << RCC_CR_PLLON);
    // wait until the PLL is ready and stable
    uint32_t RCC_ClkRdyTimeout = 0;
    while (!GET_BIT(RCC_Regs->CR, 25) && RCC_ClkRdyTimeout < 10000)
        RCC_ClkRdyTimeout++;
#endif
#endif
    // Set the clock security system
    CLEAR_BIT(RCC_Regs->CR, 19);
    RCC_Regs->CR |= (SET_CLOCK_SECURITY_SYSTEM << 19);
    // set the system clock source
    CLEAR_BIT(RCC_Regs->CFGR, 0);
    CLEAR_BIT(RCC_Regs->CFGR, 1);
    RCC_Regs->CFGR |= (0x3 & SET_SYSTEM_CLOCK_SOURCE);
    /********** set system prescalers ************/
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
    // set the mcu clock output source
    RCC_Regs->CFGR &= ~(7 << 24);
    RCC_Regs->CFGR |= (SET_MCU_CLK_OUTPUT_SRC << 24);
}

ErrorStates_t RCC_enuEnablePeripheralClock(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID)
{
    if (Copy_u8BusID == _AHB_ID_)
    {
        // enable the clock in the AHB bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if (Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->AHBENR |= (BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->AHBENR = AHBENR_ALL_VALUE;
    }
    else if (Copy_u8BusID == _APB1_ID_)
    {
        // enable the clock in the APB1 bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if (Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->APB1ENR |= (BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->APB1ENR = APB1ENR_ALL_VALUE;
    }
    else if (Copy_u8BusID == _APB2_ID_)
    {
        // enable the clock in the APB2 bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if (Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->APB2ENR |= (BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->APB2ENR = APB2ENR_ALL_VALUE;
    }
    else
    {
        return ES_OUT_OF_RANGE;
    }

    return ES_OK;
}

ErrorStates_t RCC_enuDisablePeripheralClock(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID)
{
    if (Copy_u8BusID == _AHB_ID_)
    {
        // disable the clock in the AHB bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if (Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->AHBENR &= ~(BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->AHBENR = AHBENR_RESET_VALUE;
    }
    else if (Copy_u8BusID == _APB1_ID_)
    {
        // disable the clock in the APB1 bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if (Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->APB1ENR &= ~(BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->APB1ENR = APB1ENR_RESET_VALUE;
    }
    else if (Copy_u8BusID == _APB2_ID_)
    {
        // disable the clock in the APB2 bus for peripheral {Copy_u8PeripheralID}
        // clear the bit on the clock enable register
        if (Copy_u8PeripheralID != _ALL_PERIPHERALS_)
            RCC_Regs->APB2ENR &= ~(BIT_MASK << Copy_u8PeripheralID);
        else
            RCC_Regs->APB2ENR = APB2ENR_RESET_VALUE;
    }
    else
    {
        return ES_OUT_OF_RANGE;
    }

    return ES_OK;
}

ErrorStates_t RCC_enuResetPeripheral(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID)
{
    if (Copy_u8BusID == _APB1_ID_)
    {
        // reset the peripheral {Copy_u8PeripheralID} in the APB1 bus
        // set the corresponding bit to the peripheral in the APB1RSTR
        if (Copy_u8PeripheralID != _ALL_PERIPHERALS_)
        {
            RCC_Regs->APB1RSTR |= (BIT_MASK << Copy_u8PeripheralID);
            RCC_Regs->APB1RSTR &= ~(BIT_MASK << Copy_u8PeripheralID);
        }
        else
        {
            RCC_Regs->APB1RSTR = APB1ENR_ALL_VALUE;
            RCC_Regs->APB1RSTR = 0x00000000;
        }
    }
    else if (Copy_u8BusID == _APB2_ID_)
    {
        // reset the peripheral {Copy_u8PeripheralID} in the APB2 bus
        // set the corresponding bit to the peripheral in the APB2RSTR
        if (Copy_u8PeripheralID != _ALL_PERIPHERALS_)
        {
            RCC_Regs->APB2RSTR |= (BIT_MASK << Copy_u8PeripheralID);
            RCC_Regs->APB2RSTR &= ~(BIT_MASK << Copy_u8PeripheralID);
        }
        else
        {
            RCC_Regs->APB2RSTR = APB2ENR_ALL_VALUE;
            RCC_Regs->APB2RSTR = 0x00000000;
        }
    }
    else
    {
        return ES_OUT_OF_RANGE;
    }

    return ES_OK;
}

ErrorStates_t RCC_enuGetSysClk(uint32_t *Copy_pu32SysClk)
{
    if (Copy_pu32SysClk != NULL)
    {
        // check the clock source by reading the sws bits
        uint8_t clkSrc = (SET_SYSTEM_CLOCK_SOURCE) & 0b11;
        uint8_t multFactor, pllSrc;
        switch (clkSrc)
        {
            case RCC_PLL:
                // getting the multiplication factor of pll
                multFactor = ((RCC_Regs->CFGR >> 18) & 0b1111) + 2;
                // getting the pll source
                pllSrc = (RCC_Regs->CFGR >> 16) & 0b11;
                switch (pllSrc)
                {
                case PLL_HSE:
                    *Copy_pu32SysClk = HSE_CLOCK_VALUE * multFactor;
                    break;
                case PLL_HSE_DIV2:
                    *Copy_pu32SysClk = (HSE_CLOCK_VALUE / 2) * multFactor;
                    break;
                case PLL_HSI_DIV2:
                    *Copy_pu32SysClk = (HSI_CLK_VAL / 2) * multFactor;
                    break;
                default:
                    *Copy_pu32SysClk = 0;
                    return ES_OUT_OF_RANGE;
                }
                break;
            case RCC_HSE:
                *Copy_pu32SysClk = HSE_CLOCK_VALUE;
                break;
            case RCC_HSI:
                *Copy_pu32SysClk = HSI_CLK_VAL;
                break;
            default:
                *Copy_pu32SysClk = 0;
                return ES_OUT_OF_RANGE;
        }
        return ES_OK;
    }
    else
    {
        return ES_NULL_POINTER;
    }
}

ErrorStates_t RCC_enuGetHLCK(uint32_t *Copy_pu32HLCK)
{
    if (Copy_pu32HLCK != NULL)
    {
        // get the hclk prescaller value
        uint8_t hpreVal = (RCC_Regs->CFGR >> 4) & 0b1111;
        // get the system clk
        ErrorStates_t local_error = RCC_enuGetSysClk(Copy_pu32HLCK);
        if (local_error == ES_OK)
        {
            *Copy_pu32HLCK = *Copy_pu32HLCK >> RCC_Au8HCLKPrescaller[hpreVal];
            return ES_OK;
        }
        else
        {
            *Copy_pu32HLCK = 0;
            return local_error;
        }
    }
    else
    {
        return ES_NULL_POINTER;
    }
}

ErrorStates_t RCC_enuGetPLCK1(uint32_t *Copy_pu32PLCK1)
{
    if (Copy_pu32PLCK1 != NULL)
    {
        // get the plck1 prescaller value;
        uint8_t ppre1Val = (RCC_Regs->CFGR >> 8) & 0b111;
        // get the ahb clk value
        ErrorStates_t local_error = RCC_enuGetHLCK(Copy_pu32PLCK1);
        if (local_error == ES_OK)
        {
            *Copy_pu32PLCK1 = *Copy_pu32PLCK1 >> RCC_Au8PCLKxPrescaller[ppre1Val];
            return ES_OK;
        }
        else
        {
            *Copy_pu32PLCK1 = 0;
            return local_error;
        }
    }
    else
    {
        return ES_NULL_POINTER;
    }
}

ErrorStates_t RCC_enuGetPLCK2(uint32_t *Copy_pu32PLCK2)
{
    if (Copy_pu32PLCK2 != NULL)
    {
        // get the plck1 prescaller value;
        uint8_t ppre2Val = (RCC_Regs->CFGR >> 11) & 0b111;
        // get the ahb clk value
        ErrorStates_t local_error = RCC_enuGetHLCK(Copy_pu32PLCK2);
        if (local_error == ES_OK)
        {
            *Copy_pu32PLCK2 = *Copy_pu32PLCK2 >> RCC_Au8PCLKxPrescaller[ppre2Val];
            return ES_OK;
        }
        else
        {
            *Copy_pu32PLCK2 = 0;
            return local_error;
        }
    }
    else
    {
        return ES_NULL_POINTER;
    }
}
