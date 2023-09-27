/**
 * @file AFIO_config.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the essential configuration
 *        used by the user to initialize the AFIO driver.
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _AFIO_CONFIG_
#define _AFIO_CONFIG_

/**
* @ref DEBUGGING_MODES
*/
#define SET_DEBUGGING_MODE

/** 
 *  @ref CAN_PROTOCOL_MAPPING_STATE 
 */
#define CAN1_RX_MAPPING_STATE
#define CAN1_TX_MAPPING_STATE

/**
 *  @ref ADC_MAPPING_STATE 
 */
#define ADC1_ETRGINJ_REMAP
#define ADC1_ETRGREG_REMAP

#define ADC2_ETRGINJ_REMAP
#define ADC2_ETRGREG_REMAP

/**
 * @ref TIMERS_REMAPPING_STATE 
 */
// later

#endif /* _AFIO_CONFIG_ */