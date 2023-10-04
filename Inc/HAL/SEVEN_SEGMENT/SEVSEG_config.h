/*
 * SEVSEG_config.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_SEVEN_SEGMENT_SEVSEG_CONFIG_H_
#define HAL_SEVEN_SEGMENT_SEVSEG_CONFIG_H_
#include "../../LIB/std_types.h"

#define SEVEN_SEGMENTS_NUM  4

typedef struct{
    uint8_t SS_u8Com;
    
    uint8_t SS_u8ComConnected;
    uint8_t SS_u8ComPort;
    uint8_t SS_u8ComPin;
    
    uint8_t SSA_u8Port;
    uint8_t SSA_u8Pin;

    uint8_t SSB_u8Port;
    uint8_t SSB_u8Pin;

    uint8_t SSC_u8Port;
    uint8_t SSC_u8Pin;

    uint8_t SSD_u8Port;
    uint8_t SSD_u8Pin;

    uint8_t SSE_u8Port;
    uint8_t SSE_u8Pin;

    uint8_t SSF_u8Port;
    uint8_t SSF_u8Pin;

    uint8_t SSG_u8Port;
    uint8_t SSG_u8Pin;

    uint8_t SSDot_Enable;
    uint8_t SSDot_u8Port;
    uint8_t SSDot_u8Pin;
}ST_SevSegment_t;

#endif /* HAL_SEVEN_SEGMENT_SEVSEG_CONFIG_H_ */
