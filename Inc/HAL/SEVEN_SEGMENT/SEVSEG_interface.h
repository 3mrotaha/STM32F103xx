/*
 * SEVSEG_interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_SEVEN_SEGMENT_SEVSEG_INTERFACE_H_
#define HAL_SEVEN_SEGMENT_SEVSEG_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"
#include "SEVSEG_private.h"

#define SEV_SEG_COMMON_CATHODE  _COM_CATHODE_
#define SEV_SEG_COMMON_ANODE    _COM_ANODE_

#define SEV_SEG_ENABLE_DOT      _DOT_ENABLED_
#define SEV_SEG_DISABLE_DOT     _DOT_DISABLED_

#define SEV_SEG_COM_CONNECTED   _COM_CONNECTED_
#define SEV_SEG_COM_DISCONNECTED   _COM_DISCONNECTED_

ErrorStates_t SEVSEG_enuInit(void);

ErrorStates_t SEVSEG_enuDisplayDigit(uint8_t Copy_u8SevSegId, uint8_t Copy_u8Digit);

ErrorStates_t SEVSEG_enuEnableCommon(uint8_t Copy_u8SevSegId);

ErrorStates_t SEVSEG_enuDisableCommon(uint8_t Copy_u8SevSegId);

ErrorStates_t SEVSEG_enuEnableDot(uint8_t Copy_u8SevSegId);

ErrorStates_t SEVSEG_enuDisableDot(uint8_t Copy_u8SevSegId);

#endif /* HAL_SEVEN_SEGMENT_SEVSEG_INTERFACE_H_ */
