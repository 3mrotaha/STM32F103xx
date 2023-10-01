/*
 * SW_config.c
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"

#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/HAL/SWITCH/SW_config.h"

SW_t SW_AstrSwitches[SW_NUM] = {
		{GPIO_PORTA, GPIO_PIN_0, GPIO_INPUT_PULLUP},
		{GPIO_PORTB, GPIO_PIN_3, GPIO_INPUT_PULLUP},
		{GPIO_PORTC, GPIO_PIN_4, GPIO_INPUT_PULLUP},
		{GPIO_PORTD, GPIO_PIN_5, GPIO_INPUT_PULLUP}
};
