#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"

#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/HAL/SWITCH/SW_private.h"
#include "../../../Inc/HAL/SWITCH/SW_config.h"

extern SW_t SW_AstrSwitches[SW_NUM];

ErrorStates_t SW_enuInit(void){
	if(SW_NUM >= 0){
		ErrorStates_t local_enuError = ES_NOK;
		for(uint8_t Iterator = 0; Iterator < SW_NUM; Iterator++){
			local_enuError = GPIO_enuSetPinConfiguration(SW_AstrSwitches[Iterator].SW_u8PortID, SW_AstrSwitches[Iterator].SW_u8PinID, &(GPIO_PinConfig_t){
				.mode = GPIO_INPUT,
				.config = GPIO_INPUT_PULLUP_DOWN,
				.value = SW_AstrSwitches[Iterator].SW_u8State
			});
		}
		return local_enuError == ES_OK? local_enuError: ES_NOK;
	}else{
		return ES_OUT_OF_RANGE;
	}
}


ErrorStates_t SW_enuGetState(uint8_t Copy_u8SwitchId, uint8_t* Copy_puint8Value){
	if(Copy_puint8Value == NULL){
		if(Copy_u8SwitchId < SW_NUM){
			ErrorStates_t local_enuError = ES_NOK;
			local_enuError = GPIO_enuGetPinValue(SW_AstrSwitches[Copy_u8SwitchId].SW_u8PortID, SW_AstrSwitches[Copy_u8SwitchId].SW_u8PinID, Copy_puint8Value);
			return local_enuError == ES_OK? local_enuError: ES_NOK;
		}else{
			return ES_OUT_OF_RANGE;
		}
	}else{
		return ES_NULL_POINTER;
	}
}