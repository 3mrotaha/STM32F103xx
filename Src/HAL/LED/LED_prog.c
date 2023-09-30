

#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"

#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/HAL/LED/LED_private.h"
#include "../../../Inc/HAL/LED/LED_config.h"

extern LED_t SW_AstrLEDs[LED_NUM];

ErrorStates_t LED_enuInit(void){
    if(LED_NUM > 0){
        ErrorStates_t Local_enuError = ES_NOK;
        uint8_t outVal = GPIO_OUTPUT_HIGH;
        for(uint8_t Iterator = 0; Iterator < LED_NUM; Iterator++){
            // output value according to led connectivity
            Local_enuError = GPIO_enuSetPinConfiguration(SW_AstrLEDs[Iterator].SW_u8PortID, SW_AstrLEDs[Iterator].SW_u8PinID, &(GPIO_PinConfig_t){
                .mode = GPIO_OUTPUT_2MHZ,
                .config = GPIO_OUTPUT_PUSHPULL,
                .value = SW_AstrLEDs[Iterator].SW_u8State
            });
        }
        // return NOK if some error occured
        return Local_enuError == ES_OK? ES_OK: ES_NOK;
    }
    return ES_NOK;
}

ErrorStates_t LED_enuTurnON(uint8_t Copy_u8LedId){
    if(Copy_u8LedId < LED_NUM){
        ErrorStates_t Local_enuError = ES_NOK;
        if(SW_AstrLEDs[Copy_u8LedId].SW_u8Connection == _LED_SINK_){
            Local_enuError = GPIO_enuSetPinValue(SW_AstrLEDs[Copy_u8LedId].SW_u8PortID, SW_AstrLEDs[Copy_u8LedId].SW_u8PinID, GPIO_OUTPUT_LOW);
        }else if(SW_AstrLEDs[Copy_u8LedId].SW_u8Connection == _LED_SRC_){
            Local_enuError = GPIO_enuSetPinValue(SW_AstrLEDs[Copy_u8LedId].SW_u8PortID, SW_AstrLEDs[Copy_u8LedId].SW_u8PinID, GPIO_OUTPUT_HIGH);
        }else{
            return ES_OUT_OF_RANGE;
        }
        return Local_enuError == ES_OK? ES_OK:ES_NOK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t LED_enuTurnOFF(uint8_t Copy_u8LedId){
    if(Copy_u8LedId < LED_NUM){
        ErrorStates_t Local_enuError = ES_NOK;
        if(SW_AstrLEDs[Copy_u8LedId].SW_u8Connection == _LED_SINK_){
            Local_enuError = GPIO_enuSetPinValue(SW_AstrLEDs[Copy_u8LedId].SW_u8PortID, SW_AstrLEDs[Copy_u8LedId].SW_u8PinID, GPIO_OUTPUT_HIGH);
        }else if(SW_AstrLEDs[Copy_u8LedId].SW_u8Connection == _LED_SRC_){
            Local_enuError = GPIO_enuSetPinValue(SW_AstrLEDs[Copy_u8LedId].SW_u8PortID, SW_AstrLEDs[Copy_u8LedId].SW_u8PinID, GPIO_OUTPUT_LOW);
        }else{
            return ES_OUT_OF_RANGE;
        }
        return Local_enuError == ES_OK? ES_OK:ES_NOK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

