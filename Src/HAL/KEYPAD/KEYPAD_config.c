#include "../../../Inc/HAL/KEYPAD/KEYPAD_config.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

KPAD_t KPAD_AstrKeyPadConfig[NUM_OF_KPADS] = {
	{
		{
				{GPIO_PORTA, GPIO_PIN_0},
				{GPIO_PORTA, GPIO_PIN_1},
				{GPIO_PORTA, GPIO_PIN_2},
				{GPIO_PORTA, GPIO_PIN_3}
		},
		{
				{GPIO_PORTA, GPIO_PIN_4},
				{GPIO_PORTA, GPIO_PIN_5},
				{GPIO_PORTA, GPIO_PIN_6},
				{GPIO_PORTA, GPIO_PIN_7}
		}
	}
};