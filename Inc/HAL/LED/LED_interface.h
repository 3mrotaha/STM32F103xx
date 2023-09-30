/*
 * LED_interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: amrmo
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"
#include "LED_private.h"

#define LED_SINK _LED_SINK_
#define LED_SOURCE _LED_SRC_

/**
 * @name LED_enuInit
 * @brief this function is used to initialize the LED
 * @param void
 * @return - ES_OK (ErrorState_t)
 *           if the function is executed correctly
 *        - ES_NOK (ErrorState_t)
 *          if the function is not executed correctly
 */
ErrorStates_t LED_enuInit(void);


/**
 * @name LED_enuSetLedMode
 * @brief Turns on the LED with the specified ID.
 * 
 * @param Copy_u8LedId The ID of the LED to turn on.
 * @return - ES_OK: The operation is executed successfully.
 *         - ES_NOK: The operation is not executed successfully.
 *         - ES_OUT_OF_RANGE: The ID is out of range.
 */
ErrorStates_t LED_enuTurnON(uint8_t Copy_u8LedId);

/**
 * @name LED_enuTurnOFF
 * @brief Turns off the LED with the specified ID.
 * 
 * @param Copy_u8LedId The ID of the LED to turn off.
 * @return - ES_OK: The operation is executed successfully.
 *         - ES_NOK: The operation is not executed successfully.
 *         - ES_OUT_OF_RANGE: The ID is out of range.
 */
ErrorStates_t LED_enuTurnOFF(uint8_t Copy_u8LedId);

#endif /* HAL_LED_LED_INTERFACE_H_ */
