/*
 * SW_config.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_SWITCH_SW_CONFIG_H_
#define HAL_SWITCH_SW_CONFIG_H_
#include "../../LIB/std_types.h"

#define SW_NUM	4

typedef struct{
	uint8_t SW_u8PortID;
	uint8_t SW_u8PinID;
	uint8_t SW_u8State;
}SW_t;

#endif /* HAL_SWITCH_SW_CONFIG_H_ */
