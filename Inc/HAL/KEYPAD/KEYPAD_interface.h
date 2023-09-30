/*
 * KEYPAD_interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"

ErrorStates_t KPAD_enuInit(void);

ErrorStates_t KPAD_enuGetPressedkey(uint8_t Copy_u8KpadID, uint8_t* Copy_pu8Value);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
