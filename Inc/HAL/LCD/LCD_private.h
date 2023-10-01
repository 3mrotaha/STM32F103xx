/*
 * LCD_private.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"

// LCD Commands
#define _CLEAR_DISPLAY_CMD_           (0x01)
#define _RETURN_HOME_CMD_             (0x02)
#define _SET_CGRAM_ADDRESS_CMD_       (0x40)
#define _SET_DDRAM_ADDRESS_CMD_       (0x80)

// Entry Mode Set Options
#define _ENTRY_MODE_SET_CMD_          (0x04)
#define _ENTRY_RIGHT_                 (0x02) // Bit 1 (I/D = 1)
#define _ENTRY_LEFT_                  (0x00) // Bit 1 (I/D = 0)
#define _ENTRY_SHIFT_INCREMENT_       (0x01) // Bit 0 (S = 1)
#define _ENTRY_SHIFT_DECREMENT_       (0x00) // Bit 0 (S = 0)

// Display On/Off Control Options
#define _DISPLAY_ON_OFF_CONTROL_CMD_  (0x08)
#define _DISPLAY_ON_                  (0x04) // Bit 2 (D = 1)
#define _DISPLAY_OFF_                 (0x00) // Bit 2 (D = 0)
#define _CURSOR_ON_                   (0x02) // Bit 1 (C = 1)
#define _CURSOR_OFF_                  (0x00) // Bit 1 (C = 0)
#define _BLINK_ON_                    (0x01) // Bit 0 (B = 1)
#define _BLINK_OFF_                   (0x00) // Bit 0 (B = 0)

// Cursor/Display Shift Options
#define _CURSOR_DISPLAY_SHIFT_CMD_     (0x10)
#define _DISPLAY_SHIFT_                (0x08) // Bit 3 (S/C = 1)
#define _CURSOR_SHIFT_                 (0x00) // Bit 3 (S/C = 0)
#define _SHIFT_RIGHT_                  (0x04) // Bit 2 (R/L = 1)
#define _SHIFT_LEFT_                   (0x00) // Bit 2 (R/L = 0)

// Function Set Options
#define _FUNCTION_SET_CMD_            (0x20)
#define _TWO_LINE_LCD_                (0x08) // Bit 3 (N = 1)
#define _ONE_LINE_LCD_                (0x00) // Bit 3 (N = 0)
#define _EIGHT_BIT_INTERFACE_         (0x10) // Bit 4 (DL = 1)
#define _FOUR_BIT_INTERFACE_          (0x00) // Bit 4 (DL = 0)
#define _FIVE_BY_TEN_FONT_            (0x04) // Bit 2 (F = 1)
#define _FIVE_BY_EIGHT_FONT_          (0x00) // Bit 2 (F = 0)

// Set CGRAM Address Options (for custom character generation)
#define _CGRAM_ADDRESS_BASE_          (0x40) // Base address for CGRAM


#define EIGHT_BIT_MODE	90
#define FOUR_BIT_MODE	80

static inline ErrorStates_t LCD_enuToSendCommand(uint8_t Copy_u8Command);

static inline ErrorStates_t LCD_enuSendData(uint8_t Copy_u8Data);

static inline ErrorStates_t LCD_enuDisplayNumber(sint64_t Copy_uint32Data);

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
