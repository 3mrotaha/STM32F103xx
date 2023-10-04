/*
 * LCD_prog.c
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/SysTick/SysTick_interface.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/HAL/LCD/LCD_private.h"
#include "../../../Inc/HAL/LCD/LCD_config.h"


ErrorStates_t LCD_enuInit(void){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	GPIO_PinConfig_t Local_PinConfig = {
		.mode = GPIO_OUTPUT_10MHZ,
		.config = GPIO_OUTPUT_PUSHPULL,
		.value = GPIO_OUTPUT_LOW
	};
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(RS_PORT, RS_PIN, &Local_PinConfig);
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(RW_PORT, RW_PIN, &Local_PinConfig);
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(EN_PORT, EN_PIN, &Local_PinConfig);

	Local_enuErrorStates = GPIO_enuSetPinConfiguration(D7_PORT, D7_PIN, &Local_PinConfig);
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(D6_PORT, D6_PIN, &Local_PinConfig);
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(D5_PORT, D5_PIN, &Local_PinConfig);
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(D4_PORT, D4_PIN, &Local_PinConfig);
	SysTick_vidDelayMs(30);
#if LCD_BIT_MODE == EIGHT_BIT_MODE

	Local_enuErrorStates = GPIO_enuSetPinConfiguration(D3_PORT, D3_PIN, &Local_PinConfig);
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(D2_PORT, D2_PIN, &Local_PinConfig);
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(D1_PORT, D1_PIN, &Local_PinConfig);
	Local_enuErrorStates = GPIO_enuSetPinConfiguration(D0_PORT, D0_PIN, &Local_PinConfig);

	Local_enuErrorStates = LCD_enuToSendCommand(_FUNCTION_SET_CMD_ | _EIGHT_BIT_INTERFACE_ | _TWO_LINE_LCD_ | _FIVE_BY_EIGHT_FONT_);
	SysTick_vidDelayMs(1);

#elif LCD_BIT_MODE == FOUR_BIT_MODE
	Local_enuErrorStates = LCD_enuToSendCommand(_FUNCTION_SET_CMD_ | _FOUR_BIT_INTERFACE_ | _TWO_LINE_LCD_ | _FIVE_BY_EIGHT_FONT_);
	SysTick_vidDelayMs(1);
#endif

	Local_enuErrorStates = LCD_enuToSendCommand(_DISPLAY_ON_OFF_CONTROL_CMD_ | _DISPLAY_ON_ | _CURSOR_ON_ | _BLINK_ON_);
	SysTick_vidDelayMs(1);
	Local_enuErrorStates = LCD_enuToSendCommand(_CLEAR_DISPLAY_CMD_);
	SysTick_vidDelayMs(2);
	Local_enuErrorStates = LCD_enuToSendCommand(_ENTRY_MODE_SET_CMD_ | _ENTRY_SHIFT_DECREMENT_ | _ENTRY_LEFT_);
	SysTick_vidDelayMs(2);	

	return Local_enuErrorStates;
}

ErrorStates_t LCD_enuSendCommand(uint8_t Copy_u8Command){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = LCD_enuToSendCommand(Copy_u8Command);

	return Local_enuErrorStates = ES_OK;
}

ErrorStates_t LCD_enuDisplayChar(uint8_t Copy_u8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	Local_enuErrorStates = LCD_enuSendData(Copy_u8Data);

	return Local_enuErrorStates;
}

ErrorStates_t LCD_enuDisplayString(uint8_t* Copy_u8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	uint8_t Local_u8Iterator = 0;
	if(Copy_u8Data != NULL){
		while(Copy_u8Data[Local_u8Iterator] != '\0'){
			Local_enuErrorStates = LCD_enuSendData(Copy_u8Data[Local_u8Iterator]);
			Local_u8Iterator++;
		}
	}
	else{
		Local_enuErrorStates = ES_NULL_POINTER;
	}
	return Local_enuErrorStates;
}

ErrorStates_t LCD_enuDisplayInteger(sint64_t Copy_s64Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = LCD_enuDisplayNumber(Copy_s64Data);
	return Local_enuErrorStates;
}

ErrorStates_t LCD_enuDisplayFloat(f64_t Copy_f64Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	sint64_t Local_s64RealNum;
	f64_t	Local_f64_tFraction;
	if(Copy_f64Data < 0){
		Local_enuErrorStates = LCD_enuSendData('-');
		Copy_f64Data *= -1;
	}

	Local_s64RealNum = (sint64_t) Copy_f64Data;
	Local_f64_tFraction = Copy_f64Data - Local_s64RealNum;

	Local_enuErrorStates = LCD_enuDisplayNumber(Local_s64RealNum);
	Local_enuErrorStates = LCD_enuSendData('.');

	uint8_t Local_u8Iterator;
	for(Local_u8Iterator = 0; Local_u8Iterator < FRACTION_MAX_RANGE; Local_u8Iterator++)
		Local_f64_tFraction *= 10;

	Local_enuErrorStates = LCD_enuDisplayNumber(Local_f64_tFraction);
	return Local_enuErrorStates;
}

static inline ErrorStates_t LCD_enuSendData(uint8_t Copy_u8Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;
	Local_enuErrorStates = GPIO_enuSetPinValue(RS_PORT, RS_PIN, GPIO_OUTPUT_HIGH);
	Local_enuErrorStates = GPIO_enuSetPinValue(RW_PORT, RW_PIN, GPIO_OUTPUT_LOW);
	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_LOW);

	Local_enuErrorStates = GPIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK & (Copy_u8Data >> 7));
	Local_enuErrorStates = GPIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK & (Copy_u8Data >> 6));
	Local_enuErrorStates = GPIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK & (Copy_u8Data >> 5));
	Local_enuErrorStates = GPIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK & (Copy_u8Data >> 4));

#if LCD_BIT_MODE == EIGHT_BIT_MODE
	Local_enuErrorStates = GPIO_enuSetPinValue(D3_PORT, D3_PIN, BIT_MASK & (Copy_u8Data >> 3));
	Local_enuErrorStates = GPIO_enuSetPinValue(D2_PORT, D2_PIN, BIT_MASK & (Copy_u8Data >> 2));
	Local_enuErrorStates = GPIO_enuSetPinValue(D1_PORT, D1_PIN, BIT_MASK & (Copy_u8Data >> 1));
	Local_enuErrorStates = GPIO_enuSetPinValue(D0_PORT, D0_PIN, BIT_MASK & (Copy_u8Data >> 0));
#elif LCD_BIT_MODE == FOUR_BIT_MODE
	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_HIGH);
	SysTick_vidDelayMs(10);
	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_LOW);
	SysTick_vidDelayMs(10);
	Local_enuErrorStates = GPIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK & (Copy_u8Data >> 3));
	Local_enuErrorStates = GPIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK & (Copy_u8Data >> 2));
	Local_enuErrorStates = GPIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK & (Copy_u8Data >> 1));
	Local_enuErrorStates = GPIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK & (Copy_u8Data >> 0));
#endif

	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_HIGH);
	SysTick_vidDelayMs(10);
	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_LOW);
	SysTick_vidDelayMs(10);
	return Local_enuErrorStates;
}

static inline ErrorStates_t LCD_enuToSendCommand(uint8_t Copy_u8Command){
	ErrorStates_t Local_enuErrorStates;
	Local_enuErrorStates = GPIO_enuSetPinValue(RS_PORT, RS_PIN, GPIO_OUTPUT_LOW);
	Local_enuErrorStates = GPIO_enuSetPinValue(RW_PORT, RW_PIN, GPIO_OUTPUT_LOW);
	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_LOW);

	Local_enuErrorStates = GPIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK & (Copy_u8Command >> 7));
	Local_enuErrorStates = GPIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK & (Copy_u8Command >> 6));
	Local_enuErrorStates = GPIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK & (Copy_u8Command >> 5));
	Local_enuErrorStates = GPIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK & (Copy_u8Command >> 4));

#if LCD_BIT_MODE == EIGHT_BIT_MODE
	Local_enuErrorStates = GPIO_enuSetPinValue(D3_PORT, D3_PIN, BIT_MASK & (Copy_u8Command >> 3));
	Local_enuErrorStates = GPIO_enuSetPinValue(D2_PORT, D2_PIN, BIT_MASK & (Copy_u8Command >> 2));
	Local_enuErrorStates = GPIO_enuSetPinValue(D1_PORT, D1_PIN, BIT_MASK & (Copy_u8Command >> 1));
	Local_enuErrorStates = GPIO_enuSetPinValue(D0_PORT, D0_PIN, BIT_MASK & (Copy_u8Command >> 0));
#elif LCD_BIT_MODE == FOUR_BIT_MODE
	if(Copy_u8Command == 0x28){
		Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_HIGH);
		SysTick_vidDelayMs(10);
		Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_LOW);
		SysTick_vidDelayMs(10);
		Local_enuErrorStates = GPIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK & (Copy_u8Command >> 7));
		Local_enuErrorStates = GPIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK & (Copy_u8Command >> 6));
		Local_enuErrorStates = GPIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK & (Copy_u8Command >> 5));
		Local_enuErrorStates = GPIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK & (Copy_u8Command >> 4));
	}
	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_HIGH);
	SysTick_vidDelayMs(10);
	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_LOW);
	SysTick_vidDelayMs(10);
	Local_enuErrorStates = GPIO_enuSetPinValue(D7_PORT, D7_PIN, BIT_MASK & (Copy_u8Command >> 3));
	Local_enuErrorStates = GPIO_enuSetPinValue(D6_PORT, D6_PIN, BIT_MASK & (Copy_u8Command >> 2));
	Local_enuErrorStates = GPIO_enuSetPinValue(D5_PORT, D5_PIN, BIT_MASK & (Copy_u8Command >> 1));
	Local_enuErrorStates = GPIO_enuSetPinValue(D4_PORT, D4_PIN, BIT_MASK & (Copy_u8Command >> 0));
#endif

	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_HIGH);
	SysTick_vidDelayMs(10);
	Local_enuErrorStates = GPIO_enuSetPinValue(EN_PORT, EN_PIN, GPIO_OUTPUT_LOW);
	SysTick_vidDelayMs(10);

	return Local_enuErrorStates;
}

static inline ErrorStates_t LCD_enuDisplayNumber(sint64_t Copy_u64Data){
	ErrorStates_t Local_enuErrorStates = ES_NOK;

	uint8_t Local_u8Digits = 1;
	sint64_t Local_u64Dividor = 10;

	if(Copy_u64Data < 0){
		Local_enuErrorStates = LCD_enuSendData('-');
		Copy_u64Data *= -1;
	}

	while(Copy_u64Data / Local_u64Dividor){
		Local_u64Dividor *= 10;
		++Local_u8Digits;
	}

	while(Local_u8Digits--){
		Local_u64Dividor /= 10;
		Local_enuErrorStates = LCD_enuSendData('0' + (Copy_u64Data / Local_u64Dividor));
		Copy_u64Data -= ((Copy_u64Data / Local_u64Dividor) * Local_u64Dividor);
	}

	return Local_enuErrorStates;
}


