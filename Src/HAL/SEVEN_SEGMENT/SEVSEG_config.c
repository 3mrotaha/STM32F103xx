/*
 * SEVSEG_config.c
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#include "../../../Inc/LIB/std_types.h"

#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/HAL/SEVEN_SEGMENT/SEVSEG_config.h"
#include "../../../Inc/HAL/SEVEN_SEGMENT/SEVSEG_interface.h"

ST_SevSegment_t SEVSEG_astConfig[SEVEN_SEGMENTS_NUM] = {
    {
        SEV_SEG_COMMON_CATHODE,
        SEV_SEG_COM_CONNECTED,
        GPIO_PORTA, GPIO_PIN_8,        
        GPIO_PORTA, GPIO_PIN_0,
        GPIO_PORTA, GPIO_PIN_1,
        GPIO_PORTA, GPIO_PIN_2,
        GPIO_PORTA, GPIO_PIN_3,
        GPIO_PORTA, GPIO_PIN_4,
        GPIO_PORTA, GPIO_PIN_5,
        GPIO_PORTA, GPIO_PIN_6,
        SEV_SEG_ENABLE_DOT,
        GPIO_PORTA, GPIO_PIN_7,
    },
    {
        SEV_SEG_COMMON_CATHODE,
        SEV_SEG_COM_CONNECTED,
        GPIO_PORTA, GPIO_PIN_9,        
        GPIO_PORTA, GPIO_PIN_0,
        GPIO_PORTA, GPIO_PIN_1,
        GPIO_PORTA, GPIO_PIN_2,
        GPIO_PORTA, GPIO_PIN_3,
        GPIO_PORTA, GPIO_PIN_4,
        GPIO_PORTA, GPIO_PIN_5,
        GPIO_PORTA, GPIO_PIN_6,
        SEV_SEG_ENABLE_DOT,
        GPIO_PORTA, GPIO_PIN_7,
    }
};