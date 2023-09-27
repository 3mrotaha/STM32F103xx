/**
 * @file AFIO_interface.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the APIs used
 *        by the user in the application
 * @version 1
 * @date 2023-09-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _AFIO_INTERFACE_H_
#define _AFIO_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/STM32F103xx.h"
#include "../../LIB/Error_States.h"

/**
 * @name AFIO_enuEXTILineMap
 * @brief this function is used to remap the external interrupt
 *        pins to the GPIO pins
 * @param Copy_u8Line (uint8_t)
 * @param Copy_u8MappedRegister (uint8_t) 
 * @return - ES_OK (ErrorStates_t):
 *           if the interrupt line was mapped successfully
 * @return - ES_NOK (ErrorStates_t):
 *           if something went wrong
 * @return - ES_OUT_OF_RANGE (ErrorStates_t)
 *           if the interrupt line or the mapped register values
 *           are out of range.
 */
ErrorStates_t AFIO_enuEXTILineMap(uint8_t Copy_u8Line, uint8_t Copy_u8MappedRegister);

#endif // _AFIO_INTERFACE_H_