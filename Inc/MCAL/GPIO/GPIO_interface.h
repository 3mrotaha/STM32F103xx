/**
 * @file GPIO_interface.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief  this file contains the API's used 
 *         by the user to control the GPIO peripheral.
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_
#include "../../LIB/Error_States.h"
#include "../../LIB/std_types.h"
#include "GPIO_private.h"

/**
 * @ref PIN_CONFIGURATION_TYPE
 * @brief this structure is used to set the configuration
 * for a pin when it's passed to one of GPIO driver functions
 * - mode (uint8_t): used to set the mode of the pin, possible values @ref PORT_MODES
 * - config (uint8_t): used to set the configuration for the pin, values @ref PORT_CONFIGURATION
 * - value (uin8_t): used to set the output data value, or to set the pullup/down input mode in case of
 *  input only. possible values @ref PORT_VALUES
 */
typedef struct ST_GPIO_PinConfig
{
    uint8_t mode; // input / output
    uint8_t config; // input config/ output config
    uint8_t value; // output value or input connectivity type (pullup/pulldown)
}GPIO_PinConfig_t;

/**
 * @ref PORT_ENABLE
*/
#define ENABLE_PORT                 _ENABLE_PORT_
#define DISABLE_PORT                _DISABLE_PORT_

/**
 * @ref PORT_IDs
 *
 */
#define GPIO_PORTA                  _GPIO_PORTA_
#define GPIO_PORTB                  _GPIO_PORTB_
#define GPIO_PORTC                  _GPIO_PORTC_
#define GPIO_PORTD                  _GPIO_PORTD_
#define GPIO_PORTE                  _GPIO_PORTE_

/**
 * @ref PIN_IDs
 *
 */
#define GPIO_PIN_0                  _GPIO_PIN_0_
#define GPIO_PIN_1                  _GPIO_PIN_1_
#define GPIO_PIN_2                  _GPIO_PIN_2_
#define GPIO_PIN_3                  _GPIO_PIN_3_
#define GPIO_PIN_4                  _GPIO_PIN_4_
#define GPIO_PIN_5                  _GPIO_PIN_5_
#define GPIO_PIN_6                  _GPIO_PIN_6_
#define GPIO_PIN_7                  _GPIO_PIN_7_
#define GPIO_PIN_8                  _GPIO_PIN_8_
#define GPIO_PIN_9                  _GPIO_PIN_9_
#define GPIO_PIN_10                 _GPIO_PIN_10_
#define GPIO_PIN_11                 _GPIO_PIN_11_
#define GPIO_PIN_12                 _GPIO_PIN_12_
#define GPIO_PIN_13                 _GPIO_PIN_13_
#define GPIO_PIN_14                 _GPIO_PIN_14_
#define GPIO_PIN_15                 _GPIO_PIN_15_

/**
 * @ref PIN_MODES
 */
#define GPIO_INPUT                  _GPIO_INPUT_
#define GPIO_OUTPUT_2MHZ            _GPIO_OUTPUT_2MHZ_
#define GPIO_OUTPUT_10MHZ           _GPIO_OUTPUT_10MHZ_
#define GPIO_OUTPUT_50MHZ           _GPIO_OUTPUT_50MHZ_
/**
 * @ref PORT_CONFIGURATION
 *
 */
// INPUT CONFIGURATION
#define GPIO_INPUT_ANALOG           _GPIO_INPUT_ANALOG_
#define GPIO_INPUT_PULLUP_DOWN      _GPIO_INPUT_PULLUP_DOWN_
#define GPIO_INPUT_FLOAT            _GPIO_INPUT_FLOAT_
// OUTPUT CONFIGURATION
#define GPIO_OUTPUT_OPENDRAIN       _GPIO_OUTPUT_OPENDRAIN_
#define GPIO_OUTPUT_PUSHPULL        _GPIO_OUTPUT_PUSHPULL_
#define GPIO_ALT_OUTPUT_OPENDRAIN   _GPIO_ALT_OUTPUT_OPENDRAIN_
#define GPIO_ALT_OUTPUT_PUSHPULL    _GPIO_ALT_OUTPUT_PUSHPULL_

/**
 * @ref PIN_LOCKING
 * to lock the pin on it's value (can't be changed until the next reset)
 */
#define GPIO_PIN_LOCKED             _LOCKED_
#define GPIO_PIN_UNLOCKED           _UNLOCKED_

/**
 * @ref PORT_VALUES
 *
 */
// for INPUT pins
#define GPIO_INPUT_PULLUP           _GPIO_INPUT_PULLUP_
#define GPIO_INPUT_PULLDOWN         _GPIO_INPUT_PULLDOWN_
// for OUTPUT pins
#define GPIO_OUTPUT_HIGH            _HIGH_
#define GPIO_OUTPUT_LOW             _LOW_


/***************************************************
* @name   - GPIO_vidInit
* @param  - void
* @return - void
* @brief  - initializing the GPIO peripheral
* @pre    - setting the configurations in GPIO_config.h
* @post   - none
***************************************************/
void GPIO_vidInit(void);


/***************************************************
* @name   - GPIO_enuSetPinConfiguration
* @param    Copy_u8PortId (uint8_t)
*           this is used to select the GPIO/Port Number, possible
*           arguments at @ref PORT_IDs
* @param    Copy_u8PinId (uint8_t)
*           this is used to select the pin number, possible
*           arguments at @ref PIN_IDs
* @param    Copy_pstPinConfig (GPIO_PinConfig_t*)
*           used to pass the configurations chosen for the pin
*           for more info @ref PIN_CONFIGURATION_TYPE
* @return - ES_OK (ErrorStates_t)
*           in case of successful configuration
* @return - ES_NOK (ErrorStates_t)
*           in case of something went wrong.
* @return - ES_OUT_OF_RANGE (ErrorStates_t)
*           in case of port or pin values out of range
* @return - ES_NULL_POINTER (ErrorStates_t)
*           in case of null pointer parameter.
* @brief  - use this function to set a specific pin configuration
* @pre    - port initialization using @name GPIO_vidInit
* @post   - none
***************************************************/
ErrorStates_t GPIO_enuSetPinConfiguration(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId, GPIO_PinConfig_t* Copy_pstPinConfig);

/***************************************************
* @name   - GPIO_enuSetPinValue
* @param    Copy_u8PortId (uint8_t)
*           this is used to select the GPIO/Port Number, possible
*           arguments at @ref PORT_IDs
* @param    Copy_u8PinId (uint8_t)
*           this is used to select the pin number, possible
*           arguments at @ref PIN_IDs
* @param    Copy_u8PinValue (uint8_t)
*           the value that the pin is set to, possible
*           arguments @ref PORT_VALUES
* @return - ES_OK (ErrorStates_t)
*           in case of successful configuration
* @return - ES_NOK (ErrorStates_t)
*           in case of something went wrong.
* @return - ES_OUT_OF_RANGE (ErrorStates_t)
*           in case of port or pin values out of range
* @brief  - use this function to set the external GPIO pin value
* @pre    - set the pin to output using @name GPIO_enuSetPinConfiguration
* @post   - none
***************************************************/
ErrorStates_t GPIO_enuSetPinValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId, uint8_t Copy_u8PinValue);

/***************************************************
* @name   - GPIO_enuGetPinValue
* @param    Copy_u8PortId (uint8_t)
*           this is used to select the GPIO/Port Number, possible
*           arguments at @ref PORT_IDs
* @param    Copy_u8PinId (uint8_t)
*           this is used to select the pin number, possible
*           arguments at @ref PIN_IDs
* @param    Copy_pu8PinValue (uint8_t*)
*           the value to be read from the pin.
* @return - ES_OK (ErrorStates_t)
*           in case of successful configuration
* @return - ES_NOK (ErrorStates_t)
*           in case of something went wrong.
* @return - ES_OUT_OF_RANGE (ErrorStates_t)
*           in case of port or pin values out of range.
* @return - ES_NULL_POINTER (ErrorStates_t)
*           in case of null pointer parameter.
* @brief  - use this function to read the GPIO external pin value.
* @pre    - set the pin to input using @name GPIO_enuSetPinConfiguration
*         - Copy_u8PinValue pointer isn't null
* @post   - none
***************************************************/
ErrorStates_t GPIO_enuGetPinValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId, uint8_t *Copy_pu8PinValue);

/***************************************************
* @name   - GPIO_enuTogglePinValue
* @param    Copy_u8PortId (uint8_t)
*           this is used to select the GPIO/Port Number, possible
*           arguments at @ref PORT_IDs
* @param    Copy_u8PinId (uint8_t)
*           this is used to select the pin number, possible
*           arguments at @ref PIN_IDs
* @return - ES_OK (ErrorStates_t)
*           in case of successful configuration
* @return - ES_NOK (ErrorStates_t)
*           in case of something went wrong.
* @return - ES_OUT_OF_RANGE (ErrorStates_t)
*           in case of port or pin values out of range
* @brief  - use this function to toggle the GPIO external pin value
* @pre    - set the pin to input using @name GPIO_enuSetPinConfiguration
* @post   - none
***************************************************/
ErrorStates_t GPIO_enuTogglePinValue(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId);

/***************************************************
* @name   - GPIO_enuSetPortValue
* @param    Copy_u8PortId (uint8_t)
*           this is used to select the GPIO/Port Number, possible
*           arguments at @ref PORT_IDs
* @param    Copy_u16PortValue (uint16_t)
*           this is used to pass the value of the GPIOx external 
*           pins values.
* @return - ES_OK (ErrorStates_t)
*           in case of successful configuration
* @return - ES_NOK (ErrorStates_t)
*           in case of something went wrong.
* @return - ES_OUT_OF_RANGE (ErrorStates_t)
*           in case of port or pin values out of range.
* @brief  - use this function to set the GPIOx external PORT pins values
* @pre    - set the Port pins to output using @name GPIO_enuSetPinConfiguration
* @post   - none
***************************************************/
ErrorStates_t GPIO_enuSetPortValue(uint8_t Copy_u8PortId, uint16_t Copy_u16PortValue);

/***************************************************
* @name   - GPIO_enuGetPortValue
* @param    Copy_u8PortId (uint8_t)
*           this is used to select the GPIO/Port Number, possible
*           arguments at @ref PORT_IDs
* @param    Copy_pu16PortValue (uint16_t*)
*           this is used to store the value of the GPIOx external 
*           pins values.
* @return - ES_OK (ErrorStates_t)
*           in case of successful configuration
* @return - ES_NOK (ErrorStates_t)
*           in case of something went wrong.
* @return - ES_OUT_OF_RANGE (ErrorStates_t)
*           in case of port or pin values out of range.
* @return - ES_NULL_POINTER (ErrorStates_t)
*           in case of null pointer parameter.
* @brief  - use this function to read the GPIOx external PORT pins values
* @pre    - set the Port pins to input using @name GPIO_enuSetPinConfiguration
* @post   - none
***************************************************/
ErrorStates_t GPIO_enuGetPortValue(uint8_t Copy_u8PortId, uint16_t *Copy_pu16PortValue);

/***************************************************
* @name   - GPIO_enuLockPin
* @param    Copy_u8PortId (uint8_t)
*           this is used to select the GPIO/Port Number, possible
*           arguments at @ref PORT_IDs
* @param    Copy_u8PinId (uint8_t)
*           this is used to select the pin number, possible
*           arguments at @ref PIN_IDs
* @return - ES_OK (ErrorStates_t)
*           in case of successful configuration
* @return - ES_NOK (ErrorStates_t)
*           in case of something went wrong.
* @return - ES_OUT_OF_RANGE (ErrorStates_t)
*           in case of port or pin values out of range
* @brief  - used to lock a specific pin on its value, in this
*           case the pin can't be modified until the next reset.
* @pre    - initialize the pins using @name GPIO_vidInit
* @post   - the locked pin can't be modified until the next reset.
***************************************************/
ErrorStates_t GPIO_enuLockPin(uint8_t Copy_u8PortId, uint8_t Copy_u8PinId);

#endif