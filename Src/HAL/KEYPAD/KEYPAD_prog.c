/**
 * @file KEYPAD_prog.c
 * @brief This file contains the implementation of the functions for interfacing with a keypad.
 * 
 * This file contains the implementation of the initialization function and the function to get the pressed key from a keypad.
 * The initialization function sets the rows as input and pull-up and the columns as output and push-pull with a high value.
 * The function to get the pressed key loops through all the columns and rows of the keypad and returns the corresponding key value.
 * 
 * @note This file depends on the GPIO module for setting and getting pin values and configurations.
 * @note This file depends on the KEYPAD_config.h file for the keypad configuration.
 * @note This file depends on the std_types.h, Error_States.h, and Math.h files for the data types and error states.
 * 
 * @author Amr M. Taha
 * @date 30-9-2023
 * @version v3.0
 */

#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/HAL/KEYPAD/KEYPAD_private.h"
#include "../../../Inc/HAL/KEYPAD/KEYPAD_config.h"

static uint8_t KPAD_Auint8PadKeys[NUM_OF_ROWS][NUM_OF_COLUMNS] = PAD_KEY_VALUES;
extern KPAD_t* KPAD_AstrKeyPadConfig;
ErrorStates_t KPAD_enuInit(KPAD_t* Copy_pstrKeyPadConfig){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_pstrKeyPadConfig != NULL){
		uint8_t Local_uint8Iterator1;
		uint8_t Local_uint8Iterator2;
		for(Local_uint8Iterator1 = 0; Local_uint8Iterator1 < NUM_OF_KPADS; Local_uint8Iterator1++){
			KPAD_t Local_strKeyPadConfig = Copy_pstrKeyPadConfig[Local_uint8Iterator1];
			for(Local_uint8Iterator2 = 0; Local_uint8Iterator2 < NUM_OF_ROWS; Local_uint8Iterator2++){
                // set rows as input and pull up
				Local_enuErrorStates = GPIO_enuSetPinConfiguration(Local_strKeyPadConfig.KPAD_strRows[Local_uint8Iterator2].R_u8Port, Local_strKeyPadConfig.KPAD_strRows[Local_uint8Iterator2].R_u8Pin, &(GPIO_PinConfig_t){
					.mode = GPIO_INPUT,
					.config = GPIO_INPUT_PULLUP_DOWN,
					.value = GPIO_INPUT_PULLUP
				});
			}

			for(Local_uint8Iterator2 = 0; Local_uint8Iterator2 < NUM_OF_ROWS; Local_uint8Iterator2++){
				// set cols as output and push pull, and set high
				Local_enuErrorStates = GPIO_enuSetPinConfiguration(Local_strKeyPadConfig.KPAD_strCols[Local_uint8Iterator2].C_u8Port, Local_strKeyPadConfig.KPAD_strCols[Local_uint8Iterator2].C_u8Pin, &(GPIO_PinConfig_t){
					.mode = GPIO_OUTPUT_2MHZ,
					.config = GPIO_OUTPUT_PUSHPULL,
					.value = GPIO_OUTPUT_HIGH
				});
			}
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ErrorStates_t KPAD_enuGetPressedkey(uint8_t Copy_u8KpadID, uint8_t* Copy_puint8Value){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	if(Copy_puint8Value != NULL){
		*Copy_puint8Value = 0;
		uint8_t Local_uint8RowsIterator, Local_uint8ColsIterator, Local_uint8GetKey;

		for(Local_uint8ColsIterator = 0; Local_uint8ColsIterator < NUM_OF_COLUMNS; Local_uint8ColsIterator++){
			Local_enuErrorStates = GPIO_enuSetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strCols[Local_uint8ColsIterator].C_u8Port, KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strCols[Local_uint8ColsIterator].C_u8Pin, GPIO_OUTPUT_LOW);
			for(Local_uint8RowsIterator = 0; Local_uint8RowsIterator < NUM_OF_ROWS; Local_uint8RowsIterator++){
				Local_enuErrorStates = GPIO_enuGetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strRows[Local_uint8RowsIterator].R_u8Port, KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strRows[Local_uint8RowsIterator].R_u8Pin, &Local_uint8GetKey);
				if(!Local_uint8GetKey){
					Local_enuErrorStates = GPIO_enuGetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strRows[Local_uint8RowsIterator].R_u8Port, KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strRows[Local_uint8RowsIterator].R_u8Pin, &Local_uint8GetKey);
					while(!Local_uint8GetKey)
						Local_enuErrorStates = GPIO_enuGetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strRows[Local_uint8RowsIterator].R_u8Port, KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strRows[Local_uint8RowsIterator].R_u8Pin, &Local_uint8GetKey);
					*Copy_puint8Value = KPAD_Auint8PadKeys[Local_uint8RowsIterator][Local_uint8ColsIterator];
				}
			}
			Local_enuErrorStates = GPIO_enuSetPinValue(KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strCols[Local_uint8ColsIterator].C_u8Port, KPAD_AstrKeyPadConfig[Copy_u8KpadID].KPAD_strCols[Local_uint8ColsIterator].C_u8Pin, GPIO_OUTPUT_HIGH);
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}
