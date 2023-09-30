/**
 * @file EXTI_interface.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the User definitions
 *        & APIs that're used during the application
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
/**
 * @ref EDGE_TRIGGERS
 * @brief use these configurations to set the edge trigger for
 * a specific interrupt source.
 */
#define EXTI_TRIG_RISING        _EXTI_TFE_
#define EXTI_TRIG_FALLING       _EXTI_TRE_
#define EXTI_TRIG_ON_CHANGE     _EXTI_TCH_

/**
 * @ref EXTERNAL_INT_ID
 * @brief use this to refer to a specific external interrupt.
 */
#define EXTI_LINE0 _EXTI0_
#define EXTI_LINE1 _EXTI1_
#define EXTI_LINE2 _EXTI2_
#define EXTI_LINE3 _EXTI3_
#define EXTI_LINE4 _EXTI4_
#define EXTI_LINE5 _EXTI5_
#define EXTI_LINE6 _EXTI6_
#define EXTI_LINE7 _EXTI7_
#define EXTI_LINE8 _EXTI8_
#define EXTI_LINE9 _EXTI9_
#define EXTI_LINE10 _EXTI10_
#define EXTI_LINE11 _EXTI11_
#define EXTI_LINE12 _EXTI12_
#define EXTI_LINE13 _EXTI13_
#define EXTI_LINE14 _EXTI14_
#define EXTI_LINE15 _EXTI15_

/* External interrupt LINE 0 Port Mapping */
#define EXTI_LINE0PA0 _EXTI_LINE0PA0_
#define EXTI_LINE0PB0 _EXTI_LINE0PB0_
#define EXTI_LINE0PC0 _EXTI_LINE0PC0_
#define EXTI_LINE0PD0 _EXTI_LINE0PD0_
#define EXTI_LINE0PE0 _EXTI_LINE0PE0_

/* External interrupt LINE 1 Port Mapping */
#define EXTI_LINE1PA1 _EXTI_LINE1PA1_
#define EXTI_LINE1PB1 _EXTI_LINE1PB1_
#define EXTI_LINE1PC1 _EXTI_LINE1PC1_
#define EXTI_LINE1PD1 _EXTI_LINE1PD1_
#define EXTI_LINE1PE1 _EXTI_LINE1PE1_

/* External interrupt LINE 2 Port Mapping */
#define EXTI_LINE2PA2 _EXTI_LINE2PA2_
#define EXTI_LINE2PB2 _EXTI_LINE2PB2_
#define EXTI_LINE2PC2 _EXTI_LINE2PC2_
#define EXTI_LINE2PD2 _EXTI_LINE2PD2_
#define EXTI_LINE2PE2 _EXTI_LINE2PE2_

/* External interrupt LINE 3 Port Mapping */
#define EXTI_LINE3PA3 _EXTI_LINE3PA3_
#define EXTI_LINE3PB3 _EXTI_LINE3PB3_
#define EXTI_LINE3PC3 _EXTI_LINE3PC3_
#define EXTI_LINE3PD3 _EXTI_LINE3PD3_
#define EXTI_LINE3PE3 _EXTI_LINE3PE3_

/* External interrupt LINE 4 Port Mapping */
#define EXTI_LINE4PA4 _EXTI_LINE4PA4_
#define EXTI_LINE4PB4 _EXTI_LINE4PB4_
#define EXTI_LINE4PC4 _EXTI_LINE4PC4_
#define EXTI_LINE4PD4 _EXTI_LINE4PD4_
#define EXTI_LINE4PE4 _EXTI_LINE4PE4_

/* External interrupt LINE 5 Port Mapping */
#define EXTI_LINE5PA5 _EXTI_LINE5PA5_
#define EXTI_LINE5PB5 _EXTI_LINE5PB5_
#define EXTI_LINE5PC5 _EXTI_LINE5PC5_
#define EXTI_LINE5PD5 _EXTI_LINE5PD5_
#define EXTI_LINE5PE5 _EXTI_LINE5PE5_

/* External interrupt LINE 6 Port Mapping */
#define EXTI_LINE6PA6 _EXTI_LINE6PA6_
#define EXTI_LINE6PB6 _EXTI_LINE6PB6_
#define EXTI_LINE6PC6 _EXTI_LINE6PC6_
#define EXTI_LINE6PD6 _EXTI_LINE6PD6_
#define EXTI_LINE6PE6 _EXTI_LINE6PE6_

/* External interrupt LINE 7 Port Mapping */
#define EXTI_LINE7PA7 _EXTI_LINE7PA7_
#define EXTI_LINE7PB7 _EXTI_LINE7PB7_
#define EXTI_LINE7PC7 _EXTI_LINE7PC7_
#define EXTI_LINE7PD7 _EXTI_LINE7PD7_
#define EXTI_LINE7PE7 _EXTI_LINE7PE7_

/* External interrupt LINE 8 Port Mapping */
#define EXTI_LINE8PA8 _EXTI_LINE8PA8_
#define EXTI_LINE8PB8 _EXTI_LINE8PB8_
#define EXTI_LINE8PC8 _EXTI_LINE8PC8_
#define EXTI_LINE8PD8 _EXTI_LINE8PD8_
#define EXTI_LINE8PE8 _EXTI_LINE8PE8_

/* External interrupt LINE 9 Port Mapping */
#define EXTI_LINE9PA9 _EXTI_LINE9PA9_
#define EXTI_LINE9PB9 _EXTI_LINE9PB9_
#define EXTI_LINE9PC9 _EXTI_LINE9PC9_
#define EXTI_LINE9PD9 _EXTI_LINE9PD9_
#define EXTI_LINE9PE9 _EXTI_LINE9PE9_

/* External interrupt LINE 10 Port Mapping */
#define EXTI_LINE10PA10 _EXTI_LINE10PA10_
#define EXTI_LINE10PB10 _EXTI_LINE10PB10_
#define EXTI_LINE10PC10 _EXTI_LINE10PC10_
#define EXTI_LINE10PD10 _EXTI_LINE10PD10_
#define EXTI_LINE10PE10 _EXTI_LINE10PE10_

/* External interrupt LINE 11 Port Mapping */
#define EXTI_LINE11PA11 _EXTI_LINE11PA11_
#define EXTI_LINE11PB11 _EXTI_LINE11PB11_
#define EXTI_LINE11PC11 _EXTI_LINE11PC11_
#define EXTI_LINE11PD11 _EXTI_LINE11PD11_
#define EXTI_LINE11PE11 _EXTI_LINE11PE11_

/* External interrupt LINE 12 Port Mapping */
#define EXTI_LINE12PA12 _EXTI_LINE12PA12_
#define EXTI_LINE12PB12 _EXTI_LINE12PB12_
#define EXTI_LINE12PC12 _EXTI_LINE12PC12_
#define EXTI_LINE12PD12 _EXTI_LINE12PD12_
#define EXTI_LINE12PE12 _EXTI_LINE12PE12_

/* External interrupt LINE 13 Port Mapping */
#define EXTI_LINE13PA13 _EXTI_LINE13PA13_
#define EXTI_LINE13PB13 _EXTI_LINE13PB13_
#define EXTI_LINE13PC13 _EXTI_LINE13PC13_
#define EXTI_LINE13PD13 _EXTI_LINE13PD13_
#define EXTI_LINE13PE13 _EXTI_LINE13PE13_

/* External interrupt LINE 14 Port Mapping */
#define EXTI_LINE14PA14 _EXTI_LINE14PA14_
#define EXTI_LINE14PB14 _EXTI_LINE14PB14_
#define EXTI_LINE14PC14 _EXTI_LINE14PC14_
#define EXTI_LINE14PD14 _EXTI_LINE14PD14_
#define EXTI_LINE14PE14 _EXTI_LINE14PE14_

/* External interrupt LINE 15 Port Mapping */
#define EXTI_LINE15PA15 _EXTI_LINE15PA15_
#define EXTI_LINE15PB15 _EXTI_LINE15PB15_
#define EXTI_LINE15PC15 _EXTI_LINE15PC15_
#define EXTI_LINE15PD15 _EXTI_LINE15PD15_
#define EXTI_LINE15PE15 _EXTI_LINE15PE15_


/**
 * @name EXTI_enuInit
 * @param void
 * @brief initializing the external interrupt peripheral
 *        enabling the selected ones and setting their
 *        configurations
 * @return - ES_OK (ErrorStates_t):
 *           if the interrupts are initialized successfully
 *         - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the enabled interrupts number out of 
 *           range @ref ENABELED_INTERRUPTS
 * @pre - setting the number of enabled interrupts in 
 *        the configuration file @ref ENABELED_INTERRUPTS 
 *      - setting the interrupt handlers for the enabled 
 *        external interrupts.
 * @post none
 */
ErrorStates_t EXTI_enuInit(void);

/**
 * @name EXTI_enuExtiSetConfiguration
 * @brief use this function to set the configuration for a specific external
 *        interrupt line and enables its mask.
 *        possible values for the configuration are:
 *        @ref EXTERNAL_INT_ID for External interrupt lines
 *        @ref EDGE_TRIGGERS for edge trigger configuration
 *        @example
 *         EXTI_enuExtiSetConfiguration(&(ST_EXTI_t) {
 *          .EXTI_u8ExIntID = EXTI_LINE0,
 *          .EXTI_u8EdgeID = EXTI_TRIG_RISING
 *        }); // this will set the external interrupt line 0 to be triggered on rising edge
 * @param Copy_pstExtiConfig 
 * @return - ES_OK (ErrorStates_t)
 *           if the configuration is set successfully.
 *         - ES_NULL_POINTER (ErrorStates_t)
 *           if the configuration pointer is NULL.
 *         - ES_OUT_OF_RANGE (ErrorStates_t)
 *           if the selected external interrupt source is out of range. 
 * @pre none
 * @post none
 */
ErrorStates_t EXTI_enuExtiSetConfiguration(ST_EXTI_t* Copy_pstExtiConfig);

/**
 * @name EXTI_enuEnableExtiMask
 * @brief this function is used to enable the interrupt mask for a specific
 * @param Copy_u8ExIntID (uint8_t)
 *        this parameter is used to select the external interrupt source.
 * @return - ES_OK (ErrorStates_t)
 *           if the interrupt mask is enabled successfully.
 *         - ES_OUT_OF_RANGE (ErrorStates_t)
 *           if the selected external interrupt source is out of range.
 * @pre External interrupt source is configured in initialization function @ref EXTI_enuInit.
 *      or during run time using @ref EXTI_enuExtiSetConfiguration.
 * @post none.
 */
ErrorStates_t EXTI_enuEnableExtiMask(uint8_t Copy_u8ExIntID);

/**
 * @name EXTI_enuDisableExtiMask
 * @brief this function is used to disable the interrupt mask for a specific
 * @param Copy_u8ExIntID (uint8_t)
 *        this parameter is used to select the external interrupt source.
 * @return - ES_OK (ErrorStates_t)
 *           if the interrupt mask is disabled successfully.
 *         - ES_OUT_OF_RANGE (ErrorStates_t)
 *           if the selected external interrupt source is out of range.
 */
ErrorStates_t EXTI_enuDisableExtiMask(uint8_t Copy_u8ExIntID);

/**
 * @brief this function is used to generate a software interrupt for a specific
 *        external interrupt source.
 * @param Copy_u8ExIntID (uint8_t)
 *        this parameter is used to select the external interrupt source.
 * @return - ES_OK (ErrorStates_t)
 *           if the interrupt mask is disabled successfully.
 *         - ES_OUT_OF_RANGE (ErrorStates_t)
 *           if the selected external interrupt source is out of range.
 */
ErrorStates_t EXTI_enuGenerateSoftwareEvent(uint8_t Copy_u8ExIntID);

/**
 * @name EXTI_enuSetEdgeTrigger
 * @brief this function is used to set the edge trigger for a specific
 *        external interrupt line.
 * @param Copy_u8ExIntID (uint8_t)
 *        this parameter is used to select the external interrupt source.
 * @param Copy_u8EdgeID (uint8_t)
 *        this parameter is used to select the edge trigger for the selected
 * @return - ES_OK (ErrorStates_t)
 *           if the interrupt mask is disabled successfully.
 *         - ES_OUT_OF_RANGE (ErrorStates_t)
 *           if the selected external interrupt source is out of range,
 *           or the selected edge trigger is out of range.
 *         - ES_NOK (ErrorStates_t)
 *           if the interrupt mask is not disabled successfully.
 */
ErrorStates_t EXTI_enuSetEdgeTrigger(uint8_t Copy_u8ExIntID, uint8_t Copy_u8EdgeID);

/**
 * @name EXTI_enuSetInterruptHandler
 * @brief this function is used to set the interrupt handler for a specific
 *        external interrupt source.
 * @param Copy_u8ExIntID (uint8_t)
 *        this parameter is used to select the external interrupt source.
 * @param Copy_pvHandler (void (*)(void*))
 *        this parameter is used to set the interrupt handler for the selected
 * @param Copy_pvParameter (void*)
 *        this parameter is used to set the parameters for a specific interrupt
 *        handler.
 * @return - ES_OK (ErrorStates_t)
 *           if the interrupt handler is set successfully.
 *         - ES_OUT_OF_RANGE (ErrorStates_t)
 *           if the selected external interrupt source is out of range.
 *         - ES_NULL_POINTER (ErrorStates_t)
 *          if the interrupt handler is NULL.
 * @pre enabling the interrupt source in the configuration file @ref ENABELED_INTERRUPTS.
 * @post none.
 */
ErrorStates_t EXTI_enuSetInterruptHandler(uint8_t Copy_u8ExIntID, void (*Copy_pvHandler)(void*), void* Copy_pvParameter);

#endif