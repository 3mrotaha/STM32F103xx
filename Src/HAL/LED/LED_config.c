/*
 * LED_config.c
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../../../Inc/HAL/LED/LED_config.h"
#include "../../../Inc/HAL/LED/LED_interface.h"

LED_t SW_AstrLEDs[LED_NUM] = {
		{GPIO_PORTA, GPIO_PIN_1, LED_SINK, GPIO_OUTPUT_LOW},
		{GPIO_PORTA, GPIO_PIN_2, LED_SOURCE, GPIO_OUTPUT_LOW},
		{GPIO_PORTA, GPIO_PIN_3, LED_SOURCE, GPIO_OUTPUT_LOW},
		{GPIO_PORTA, GPIO_PIN_4, LED_SINK, GPIO_OUTPUT_LOW},
		{GPIO_PORTA, GPIO_PIN_5, LED_SINK, GPIO_OUTPUT_LOW}
};

