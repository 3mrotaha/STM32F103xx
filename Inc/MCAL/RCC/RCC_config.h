/**
 * @file RCC_config.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the essential configurations
 *        that're used to initialize the MCU clocking system.
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_
#include "RCC_interface.h"

/**
 * @brief this defines the value of the external clock
 *       if the external clock is used.
 *       the value is in Hz.
 *       Max value is 72000000 Hz.
 */
#define HSE_CLOCK_VALUE             8000000UL

/*
 * @ref SYSTEM_CLOCK_SOURCES
 */
#define SET_SYSTEM_CLOCK_SOURCE     PLL_CLK

/*
 * @ref PLL_SOURCES
*/
#define PLL_SOURCE                  PLL_HIGH_INTERNAL_DIV2_OSC

/*
 * @ref PLL_MULTI_VALUES
 */
#define PLL_MULTIPLICATION_VALUE    PLL_MULTIPLICATION_9

/*
* @ref CLOCK_SECURITY_SYSTEM
*/
#define SET_CLOCK_SECURITY_SYSTEM   CLK_SECURITY_DISABLE
/*
 * @ref AHB_CLOCK_PRESCALER
 */
#define SET_AHB_CLOCK_PRESCALER     AHB_CLK_NOT_DIVIDED

/*
 * @ref APB1_CLOCK_PRESCALER
 */
#define SET_APB1_CLOCK_PRESCALER    ABP1_CLK_DIVIDED_BY_2

/*
 * @ref APB2_CLOCK_PRESCALER
 */
#define SET_APB2_CLOCK_PRESCALER    ABP1_CLK_NOT_DIVIDED

/*
 * @ref ADC_Prescalers
 */
#define SET_ADC_PRESCALER           ADC_CLK_DIVIDED_BY_2

/*
 *  @ref USB_PRESCALERS
 */
#define SET_USB_PRESCALER           USB_CLK_NOT_DIVIDED

/*
* @ref MCU_CLOCK_OUTPUT
* clock ouput source
*/
#define SET_MCU_CLK_OUTPUT_SRC          MCO_SYS_CLK_SELECTED

#endif /* MCAL_RCC_RCC_CONFIG_H_ */
