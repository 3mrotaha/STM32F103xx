

#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"

#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/HAL/LED/LED_private.h"
#include "../../../Inc/HAL/LED/LED_config.h"

extern LED_t LED_AstrLEDs[LED_NUM];

ErrorStates_t LED_enuInit(void){
    if(LED_NUM > 0){
        ErrorStates_t Local_enuError = ES_NOK;
        uint8_t outVal = GPIO_OUTPUT_HIGH;
        for(uint8_t Iterator = 0; Iterator < LED_NUM; Iterator++){
            // output value according to led connectivity
            Local_enuError = GPIO_enuSetPinConfiguration(LED_AstrLEDs[Iterator].LED_u8PortID, LED_AstrLEDs[Iterator].LED_u8PinID, &(GPIO_PinConfig_t){
                .mode = GPIO_OUTPUT_2MHZ,
                .config = GPIO_OUTPUT_PUSHPULL,
                .value = LED_AstrLEDs[Iterator].LED_u8State
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
        if(LED_AstrLEDs[Copy_u8LedId].LED_u8Connection == _LED_SINK_){
            Local_enuError = GPIO_enuSetPinValue(LED_AstrLEDs[Copy_u8LedId].LED_u8PortID, LED_AstrLEDs[Copy_u8LedId].LED_u8PinID, GPIO_OUTPUT_LOW);
        }else if(LED_AstrLEDs[Copy_u8LedId].LED_u8Connection == _LED_SRC_){
            Local_enuError = GPIO_enuSetPinValue(LED_AstrLEDs[Copy_u8LedId].LED_u8PortID, LED_AstrLEDs[Copy_u8LedId].LED_u8PinID, GPIO_OUTPUT_HIGH);
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
        if(LED_AstrLEDs[Copy_u8LedId].LED_u8Connection == _LED_SINK_){
            Local_enuError = GPIO_enuSetPinValue(LED_AstrLEDs[Copy_u8LedId].LED_u8PortID, LED_AstrLEDs[Copy_u8LedId].LED_u8PinID, GPIO_OUTPUT_HIGH);
        }else if(LED_AstrLEDs[Copy_u8LedId].LED_u8Connection == _LED_SRC_){
            Local_enuError = GPIO_enuSetPinValue(LED_AstrLEDs[Copy_u8LedId].LED_u8PortID, LED_AstrLEDs[Copy_u8LedId].LED_u8PinID, GPIO_OUTPUT_LOW);
        }else{
            return ES_OUT_OF_RANGE;
        }
        return Local_enuError == ES_OK? ES_OK:ES_NOK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t LED_enuToggle(uint8_t Copy_u8LedId){
    if(Copy_u8LedId < LED_NUM){
        ErrorStates_t Local_enuError = ES_NOK;
        Local_enuError = GPIO_enuTogglePinValue(LED_AstrLEDs[Copy_u8LedId].LED_u8PortID, LED_AstrLEDs[Copy_u8LedId].LED_u8PinID);
        return Local_enuError == ES_OK? ES_OK:ES_NOK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}