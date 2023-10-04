/*
 * LCD_config.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#include "../../MCAL/GPIO/GPIO_interface.h"

#define LCD_BIT_MODE	FOUR_BIT_MODE

#define RS_PORT			GPIO_PORTB
#define RS_PIN			GPIO_PIN_0

#define RW_PORT       	GPIO_PORTB
#define RW_PIN         	GPIO_PIN_1

#define EN_PORT        	GPIO_PORTB
#define EN_PIN         	GPIO_PIN_2

#define D7_PORT       	GPIO_PORTB
#define D7_PIN         	GPIO_PIN_3

#define D6_PORT        	GPIO_PORTB
#define D6_PIN         	GPIO_PIN_4

#define D5_PORT        	GPIO_PORTB
#define D5_PIN         	GPIO_PIN_5

#define D4_PORT       	GPIO_PORTB
#define D4_PIN        	GPIO_PIN_6

#define D3_PORT         GPIO_PORTB
#define D3_PIN          GPIO_PIN_7

#define D2_PORT         GPIO_PORTB
#define D2_PIN          GPIO_PIN_8

#define D1_PORT         GPIO_PORTB
#define D1_PIN          GPIO_PIN_9

#define D0_PORT       	GPIO_PORTB
#define D0_PIN        	GPIO_PIN_10

#define FRACTION_MAX_RANGE	4

#endif /* HAL_LCD_LCD_CONFIG_H_ */
