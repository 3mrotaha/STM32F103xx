/*
 * SW_interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_SWITCH_SW_INTERFACE_H_
#define HAL_SWITCH_SW_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"

/**
 * @name SW_enuInit
 * @brief Initializes the switch module.
 * @param void 
 * @return - ES_OK (ErrorStates_t) if the module is initialized successfully.
 *         - ES_NOK (ErrorStates_t) if the module is not initialized successfully.
 */
ErrorStates_t SW_enuInit(void);

/**
 * @name SW_enuGetState
 * @brief Get the state of a switch.
 * @param Copy_u8SwitchId (uint8_t) The ID of the switch to get the state of.
 * @param Copy_puint8Value (uint8_t*) Pointer to a variable to store the switch state in.
 * @return - ES_OK (ErrorStates_t) if the state is read successfully.
 *        - ES_NOK (ErrorStates_t) if the state is not read successfully.
 *        - ES_NULL_POINTER (ErrorStates_t) if passed the pointer is NULL.
 *       - ES_OUT_OF_RANGE (ErrorStates_t) if the switch ID is out of range.
 */
ErrorStates_t SW_enuGetState(uint8_t Copy_u8SwitchId, uint8_t* Copy_puint8Value);

#endif /* HAL_SWITCH_SW_INTERFACE_H_ */
