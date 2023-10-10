/**
 * @file AFIO_prog.c
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the implementation
 *        of the AFIO APIs
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/STM32F103xx.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/EXTI/EXTI_private.h"

#include "../../../Inc/MCAL/GPIO/GPIO_private.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/MCAL/AFIO/AFIO_private.h"
#include "../../../Inc/MCAL/AFIO/AFIO_interface.h"

#include "../../../Inc/MCAL/RCC/RCC_interface.h"

#include "../../../Inc/MCAL/UART/UART_interface.h"

ErrorStates_t AFIO_enuEXTILineMap(uint8_t Copy_u8Line, uint8_t Copy_u8MappedRegister){
    if((Copy_u8Line >= _EXTI0_ && Copy_u8Line <= _EXTI15_) && (Copy_u8MappedRegister >= _GPIO_PORTA_ && Copy_u8MappedRegister <= _GPIO_PORTE_)){
        uint8_t bitOffset = (Copy_u8Line % 4) * 4; // get the bit offset.
        AFIO_Regs->EXTICR[Copy_u8Line / 4] &= ~((uint32_t)0xf << bitOffset); // clear the bits
        AFIO_Regs->EXTICR[Copy_u8Line / 4] |= (Copy_u8MappedRegister << bitOffset); // set the port bits
        return ES_OK; /* everything is ok */
    }else{
        return ES_OUT_OF_RANGE; /* parameter out of range */
    }
}

ErrorStates_t AFIO_enuUartMap(uint8_t Copy_u8UartId, uint8_t Copy_u8RemapValue){
    if(Copy_u8UartId <= UART_1 && Copy_u8UartId >= UART_3){
        GPIO_PinConfig_t UartRx = {
            .mode = GPIO_INPUT,
            .config = GPIO_INPUT_PULLUP_DOWN,
            .value = GPIO_INPUT_PULLUP
        }, UartTx = {
            .mode = GPIO_OUTPUT_10MHZ,
            .config = GPIO_ALT_OUTPUT_PUSHPULL,
            .value = GPIO_OUTPUT_HIGH
        };
        switch (Copy_u8UartId)
        {
        case UART_1:
            if(Copy_u8RemapValue == NO_REMAPING){
                AFIO_Regs->MAPR1 &= ~(BIT_MASK << 2); // clear the bits
                RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTA_ID); // enable the AFIO clock
                GPIO_enuSetPinConfiguration(GPIO_PORTA, GPIO_PIN_9, &UartTx);
                GPIO_enuSetPinConfiguration(GPIO_PORTA, GPIO_PIN_10, &UartRx);
            }            
            else{
                RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTB_ID); // enable the AFIO clock
                AFIO_Regs->MAPR1 |= ((Copy_u8RemapValue & BIT_MASK) << 2); // set the port bits      
                GPIO_enuSetPinConfiguration(GPIO_PORTB, GPIO_PIN_6, &UartTx);
                GPIO_enuSetPinConfiguration(GPIO_PORTB, GPIO_PIN_7, &UartRx);      
            }
        break;
        case UART_2:
            if(Copy_u8RemapValue == NO_REMAPING){
                AFIO_Regs->MAPR1 &= ~(BIT_MASK << 3); // clear the bits
                RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTA_ID); // enable the AFIO clock
                GPIO_enuSetPinConfiguration(GPIO_PORTA, GPIO_PIN_2, &UartTx);
                GPIO_enuSetPinConfiguration(GPIO_PORTA, GPIO_PIN_3, &UartRx);
            }
            else{
                AFIO_Regs->MAPR1 |= ((Copy_u8RemapValue & BIT_MASK) << 3); // set the port bits
                RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTD_ID); // enable the AFIO clock
                GPIO_enuSetPinConfiguration(GPIO_PORTD, GPIO_PIN_5, &UartTx);
                GPIO_enuSetPinConfiguration(GPIO_PORTD, GPIO_PIN_6, &UartRx);
            }
        break;
        case UART_3:
            AFIO_Regs->MAPR1 &= ~((uint32_t)0x3 << 4); // clear the bits
            AFIO_Regs->MAPR1 |= (Copy_u8RemapValue << 4); // set the port bits
            if(Copy_u8RemapValue == NO_REMAPING){
                RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTB_ID); // enable the AFIO clock
                GPIO_enuSetPinConfiguration(GPIO_PORTB, GPIO_PIN_10, &UartTx);
                GPIO_enuSetPinConfiguration(GPIO_PORTB, GPIO_PIN_11, &UartRx);
            }else if(Copy_u8RemapValue == PARTIAL_REMAPING){
                RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTC_ID); // enable the AFIO clock
                GPIO_enuSetPinConfiguration(GPIO_PORTC, GPIO_PIN_10, &UartTx);
                GPIO_enuSetPinConfiguration(GPIO_PORTC, GPIO_PIN_11, &UartRx);
            }else if(Copy_u8RemapValue == FULL_REMAPING){
                RCC_enuEnablePeripheralClock(APB_2_ID, IO_PORTD_ID); // enable the AFIO clock
                GPIO_enuSetPinConfiguration(GPIO_PORTD, GPIO_PIN_8, &UartTx);
                GPIO_enuSetPinConfiguration(GPIO_PORTD, GPIO_PIN_9, &UartRx);
            }
        break;
        default:
            return ES_NOK; /* something went wrong */
        }
        return ES_OK; /* everything is ok */
    }else{
        return ES_OUT_OF_RANGE; /* parameter out of range */
    }
}
