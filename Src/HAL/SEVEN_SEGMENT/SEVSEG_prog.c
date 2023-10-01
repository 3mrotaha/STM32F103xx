/*
 * SEVSEG_prog.c
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */


#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/HAL/SEVEN_SEGMENT/SEVSEG_private.h"
#include "../../../Inc/HAL/SEVEN_SEGMENT/SEVSEG_config.h"

static uint8_t SEVSEG_au8Values[] = SEVEN_SEGMENT_VALUES;
extern ST_SevSegment_t SEVSEG_astConfig[SEVEN_SEGMENTS_NUM];

ErrorStates_t SEVSEG_enuInit(void){
    if(SEVEN_SEGMENTS_NUM > 0){
        ErrorStates_t local_enuError = ES_NOK;
        GPIO_PinConfig_t local_stGpioConfig = {
            .mode = GPIO_OUTPUT_2MHZ,
            .config = GPIO_OUTPUT_PUSHPULL,
            .value = GPIO_OUTPUT_LOW
        };
        for(uint8_t Iterator = 0; Iterator < SEVEN_SEGMENTS_NUM; Iterator++){
            if(SEVSEG_astConfig[Iterator].SS_u8Com == _COM_CATHODE_){
                local_stGpioConfig.value = GPIO_OUTPUT_LOW;
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSA_u8Port, SEVSEG_astConfig[Iterator].SSA_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSB_u8Port, SEVSEG_astConfig[Iterator].SSB_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSC_u8Port, SEVSEG_astConfig[Iterator].SSC_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSD_u8Port, SEVSEG_astConfig[Iterator].SSD_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSE_u8Port, SEVSEG_astConfig[Iterator].SSE_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSF_u8Port, SEVSEG_astConfig[Iterator].SSF_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSG_u8Port, SEVSEG_astConfig[Iterator].SSG_u8Pin, &local_stGpioConfig);                
                if(SEVSEG_astConfig[Iterator].SSDot_Enable == _DOT_ENABLED_){
                    local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSDot_u8Port, SEVSEG_astConfig[Iterator].SSDot_u8Pin, &local_stGpioConfig);
                }
                if(SEVSEG_astConfig[Iterator].SS_u8ComConnected == _COM_CONNECTED_){
                    local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SS_u8ComPort, SEVSEG_astConfig[Iterator].SS_u8ComPin, &local_stGpioConfig);
                }
            }else if(SEVSEG_astConfig[Iterator].SS_u8Com == _COM_ANODE_){
                local_stGpioConfig.value = GPIO_OUTPUT_HIGH;
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSA_u8Port, SEVSEG_astConfig[Iterator].SSA_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSB_u8Port, SEVSEG_astConfig[Iterator].SSB_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSC_u8Port, SEVSEG_astConfig[Iterator].SSC_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSD_u8Port, SEVSEG_astConfig[Iterator].SSD_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSE_u8Port, SEVSEG_astConfig[Iterator].SSE_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSF_u8Port, SEVSEG_astConfig[Iterator].SSF_u8Pin, &local_stGpioConfig);
                local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSG_u8Port, SEVSEG_astConfig[Iterator].SSG_u8Pin, &local_stGpioConfig);                
                if(SEVSEG_astConfig[Iterator].SSDot_Enable == _DOT_ENABLED_){
                    local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SSDot_u8Port, SEVSEG_astConfig[Iterator].SSDot_u8Pin, &local_stGpioConfig);
                }
                if(SEVSEG_astConfig[Iterator].SS_u8ComConnected == _COM_CONNECTED_){
                    local_enuError = GPIO_enuSetPinConfiguration(SEVSEG_astConfig[Iterator].SS_u8ComPort, SEVSEG_astConfig[Iterator].SS_u8ComPin, &local_stGpioConfig);
                }
            }else{
                return ES_OUT_OF_RANGE;
            }

            return local_enuError == ES_OK? local_enuError: ES_NOK;
        }
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t SEVSEG_enuDisplayDigit(uint8_t Copy_u8SevSegId, uint8_t Copy_u8Digit){
    if(Copy_u8SevSegId < SEVEN_SEGMENTS_NUM){
        ErrorStates_t local_enuError = ES_NOK;
        if(SEVSEG_astConfig[Copy_u8SevSegId].SS_u8Com == _COM_CATHODE_){
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSA_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSA_u8Pin, (SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 0);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSB_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSB_u8Pin, (SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 1);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSC_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSC_u8Pin, (SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 2);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSD_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSD_u8Pin, (SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 3);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSE_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSE_u8Pin, (SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 4);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSF_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSF_u8Pin, (SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 5);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSG_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSG_u8Pin, (SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 6);
        }else if(SEVSEG_astConfig[Copy_u8SevSegId].SS_u8Com == _COM_ANODE_){
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSA_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSA_u8Pin, ~(SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 0);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSB_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSB_u8Pin, ~(SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 1);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSC_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSC_u8Pin, ~(SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 2);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSD_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSD_u8Pin, ~(SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 3);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSE_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSE_u8Pin, ~(SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 4);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSF_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSF_u8Pin, ~(SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 5);
            local_enuError = GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSG_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSG_u8Pin, ~(SEVSEG_au8Values[Copy_u8Digit] & BIT_MASK) >> 6);
        }else{
            return ES_OUT_OF_RANGE;
        }
        return local_enuError == ES_OK? local_enuError: ES_NOK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t SEVSEG_enuEnableCommon(uint8_t Copy_u8SevSegId){
    if(Copy_u8SevSegId < SEVEN_SEGMENTS_NUM){
        switch (SEVSEG_astConfig[Copy_u8SevSegId].SS_u8Com)
        {
        case _COM_ANODE_:
            GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SS_u8ComPort, SEVSEG_astConfig[Copy_u8SevSegId].SS_u8ComPin, GPIO_OUTPUT_HIGH);
            break;

        case _COM_CATHODE_:
            GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SS_u8ComPort, SEVSEG_astConfig[Copy_u8SevSegId].SS_u8ComPin, GPIO_OUTPUT_LOW);
            break;        
        default:
            return ES_OUT_OF_RANGE;
            break;
        }
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t SEVSEG_enuDisableCommon(uint8_t Copy_u8SevSegId){
    if(Copy_u8SevSegId < SEVEN_SEGMENTS_NUM){
        switch (SEVSEG_astConfig[Copy_u8SevSegId].SS_u8Com)
        {
        case _COM_ANODE_:
            GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SS_u8ComPort, SEVSEG_astConfig[Copy_u8SevSegId].SS_u8ComPin, GPIO_OUTPUT_LOW);
            break;

        case _COM_CATHODE_:
            GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SS_u8ComPort, SEVSEG_astConfig[Copy_u8SevSegId].SS_u8ComPin, GPIO_OUTPUT_HIGH);
            break;        
        default:
            return ES_OUT_OF_RANGE;
            break;
        }
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t SEVSEG_enuEnableDot(uint8_t Copy_u8SevSegId){
    if(Copy_u8SevSegId < SEVEN_SEGMENTS_NUM){
        switch (SEVSEG_astConfig[Copy_u8SevSegId].SS_u8Com)
        {
        case _COM_ANODE_:
            GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSDot_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSDot_u8Pin, GPIO_OUTPUT_LOW);
            break;
        case _COM_CATHODE_:
            GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSDot_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSDot_u8Pin, GPIO_OUTPUT_HIGH);
            break;        
        default:
            return ES_OUT_OF_RANGE;
            break;
        }
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t SEVSEG_enuDisableDot(uint8_t Copy_u8SevSegId){
    if(Copy_u8SevSegId < SEVEN_SEGMENTS_NUM){
        switch (SEVSEG_astConfig[Copy_u8SevSegId].SS_u8Com)
        {
        case _COM_ANODE_:
            GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSDot_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSDot_u8Pin, GPIO_OUTPUT_HIGH);
            break;
        case _COM_CATHODE_:
            GPIO_enuSetPinValue(SEVSEG_astConfig[Copy_u8SevSegId].SSDot_u8Port, SEVSEG_astConfig[Copy_u8SevSegId].SSDot_u8Pin, GPIO_OUTPUT_LOW);
            break;        
        default:
            return ES_OUT_OF_RANGE;
            break;
        }
    }else{
        return ES_OUT_OF_RANGE;
    }
}