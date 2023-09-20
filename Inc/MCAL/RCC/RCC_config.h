/*
 * RCC_config.h
 *
 *  Created on: Sep 17, 2023
 *      Author: amrmo
 */

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_
#include "RCC_interface.h"
/*
 * @ref SYSTEM_CLOCK_SOURCES
 */
#define SET_SYSTEM_CLOCK_SOURCE     HIGH_INTERNAL_OSC

/*
 * @ref PLL_SOURCES
*/
#define PLL_SOURCE                  PLL_HSI

/*
 * @ref PLL_MULTI_VALUES
 */
#define PLL_MULTIPLICATION_VALUE    PLL_MULTIPLICATION_2

/*
* @ref CLOCK_SECURITY_SYSTEM
*/
#define SET_CLOCK_SECURITY_SYSTEM   CLK_SECURITY_ENABLE
/*
 * @ref AHB_CLOCK_PRESCALER
 */
#define SET_AHB_CLOCK_PRESCALER     AHB_CLK_DIVIDED_BY_2

/*
 * @ref APB1_CLOCK_PRESCALER
 */
#define SET_APB1_CLOCK_PRESCALER    ABP1_CLK_DIVIDED_BY_2

/*
 * @ref APB2_CLOCK_PRESCALER
 */
#define SET_APB2_CLOCK_PRESCALER    ABP2_CLK_DIVIDED_BY_2

/*
 * @ref ADC_Prescalers
 */
#define SET_ADC_PRESCALER           ABP1_CLK_DIVIDED_BY_2

/*
 *  @ref USB_PRESCALERS
 */
#define SET_USB_PRESCALER           USB_CLK_NOT_DIVIDED

/*
* @ref MCU_CLOCK_OUTPUT
* clock ouput source
*/
#define SET_MCU_CLK_OUTPUT_SRC          MCO_NO_CLK_OUTPUT

#endif /* MCAL_RCC_RCC_CONFIG_H_ */
