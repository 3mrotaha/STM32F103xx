/*
 * USART_private.h
 *
 *  Created on: Oct 4, 2023
 *      Author: amrmo
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_
#include "../../LIB/STM32F103xx.h"
#include "../../LIB/std_types.h"

#define UART1_BASE (MCU_PERIPHERALS_BASE +  0x13800)
#define UART2_BASE (MCU_PERIPHERALS_BASE +  0x4400)
#define UART3_BASE (MCU_PERIPHERALS_BASE +  0x4800)

// UART Registers
typedef struct ST_UART_Regs{
    uint32_t SR;
    uint32_t DR;
    uint32_t BRR;
    uint32_t CR[3];
    uint32_t GTPR;
}ST_UART_Regs_t;

// UART instants
#define UART1_Regs  ((volatile ST_UART_Regs_t*) UART1_BASE)
#define UART2_Regs  ((volatile ST_UART_Regs_t*) UART2_BASE)
#define UART3_Regs  ((volatile ST_UART_Regs_t*) UART3_BASE)

#define _UART_TX_COMPLETE_INTERRUPT_   0
#define _UART_CTS_INTERRUPT_           1
#define _UART_TDR_EMPTY_INTERRUPT_     2
#define _UART_RX_READY_INTERRUPT_	   3
#define _UART_OVERRUN_ERROR_INTERRUPT_ 4
#define _UART_PARITY_ERROR_INTERRUPT_  5
#define _UART_FRAMING_ERROR_INTERRUPT_ 6
#define _UART_NOISE_ERROR_INTERRUPT_   7
#define _UART_IDLE_INTERRUPT_          8

// uart word length
#define _UART_WORD_LENGTH_8BIT_  0
#define _UART_WORD_LENGTH_9BIT_  1

// uart stop bits
#define _UART_STOP_BITS_0_5_	0
#define _UART_STOP_BITS_1_		1
#define _UART_STOP_BITS_1_5_	2
#define _UART_STOP_BITS_2_		3

// uart parity
#define _UART_PARITY_DISABLE_   0
#define _UART_PARITY_EVEN_      1
#define _UART_PARITY_ODD_       2

// uart flow control
#define _UART_FLOW_CONTROL_DISABLE_  0   
#define _UART_FLOW_CTS_ENABLE_       1
#define _UART_FLOW_RTS_ENABLE_       2
#define _UART_FLOW_CTS_RTS_ENABLE_   3  

// uart baudrate
#define _UART_B2400_    2400UL
#define _UART_B9600_    9600UL
#define _UART_B19200_   19200UL
#define _UART_B57600_   57600UL
#define _UART_B115200_  115200UL
#define _UART_B230400_  230400UL
#define _UART_B460800_  460800UL
#define _UART_B921600_  921600UL
#define _UART_B2_25M_   2250000UL
#define _UART_B4_5M_    4500000UL

#endif /* MCAL_USART_USART_PRIVATE_H_ */
