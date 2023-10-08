/*
 * USART_config.h
 *
 *  Created on: Oct 4, 2023
 *      Author: amrmo
 */

#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_
#include "UART_interface.h"

/**
 * @ref UART_WORD_LENGTH_CONFIG
 * @brief Select the word length of the UART,
 *        possible values: @ref UART_WORD_LENGTH 
 */
#define SET_UART1_WORD_LENGTH   UART_WORD_LENGTH_8_BITS
#define SET_UART2_WORD_LENGTH   UART_WORD_LENGTH_8_BITS
#define SET_UART3_WORD_LENGTH   UART_WORD_LENGTH_8_BITS

/**
 * @ref UART_STOP_BITS_CONFIG
 * @brief Select the number of stop bits of the UART,
 *        possible values: @ref UART_STOP_BITS 
 */
#define SET_UART1_STOP_BITS     UART_STOP_BITS_1
#define SET_UART2_STOP_BITS     UART_STOP_BITS_1
#define SET_UART3_STOP_BITS     UART_STOP_BITS_1

/**
 * @ref UART_PARITY_CONFIG
 * @brief Select the parity of the UART,
 *        possible values: @ref UART_PARITY
 */
#define SET_UART1_PARITY        UART_PARITY_DISABLE
#define SET_UART2_PARITY        UART_PARITY_DISABLE
#define SET_UART3_PARITY        UART_PARITY_DISABLE

/**
 * @ref UART_FLOW_CONTROL_CONFIG
 * @brief Select the flow control of the UART,
 *       possible values: @ref UART_FLOW_CONTROL
 */
#define SET_UART1_FLOW_CONTROL  UART_FLOW_CONTROL_DISABLE
#define SET_UART2_FLOW_CONTROL  UART_FLOW_CONTROL_DISABLE
#define SET_UART3_FLOW_CONTROL  UART_FLOW_CONTROL_DISABLE

/**
 * @ref UART_BAUDRATE_CONFIG
 * @brief Select the baudrate of the UART,
 *       possible values: @ref UART_BAUDRATE
 */
#define SET_UART1_BAUDRATE      UART_BAUDRATE_9600
#define SET_UART2_BAUDRATE      UART_BAUDRATE_9600
#define SET_UART3_BAUDRATE      UART_BAUDRATE_9600

#endif /* MCAL_USART_USART_CONFIG_H_ */
