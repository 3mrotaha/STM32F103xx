/*
 * KEYPAD_config.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_
#include "../../LIB/std_types.h"

#define NUM_OF_KPADS	1

#define NUM_OF_COLUMNS	4
#define NUM_OF_ROWS		4


typedef struct{
	struct{
		uint8_t R_u8Port;
		uint8_t R_u8Pin;        
	}KPAD_strRows[NUM_OF_ROWS];

	struct{
			uint8_t C_u8Port;
			uint8_t C_u8Pin;
		}KPAD_strCols[NUM_OF_COLUMNS];
}KPAD_t;

#define PAD_KEY_VALUES	{\
		{ '7', '8', '9', '+'},\
		{ '4', '5', '6', '-'},\
		{ '1', '2', '3', 'x'},\
		{ 'c', '0', '=', '/'}\
	}

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
