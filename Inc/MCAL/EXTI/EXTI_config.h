/**
 * @file EXTI_config.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the essential configurations
 *        needed for EXTI initialization & control.
 * @version 0.1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_
#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/NVIC/NVIC_interface.h"

/**
 * @brief  use this to detect how many External interrupts are enabled initially
 * @ref ENABELED_INTERRUPTS 
 */
#define ENABLED_EXIT_NUM    2

/**
 * @brief this struct is used to configure the External interrupts
 * @param EXIT_id
 *        this field refers to the external interrupt id
 * @param portId
 *        this field refers to the port id, External interrupt x
 *        (EXTI)can be mapped to GPIOAx, GPIOBx, GPIOCx, GPIODx, GPIOEx
 * @param IRQ_number
 *         this field refers to the interrupt number
 * @ref EXTERNAL_INTERRUPTS_CONFIG
 */
typedef struct ST_EXTI_config
{
    uint8_t EXTI_id; /* External Interrupt id */
    uint8_t portId; /* FOR Port mapping */
    uint8_t IRQ_number; /* for NVIC */
}ST_EXTI_config_t;

/**
 * @brief this struct is used to configure the External interrupts
 * @param EXTI_config
 *        this field refers to the external interrupt configuration
 *         possible values are: @ref EXTERNAL_INTERRUPTS
 * @param edgeTrigger
 */
typedef struct ST_EXTI
{
    ST_EXTI_config_t EXTI_config; /* for EXTI configuration */
    uint8_t edgeTrigger; /* for edge trigger */
}ST_EXTI_t;

#endif