#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"
#include "NVIC_private.h"

/**
 * @ref NVIC_INTERRUPTS_ENABLE
 *  @brief use this definitions to enable or disable the interrupts initially
 */
#define INT_ENABLE  _INT_ENABLE_
#define INT_DISABLE _INT_DISABLE_

/**
 * @ref NVIC_INTERRUPTS
 * @brief use this IDs to refer to a specific interrupt number
 * when you want to set or clear enable of an interrupt source
 */
#define INT_NUM_0   _INT_NUM_0_
#define INT_NUM_1   _INT_NUM_1_
#define INT_NUM_2   _INT_NUM_2_
#define INT_NUM_3   _INT_NUM_3_
#define INT_NUM_4   _INT_NUM_4_
#define INT_NUM_5   _INT_NUM_5_
#define INT_NUM_6   _INT_NUM_6_
#define INT_NUM_7   _INT_NUM_7_
#define INT_NUM_8   _INT_NUM_8_
#define INT_NUM_9   _INT_NUM_9_
#define INT_NUM_10  _INT_NUM_10_
#define INT_NUM_11  _INT_NUM_11_
#define INT_NUM_12  _INT_NUM_12_
#define INT_NUM_13  _INT_NUM_13_
#define INT_NUM_14  _INT_NUM_14_
#define INT_NUM_15  _INT_NUM_15_
#define INT_NUM_16  _INT_NUM_16_
#define INT_NUM_17  _INT_NUM_17_
#define INT_NUM_18  _INT_NUM_18_
#define INT_NUM_19  _INT_NUM_19_
#define INT_NUM_20  _INT_NUM_20_
#define INT_NUM_21  _INT_NUM_21_
#define INT_NUM_22  _INT_NUM_22_
#define INT_NUM_23  _INT_NUM_23_
#define INT_NUM_24  _INT_NUM_24_
#define INT_NUM_25  _INT_NUM_25_
#define INT_NUM_26  _INT_NUM_26_
#define INT_NUM_27  _INT_NUM_27_
#define INT_NUM_28  _INT_NUM_28_
#define INT_NUM_29  _INT_NUM_29_
#define INT_NUM_30  _INT_NUM_30_
#define INT_NUM_31  _INT_NUM_31_

#define INT_NUM_32  _INT_NUM_32_
#define INT_NUM_33  _INT_NUM_33_
#define INT_NUM_34  _INT_NUM_34_
#define INT_NUM_35  _INT_NUM_35_
#define INT_NUM_36  _INT_NUM_36_
#define INT_NUM_37  _INT_NUM_37_
#define INT_NUM_38  _INT_NUM_38_
#define INT_NUM_39  _INT_NUM_39_
#define INT_NUM_40  _INT_NUM_40_
#define INT_NUM_41  _INT_NUM_41_
#define INT_NUM_42  _INT_NUM_42_
#define INT_NUM_43  _INT_NUM_43_
#define INT_NUM_44  _INT_NUM_44_
#define INT_NUM_45  _INT_NUM_45_
#define INT_NUM_46  _INT_NUM_46_
#define INT_NUM_47  _INT_NUM_47_
#define INT_NUM_48  _INT_NUM_48_
#define INT_NUM_49  _INT_NUM_49_
#define INT_NUM_50  _INT_NUM_50_
#define INT_NUM_51  _INT_NUM_51_
#define INT_NUM_52  _INT_NUM_52_
#define INT_NUM_53  _INT_NUM_53_
#define INT_NUM_54  _INT_NUM_54_
#define INT_NUM_55  _INT_NUM_55_
#define INT_NUM_56  _INT_NUM_56_
#define INT_NUM_57  _INT_NUM_57_
#define INT_NUM_58  _INT_NUM_58_
#define INT_NUM_59  _INT_NUM_59_
#define INT_NUM_60  _INT_NUM_60_
#define INT_NUM_61  _INT_NUM_61_
#define INT_NUM_62  _INT_NUM_62_
#define INT_NUM_63  _INT_NUM_63_

#define INT_NUM_64  _INT_NUM_64_
#define INT_NUM_65  _INT_NUM_65_
#define INT_NUM_66  _INT_NUM_66_
#define INT_NUM_67  _INT_NUM_67_

/**
 * @ref NVIC_PRIORITY_GROUP
 * @brief use this IDs to refer to a specific priority group
 */
#define NVIC_PRIORITY_GROUP1            _NVIC_PR_G1_
#define NVIC_PRIORITY_GROUP2            _NVIC_PR_G2_
#define NVIC_PRIORITY_GROUP3            _NVIC_PR_G3_
#define NVIC_PRIORITY_GROUP4            _NVIC_PR_G4_
#define NVIC_PRIORITY_GROUP5            _NVIC_PR_G5_

/**
 * @ref NVIC_PREEMPTIVE_PRIORITY
 * @brief use this IDs to refer to a specific preemptive priority
 */
#define NVIC_PREEMPTIVE_PRIORITY_L1     _NVIC_P_PREE_L1_
#define NVIC_PREEMPTIVE_PRIORITY_L2     _NVIC_P_PREE_L2_
#define NVIC_PREEMPTIVE_PRIORITY_L3     _NVIC_P_PREE_L3_
#define NVIC_PREEMPTIVE_PRIORITY_L4     _NVIC_P_PREE_L4_

/**
 * @ref NVIC_SUB_PRIORITY
 * @brief use this IDs to refer to a specific sub priority
 */
#define NVIC_SUB_PRIORITY_L1            _NVIC_P_SUB_L1_
#define NVIC_SUB_PRIORITY_L2            _NVIC_P_SUB_L2_
#define NVIC_SUB_PRIORITY_L3            _NVIC_P_SUB_L3_
#define NVIC_SUB_PRIORITY_L4            _NVIC_P_SUB_L4_    

/***************************************************************
 * @name NVIC_vidInit
 * @param void
 * @return void
 * @brief This function is responsible for initializing NVIC
 * @pre none
 * @post none
 ***************************************************************/
void NVIC_vidInit(void);

/*****************************************************************************
 * @name NVIC_enuEnableInterrupt
 * @param Copy_u8IntNum (uint8_t)
 *        - interrupt number that should be set enable, 
 *          possible values are @ref NVIC_INTERRUPTS
 * @return - ES_OK (ErrorStates_t): 
 *           if the interrupt number is valid and the interrupt is enabled
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the interrupt number is not valid
 * @return - ES_NOK (ErrorStates_t):
 *           if the interrupt number is valid but the interrupt is not enabled
 * @brief This function is responsible for enabling a specific interrupt Source
 * @pre none
 * @post device interrupt should be enabled
 *******************************************************************************/
ErrorStates_t NVIC_enuEnableInterrupt(uint8_t Copy_u8IntNum);

/*****************************************************************************
 * @name NVIC_enuDisableInterrupt
 * @param Copy_u8IntNum (uint8_t)
 *        possible values are @ref NVIC_INTERRUPTS
 * @return - ES_OK (ErrorStates_t):
 *           if the interrupt number is valid and the interrupt is disabled
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the interrupt number is not valid
 * @return - ES_NOK (ErrorStates_t):
 *           if the interrupt number is valid but the interrupt is not disabled
 * @brief This function is responsible for disabling a specific interrupt Source
 * @pre none
 * @post device interrupt should be disabled
 *******************************************************************************/
ErrorStates_t NVIC_enuDisableInterrupt(uint8_t Copy_u8IntNum);

/*****************************************************************************
 * @name NVIC_enuSetInterruptPending
 * @param Copy_u8IntNum (uint8_t)
 *       - interrupt number that should be set pending,
 *       possible values are @ref NVIC_INTERRUPTS
 * @return - ES_OK (ErrorStates_t):
 *           if the interrupt number is valid and the interrupt is set pending
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the interrupt number is not valid
 * @return - ES_NOK (ErrorStates_t):
 *           if the interrupt number is valid but the interrupt is not set pending
 * @brief This function is responsible for setting a specific interrupt Source pending
 * @pre none
 * @post none
 *******************************************************************************/
ErrorStates_t NVIC_enuSetInterruptPending(uint8_t Copy_u8IntNum);

/*****************************************************************************
 * @name NVIC_enuClearInterruptPending
 * @param Copy_u8IntNum (uint8_t)
 *      - interrupt number that should be clear pending,
 *        possible values are @ref NVIC_INTERRUPTS
 * @return - ES_OK (ErrorStates_t):
 *           if the interrupt number is valid and the interrupt is clear pending
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the interrupt number is not valid
 * @return - ES_NOK (ErrorStates_t):
 *           if the interrupt number is valid but the interrupt is not clear pending
 * @brief This function is responsible for clearing a specific interrupt Source pending
 * @pre none
 * @post none
 *******************************************************************************/
ErrorStates_t NVIC_enuClearInterruptPending(uint8_t Copy_u8IntNum);


/*****************************************************************************
 * @name NVIC_enuGetActiveFlag
 * @param Copy_u8IntNum (uint8_t)
 *        - interrupt number that should be get active flag,
 * @return - ES_OK (ErrorStates_t):
 *           if the interrupt number is valid and the interrupt is active
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the interrupt number is not valid
 * @return - ES_NOK (ErrorStates_t):
 *           if the interrupt number is valid but the interrupt is not active
 * @brief  This function is responsible for getting a specific interrupt 
 *          Source active flag
 * @pre none
 * @post none
 *******************************************************************************/
uint8_t NVIC_enuGetActiveFlag(uint8_t Copy_u8IntNum);

/*****************************************************************************
 * @name NVIC_enuSetInterruptPriority
 * @param Copy_u8IntNum (uint8_t)
 *       - interrupt number that should be set priority,
 *         possible values are @ref NVIC_INTERRUPTS
 * @param Copy_u8GroupID (uint8_t)
 *      - the priority group that the interrupt should be set to,
 *        possible values are @ref NVIC_PRIORITY_GROUP
 * @param Copy_u8PreempPrio (uint8_t)
 *     - the preemptive priority that the interrupt should be set to,
 *       possible values are @ref NVIC_PREEMPTIVE_PRIORITY
 * @param Copy_u8SubPrio (uint8_t)
 *     - the sub priority that the interrupt should be set to,
 *       possible values are @ref NVIC_SUB_PRIORITY
 * @return - ES_OK (ErrorStates_t):
 *           if the interrupt number, priority group, preemptive priority and 
 *            sub priority are valid and the interrupt priority is set
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *           if the interrupt number, priority group, preemptive priority or 
 *           sub priority are not valid
 * @return - ES_NOK (ErrorStates_t):
 *           if the interrupt number, priority group, preemptive priority or
 *           sub priority are valid but the interrupt priority is not set
 * @brief This function is responsible for setting a specific interrupt Source priority
 *        if given a correct priority group, preemptive priority and sub priority.
 * @pre none
 * @post none
 *******************************************************************************/
ErrorStates_t NVIC_enuSetInterruptPriority(uint8_t Copy_u8IntNum, uint8_t Copy_u8GroupID, uint8_t Copy_u8PreempPrio, uint8_t Copy_u8SubPrio);

/*****************************************************************************
 * @name NVIC_enuGetInterruptPriority
 * @param Copy_u8IntNum (uint8_t)
 *        - interrupt number that should be get priority,
 *          possible values are @ref NVIC_INTERRUPTS
 * @param Copy_u8GroupID (uint8_t)
 *        - the priority group that the interrupt should be get to,
 *          possible values are @ref NVIC_PRIORITY_GROUP
 * @param Copy_pu8PreempPrio (uint8_t*)
 *        - the preemptive priority that the interrupt should be get to,
 *         possible values are @ref NVIC_PREEMPTIVE_PRIORITY
 * @param Copy_pu8SubPrio (uint8_t*)
 *        - the sub priority that the interrupt should be get to,
 *         possible values are @ref NVIC_SUB_PRIORITY
 * @return - ES_OK (ErrorStates_t):
 *          if the interrupt number and priority group are valid
 * @return - ES_OUT_OF_RANGE (ErrorStates_t):
 *         if the interrupt number or priority group are not valid.
 * @return - ES_NOK (ErrorStates_t):
 *          if the interrupt number and priority group are valid but
 *          the interrupt priority is not get.
 * @return - ES_NULL_POINTER (ErrorStates_t):
 *         if a null pointer is passed to the function.
 * @brief This function is responsible for getting a specific interrupt
 *       Source priority if given a correct priority group.
 * @pre Interrupt priority is set.
 * @post none
 *******************************************************************************/
ErrorStates_t NVIC_enuGetInterruptPriority(uint8_t Copy_u8IntNum, uint8_t Copy_u8GroupID, uint8_t *Copy_pu8PreempPrio, uint8_t *Copy_pu8SubPrio);

#endif /* NVIC_INTERFACE_H */