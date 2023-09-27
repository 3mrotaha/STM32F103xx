/**
 * @file EXTI_config.c
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the external interrupts
 *        essential configuration.
 *        these configurations are essential for the
 *        EXTI initialization
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/MCAL/EXTI/EXTI_config.h"
#include "../../../Inc/MCAL/EXTI/EXTI_interface.h"
/**
 * @brief set here the list of ENABLED_EXIT_NUM external interrupts 
 * @ref EXTERNAL_INTERRUPTS in EXTI_config.h
 */
ST_EXTI_t EXTI_ASTconfig[ENABLED_EXIT_NUM] = {
    {EXTI_LINE0PA0, EXTI_TRIG_ON_CHANGE},
    {EXTI_LINE1PA1, EXTI_TRIG_RISING}
};
