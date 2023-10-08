/*
 * USART_interface.h
 *
 *  Created on: Oct 4, 2023
 *      Author: amrmo
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"

/**
 * @ref UART_IDs
 * @brief - IDs of the UART peripherals
 */
#define UART_1 _UART_1_
#define UART_2 _UART_2_
#define UART_3 _UART_3_

/**
 * @ref UART_Interrupt_Types
 * @brief - Types of UART interrupts to set the callback function for
 *       each type of interrupt is defined by a bit in the UART peripheral's
 *      interrupt enable register.
 */
#define UART_TX_COMPLETE_INTERRUPT      _UART_TX_COMPLETE_INTERRUPT_
#define UART_CTS_INTERRUPT              _UART_CTS_INTERRUPT_
#define UART_TDR_EMPTY_INTERRUPT        _UART_TDR_EMPTY_INTERRUPT_
#define UART_RX_READY_INTERRUPT         _UART_RX_READY_INTERRUPT_
#define UART_OVERRUN_ERROR_INTERRUPT    _UART_OVERRUN_ERROR_INTERRUPT_
#define UART_PARITY_ERROR_INTERRUPT     _UART_PARITY_ERROR_INTERRUPT_
#define UART_FRAMING_ERROR_INTERRUPT    _UART_FRAMING_ERROR_INTERRUPT_
#define UART_NOISE_ERROR_INTERRUPT      _UART_NOISE_ERROR_INTERRUPT_
#define UART_IDLE_LINE_INTERRUPT        _UART_IDLE_INTERRUPT_

/**
 * @ref UART_WORD_LENGTH 
 * @brief use it to configure the UART word length
 */
#define UART_WORD_LENGTH_8_BIT _UART_WORD_LENGTH_8BIT_
#define UART_WORD_LENGTH_9_BIT _UART_WORD_LENGTH_9BIT_

/**
 * @ref UART_STOP_BITS
 * @brief use it to configure the UART stop bits
 */
#define UART_STOP_BITS_1    _UART_STOP_BITS_1_
#define UART_STOP_BITS_2    _UART_STOP_BITS_2_
#define UART_STOP_BITS_0_5  _UART_STOP_BITS_0_5_
#define UART_STOP_BITS_1_5  _UART_STOP_BITS_1_5_

/**
 * @ref UART_PARITY
 * @brief use it to configure the UART parity
 */
#define UART_PARITY_DISABLE _UART_PARITY_DISABLE_
#define UART_PARITY_EVEN    _UART_PARITY_EVEN_
#define UART_PARITY_ODD     _UART_PARITY_ODD_

/**
 * @ref UART_FLOW_CONTROL
 * @brief use it to configure the UART flow control
 */
#define UART_FLOW_CONTROL_DISABLE _UART_FLOW_CONTROL_DISABLE_
#define UART_FLOW_CTS_ENABLE      _UART_FLOW_CTS_ENABLE_
#define UART_FLOW_RTS_ENABLE      _UART_FLOW_RTS_ENABLE_
#define UART_FLOW_CTS_RTS_ENABLE  _UART_FLOW_CTS_RTS_ENABLE_

/**
 * @ref UART_BAUDRATE
 * @brief use it to configure the UART baudrate
 */
#define UART_BAUDRATE_2400   _UART_B2400_
#define UART_BAUDRATE_9600   _UART_B9600_
#define UART_BAUDRATE_19200  _UART_B19200_
#define UART_BAUDRATE_57600  _UART_B57600_
#define UART_BAUDRATE_115200 _UART_B115200_
#define UART_BAUDRATE_230400 _UART_B230400_
#define UART_BAUDRATE_460800 _UART_B460800_
#define UART_BAUDRATE_921600 _UART_B921600_
#define UART_BAUDRATE_2_25M  _UART_B2_25M_
#define UART_BAUDRATE_4_5M   _UART_B4_5M_



/*****************************************************************************
 * @name UART_enuInit
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to be initialized
 *       possible values are @ref UART_IDs
 * @return - ES_OK (ErrorStates_t):
 *           if the UART peripheral is initialized successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the UART peripheral is not initialized successfully
 * @brief - This function initializes the UART peripheral
 * @pre none
 * @post none
 *******************************************************************************/
ErrorStates_t UART_enuInit(uint8_t Copy_u8UartId);

/*****************************************************************************
 * @name UART_enuDeInit
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to be de-initialized
 *       possible values are @ref UART_IDs
 * @return - ES_OK (ErrorStates_t):
 *           if the UART peripheral is de-initialized successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the UART peripheral is not de-initialized successfully
 * @brief - This function de-initializes the UART peripheral
 * @pre none
 * @post none
 *****************************************************************************/
ErrorStates_t UART_enuDeInit(uint8_t Copy_u8UartId);


/*****************************************************************************
 * @name UART_enuTransmitByte
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to transmit data through
 *       possible values are @ref UART_IDs
 * @param Copy_u8Data (uint8_t)
 *       - Byte of data to be transmitted through the UART peripheral
 * @return - ES_OK (ErrorStates_t):
 *           if the byte of data is transmitted successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the byte of data is not transmitted successfully
 * @brief - This function transmits a single byte of data through the UART peripheral
 * @pre none
 * @post none
 *****************************************************************************/
ErrorStates_t UART_enuTransmitByte(uint8_t Copy_u8UartId, uint8_t Copy_u8Data);


/*****************************************************************************
 * @name UART_enuReceiveByte
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to receive data through
 *       possible values are @ref UART_IDs
 * @param Copy_pu8Data (uint8_t*)
 *       - Pointer to a variable to store the received byte of data
 * @return - ES_OK (ErrorStates_t):
 *           if the byte of data is received successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the byte of data is not received successfully
 * @brief - This function receives a single byte of data through the UART peripheral
 * @pre none
 * @post none
 *****************************************************************************/
ErrorStates_t UART_enuReceiveByte(uint8_t Copy_u8UartId, uint8_t *Copy_pu8Data);


/*****************************************************************************
 * @name UART_enuTransmitString
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to transmit data through
 *       possible values are @ref UART_IDs
 * @param Copy_pu8Data (uint8_t*)
 *       - Pointer to the string of data to be transmitted through the UART peripheral
 * @return - ES_OK (ErrorStates_t):
 *           if the string of data is transmitted successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the string of data is not transmitted successfully
 * @brief - This function transmits a string of data through the UART peripheral
 * @pre none
 * @post none
 *****************************************************************************/
ErrorStates_t UART_enuTransmitString(uint8_t Copy_u8UartId, uint8_t *Copy_pu8Data);


/*****************************************************************************
 * @name UART_enuReceiveString
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to receive data through
 *       possible values are @ref UART_IDs
 * @param Copy_pu8Data (uint8_t*)
 *       - Pointer to a buffer to store the received string of data
 * @return - ES_OK (ErrorStates_t):
 *           if the string of data is received successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the string of data is not received successfully
 * @brief - This function receives a string of data through the UART peripheral
 * @pre none
 * @post none
 *****************************************************************************/
ErrorStates_t UART_enuReceiveString(uint8_t Copy_u8UartId, uint8_t *Copy_pu8Data);

/*****************************************************************************
 * @name UART_enuEnableInterrupt
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to enable the interrupt for
 *       possible values are @ref UART_IDs
 * @param Copy_u8InterruptType (uint8_t)
 *       - Type of UART interrupt to enable
 *       possible values are @ref UART_Interrupt_Types
 * @return - ES_OK (ErrorStates_t):
 *           if the UART interrupt is enabled successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID or interrupt type is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the UART interrupt is not enabled successfully
 * @brief - This function enables a UART interrupt
 * @pre none
 * @post none
 *****************************************************************************/
ErrorStates_t UART_enuEnableInterrupt(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType);

/*****************************************************************************
 * @name UART_enuDisableInterrupt
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to disable the interrupt for
 *       possible values are @ref UART_IDs
 * @param Copy_u8InterruptType (uint8_t)
 *       - Type of UART interrupt to disable
 *       possible values are @ref UART_Interrupt_Types
 * @return - ES_OK (ErrorStates_t):
 *           if the UART interrupt is disabled successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID or interrupt type is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the UART interrupt is not disabled successfully
 * @brief - This function disables a UART interrupt
 * @pre none
 * @post none
 *****************************************************************************/
ErrorStates_t UART_enuDisableInterrupt(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType);

/*****************************************************************************
 * @name UART_enuSetCallBack
 * @param Copy_u8UartId (uint8_t)
 *       - ID of the UART peripheral to set the callback function for
 *       possible values are @ref UART_IDs
 * @param Copy_u8InterruptType (uint8_t)
 *       - Type of UART interrupt to set the callback function for
 *       possible values are @ref UART_Interrupt_Types
 * @param Copy_fpvCallBack (void (*)(void))
 *       - Pointer to the callback function to be called when the UART interrupt occurs
 * @param Copy_pvParameter (void*)
 *       - Pointer to a parameter to be passed to the callback function when it is called
 * @return - ES_OK (ErrorStates_t):
 *           if the callback function is set successfully
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the UART peripheral ID or interrupt type is out of range
 * @return - ES_NOK (ErrorStates_t):
 *           if the callback function is not set successfully
 * @brief - This function sets a callback function to be called when a UART interrupt occurs
 * @pre none
 * @post none
 *****************************************************************************/
ErrorStates_t UART_enuSetCallBack(uint8_t Copy_u8UartId, uint8_t Copy_u8InterruptType, void (*Copy_fpvCallBack)(void), void* Copy_pvParameter);

#endif /* MCAL_USART_USART_INTERFACE_H_ */
