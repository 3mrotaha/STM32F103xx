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
#include "../AFIO/AFIO_private.h"

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

// polling enable type
typedef unsigned char PollingEn_t;
#define _UART_POLLING_ENABLE_    1
#define _UART_POLLING_DISABLE_   0

// UART IDs
#define _UART_1_    0
#define _UART_2_    1
#define _UART_3_    2

// UART CR1
#define _UART_TX_COMPLETE_INTERRUPT_    0UL
#define _UART_CTS_INTERRUPT_            1UL
#define _UART_TDR_EMPTY_INTERRUPT_      2UL
#define _UART_RX_READY_INTERRUPT_	    3UL
#define _UART_OVERRUN_ERROR_INTERRUPT_  4UL
#define _UART_PARITY_ERROR_INTERRUPT_   5UL
#define _UART_FRAMING_ERROR_INTERRUPT_  6UL
#define _UART_NOISE_ERROR_INTERRUPT_    7UL
#define _UART_IDLE_INTERRUPT_           8UL

// uart word length
#define _UART_WORD_LENGTH_8BIT_         0UL
#define _UART_WORD_LENGTH_9BIT_         1UL

// uart stop bits
#define _UART_STOP_BITS_1_		        0UL
#define _UART_STOP_BITS_0_5_	        1UL
#define _UART_STOP_BITS_2_		        2UL
#define _UART_STOP_BITS_1_5_	        3UL

// uart parity
#define _UART_PARITY_DISABLE_           0UL
#define _UART_PARITY_EVEN_              2UL
#define _UART_PARITY_ODD_               3UL

// uart flow control
#define _UART_FLOW_CONTROL_DISABLE_     0UL
#define _UART_FLOW_RTS_ENABLE_          1UL
#define _UART_FLOW_CTS_ENABLE_          2UL
#define _UART_FLOW_CTS_RTS_ENABLE_      3UL

// uart baudrate
#define _UART_B2400_                    2400UL
#define _UART_B9600_                    9600UL
#define _UART_B19200_                   19200UL
#define _UART_B57600_                   57600UL
#define _UART_B115200_                  115200UL
#define _UART_B230400_                  230400UL
#define _UART_B460800_                  460800UL
#define _UART_B921600_                  921600UL
#define _UART_B2_25M_                   2250000UL
#define _UART_B4_5M_                    4500000UL

#define _UART_INT_DISABLE_              0UL
#define _UART_INT_ENABLE_               1UL

#define _UART_SEND_RECEIVE_DISABLE_     0UL
#define _UART_RECEIVE_ENABLE_           1UL
#define _UART_SEND_ENABLE_              2UL
#define _UART_SEND_RECEIVE_ENABLE_      3UL

// uart remap
#define _UART_NO_MAPPING_        _N_REMAP_
#define _UART_PARTIAL_REMAP_     _P_REMAP_
#define _UART_FULL_REMAP_        _F_REMAP_

#define UART_DIV(_PLCx_, _BDR_)            ((uint32_t)(((_PLCx_) / (16 * _BDR_))))
#define UART_DIV_MUL100(_PLCx_, _BDR_)     ((uint32_t)(((_PLCx_ * 25) / (4 * _BDR_))))

#define UART_MANTISSA_MUL100(_PLCx_, _BDR_) ((UART_DIV(_PLCx_, _BDR_) * 100))
#define UART_FRACTION(_PLCx_, _BDR_)        ((uint32_t)((UART_DIV_MUL100(_PLCx_, _BDR_) - UART_MANTISSA_MUL100(_PLCx_, _BDR_)) * 16) / 100)
#define UART_BUAD_RATE(_PLCx_, _BDR_)       ((uint32_t)(((uint32_t)(UART_DIV(_PLCx_, _BDR_) << 4)) | UART_FRACTION(_PLCx_, _BDR_)))

#endif /* MCAL_USART_USART_PRIVATE_H_ */
