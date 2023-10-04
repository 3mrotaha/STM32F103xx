/*
 * LCD_interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"
#include "LCD_private.h"
/**
 * @ref LCD_COMMANDS
 * @brief use these definitions to send as commands to LCD
 * @example LCD_enuSendCommand(CLEAR_DISPLAY_CMD);
 */
// LCD Commands
#define CLEAR_DISPLAY_CMD       _CLEAR_DISPLAY_CMD_           
#define RETURN_HOME_CMD         _RETURN_HOME_CMD_             
#define SET_CGRAM_ADDRESS_CMD   _SET_CGRAM_ADDRESS_CMD_       
#define SET_DDRAM_ADDRESS_CMD   _SET_DDRAM_ADDRESS_CMD_ 

/**
 * @ref ENTRY_MODE_COMMANDS
 * @breif use these definitions to send as commands to LCD
 * @example LCD_enuSendCommand(ENTRY_MODE_SET_CMD | ENTRY_RIGHT | ENTRY_SHIFT_INCREMENT);
 */
#define ENTRY_MODE_SET_CMD          _ENTRY_MODE_SET_CMD_          
#define ENTRY_RIGHT                 _ENTRY_RIGHT_                
#define ENTRY_LEFT                  _ENTRY_LEFT_                 
#define ENTRY_SHIFT_INCREMENT       _ENTRY_SHIFT_INCREMENT_      
#define ENTRY_SHIFT_DECREMENT       _ENTRY_SHIFT_DECREMENT_

/**
 * @brief use these definitions to set the display on/off
 * @example LCD_enuSendCommand(DISPLAY_ON_OFF_CONTROL_CMD | DISPLAY_ON | CURSOR_ON | BLINK_ON);
 * 
 */
#define DISPLAY_ON_OFF_CONTROL_CMD  _DISPLAY_ON_OFF_CONTROL_CMD_ 
#define DISPLAY_ON                  _DISPLAY_ON_                 
#define DISPLAY_OFF                 _DISPLAY_OFF_                
#define CURSOR_ON                   _CURSOR_ON_                  
#define CURSOR_OFF                  _CURSOR_OFF_                 
#define BLINK_ON                    _BLINK_ON_                   
#define BLINK_OFF                   _BLINK_OFF_              

/**
 * @brief use these definitions to shift the cursor or the display
 * @example LCD_enuSendCommand(CURSOR_DISPLAY_SHIFT_CMD | DISPLAY_SHIFT | SHIFT_RIGHT);
 */
#define CURSOR_DISPLAY_SHIFT_CMD     _CURSOR_DISPLAY_SHIFT_CMD_     
#define DISPLAY_SHIFT                _DISPLAY_SHIFT_                
#define CURSOR_SHIFT                 _CURSOR_SHIFT_                 
#define SHIFT_RIGHT                  _SHIFT_RIGHT_                  
#define SHIFT_LEFT                   _SHIFT_LEFT_                   




ErrorStates_t LCD_enuInit(void);

ErrorStates_t LCD_enuSendCommand(uint8_t Copy_u8Command);

ErrorStates_t LCD_enuDisplayChar(uint8_t Copy_u8Data);

ErrorStates_t LCD_enuDisplayString(uint8_t* Copy_u8Data);

ErrorStates_t LCD_enuDisplayInteger(sint64_t Copy_s64Data);

ErrorStates_t LCD_enuDisplayFloat(f64_t Copy_f64Data);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
