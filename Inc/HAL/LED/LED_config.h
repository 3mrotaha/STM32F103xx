/*
 * LED_config.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_


#define LED_NUM	5

typedef struct{
	uint8_t LED_u8PortID;
	uint8_t LED_u8PinID;
	uint8_t LED_u8Connection;
	uint8_t LED_u8State;
}LED_t;


#endif /* HAL_LED_LED_CONFIG_H_ */
