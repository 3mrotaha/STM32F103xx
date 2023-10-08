/*
 * USART_prog.c
 *
 *  Created on: Oct 4, 2023
 *      Author: amrmo
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Math.h"
#include "../../../Inc/LIB/Error_States.h"

#include "../../../Inc/MCAL/RCC/RCC_interface.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../../../Inc/MCAL/AFIO/AFIO_interface.h"

#include "../../../Inc/MCAL/UART/UART_config.h"

ErrorStates_t UART_enuInit(uint8_t Copy_u8UartId);

ErrorStates_t UART_enuDeInit(uint8_t Copy_u8UartId);

ErrorStates_t UART_enuTransmitByte(uint8_t Copy_u8UartId, uint8_t Copy_u8Data);

ErrorStates_t UART_enuReceiveByte(uint8_t Copy_u8UartId, uint8_t *Copy_pu8Data);

ErrorStates_t UART_enuTransmitString(uint8_t Copy_u8UartId, uint8_t *Copy_pu8Data);

ErrorStates_t UART_enuReceiveString(uint8_t Copy_u8UartId, uint8_t *Copy_pu8Data);

ErrorStates_t UART_enuEnableInterrupt(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType);

ErrorStates_t UART_enuDisableInterrupt(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType);

ErrorStates_t UART_enuSetCallBack(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType, void (*Copy_fpvCallBack)(void), void* Copy_pvParameter);