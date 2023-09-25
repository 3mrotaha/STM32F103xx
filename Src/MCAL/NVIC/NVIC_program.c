/**
 * @file NVIC_program.c
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the essential functions of NVIC
 *        Cortex-M3 internal peripheral.
 * @version 1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/stm32f103xx.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/NVIC/NVIC_private.h"
#include "../../../Inc/MCAL/NVIC/NVIC_config.h"

void NVIC_vidInit(void){
    /** set the enabled interrupts in ISER0 **/
    // first 16 interrupts
    NVIC_Regs->ISER0 = _CONCAT_(
        SET_INT_0, SET_INT_1, SET_INT_2, SET_INT_3, SET_INT_4, SET_INT_5, SET_INT_6, SET_INT_7,
        SET_INT_8, SET_INT_9, SET_INT_10, SET_INT_11, SET_INT_12, SET_INT_13, SET_INT_14, SET_INT_15
    );
    // second 16 interrupts
    NVIC_Regs->ISER0 = _CONCAT_(SET_INT_16, SET_INT_17, SET_INT_18, SET_INT_19, SET_INT_20, SET_INT_21, SET_INT_22, SET_INT_23,
        SET_INT_24, SET_INT_25, SET_INT_26, SET_INT_27, SET_INT_28, SET_INT_29, SET_INT_30, SET_INT_31
    ) << 16;

    /** set the enabled interrupts in ISER1 **/
    // first 16 interrupts
    NVIC_Regs->ISER1 = _CONCAT_(
        SET_INT_32, SET_INT_33, SET_INT_34, SET_INT_35, SET_INT_36, SET_INT_37, SET_INT_38, SET_INT_39,
        SET_INT_40, SET_INT_41, SET_INT_42, SET_INT_43, SET_INT_44, SET_INT_45, SET_INT_46, SET_INT_47
    );
    // second 16 interrupts
    NVIC_Regs->ISER1 = _CONCAT_(SET_INT_48, SET_INT_49, SET_INT_50, SET_INT_51, SET_INT_52, SET_INT_53, SET_INT_54, SET_INT_55,
        SET_INT_56, SET_INT_57, SET_INT_58, SET_INT_59, SET_INT_60, SET_INT_61, SET_INT_62, SET_INT_63
    ) << 16;

    /** set the enabled interrupts in ISER2 **/
    NVIC_Regs->ISER2 = (SET_INT_64 << 0) | (SET_INT_65 << 1) | (SET_INT_66 << 2) | (SET_INT_67 << 3);
}

ErrorStates_t NVIC_enuEnableInterrupt(uint8_t Copy_u8IntNum){
    if(Copy_u8IntNum >= _INT_NUM_0_ && Copy_u8IntNum <= _INT_NUM_67_){
        // check the number if in ISER0, ISER1 or ISER2 range
        if(Copy_u8IntNum <= _INT_NUM_31_ && Copy_u8IntNum >= _INT_NUM_0_){
            SET_BIT(NVIC_Regs->ISER0, (Copy_u8IntNum)); /*set the interrupt enable*/
        }else if(Copy_u8IntNum <= _INT_NUM_63_ && Copy_u8IntNum >= _INT_NUM_32_){
            SET_BIT(NVIC_Regs->ISER1, (Copy_u8IntNum - 32)); /*set the interrupt enable*/
        }else if(Copy_u8IntNum <= _INT_NUM_67_ && Copy_u8IntNum >= _INT_NUM_64_){
            SET_BIT(NVIC_Regs->ISER2, (Copy_u8IntNum - 64)); /*set the interrupt enable*/
        }else{
            return ES_NOK; /*something went wrong*/
        }
        return ES_OK; /*everything is ok*/
    }else{
        return ES_OUT_OF_RANGE; /*the number is out of range*/
    }
}

ErrorStates_t NVIC_enuDisableInterrupt(uint8_t Copy_u8IntNum){
    if(Copy_u8IntNum >= _INT_NUM_0_ && Copy_u8IntNum <= _INT_NUM_67_){
        // check the number if in ICER0, ICER1 or ICER2 range
        if(Copy_u8IntNum <= _INT_NUM_31_ && Copy_u8IntNum >= _INT_NUM_0_){
            SET_BIT(NVIC_Regs->ICER0, (Copy_u8IntNum)); /*Write 1 to clear*/
        }else if(Copy_u8IntNum <= _INT_NUM_63_ && Copy_u8IntNum >= _INT_NUM_32_){
            SET_BIT(NVIC_Regs->ICER1, (Copy_u8IntNum - 32)); /*Write 1 to clear*/
        }else if(Copy_u8IntNum <= _INT_NUM_67_ && Copy_u8IntNum >= _INT_NUM_64_){
            SET_BIT(NVIC_Regs->ICER2, (Copy_u8IntNum - 64)); /*Write 1 to clear*/
        }else{
            return ES_NOK; /*something went wrong*/
        }
        return ES_OK; /*everything is ok*/
    }else{
        return ES_OUT_OF_RANGE; /*the number is out of range*/
    }
}

ErrorStates_t NVIC_enuSetInterruptPending(uint8_t Copy_u8IntNum){
    if(Copy_u8IntNum >= _INT_NUM_0_ && Copy_u8IntNum <= _INT_NUM_67_){
        // check the number if in ISPR0, ISPR1 or ISPR2 range
        if(Copy_u8IntNum <= _INT_NUM_31_ && Copy_u8IntNum >= _INT_NUM_0_){
            SET_BIT(NVIC_Regs->ISPR0, (Copy_u8IntNum)); /*set the interrupt pending*/
        }else if(Copy_u8IntNum <= _INT_NUM_63_ && Copy_u8IntNum >= _INT_NUM_32_){
            SET_BIT(NVIC_Regs->ISPR1, (Copy_u8IntNum - 32)); /*set the interrupt pending*/
        }else if(Copy_u8IntNum <= _INT_NUM_67_ && Copy_u8IntNum >= _INT_NUM_64_){
            SET_BIT(NVIC_Regs->ISPR2, (Copy_u8IntNum - 64)); /*set the interrupt pending*/
        }else{
            return ES_NOK; /*something went wrong*/
        }
        return ES_OK; /*everything is ok*/
    }else{
        return ES_OUT_OF_RANGE; /*the number is out of range*/
    }
}

ErrorStates_t NVIC_enuClearInterruptPending(uint8_t Copy_u8IntNum){
    if(Copy_u8IntNum >= _INT_NUM_0_ && Copy_u8IntNum <= _INT_NUM_67_){
        // check the number if in ICPR0, ICPR1 or ICPR2 range
        if(Copy_u8IntNum <= _INT_NUM_31_ && Copy_u8IntNum >= _INT_NUM_0_){
            SET_BIT(NVIC_Regs->ICPR0, (Copy_u8IntNum)); /*Write 1 to clear*/
        }else if(Copy_u8IntNum <= _INT_NUM_63_ && Copy_u8IntNum >= _INT_NUM_32_){
            SET_BIT(NVIC_Regs->ICPR1, (Copy_u8IntNum - 32)); /*Write 1 to clear*/
        }else if(Copy_u8IntNum <= _INT_NUM_67_ && Copy_u8IntNum >= _INT_NUM_64_){
            SET_BIT(NVIC_Regs->ICPR2, (Copy_u8IntNum - 64)); /*Write 1 to clear*/
        }else{
            return ES_NOK; /*something went wrong*/
        }
        return ES_OK; /*everything is ok*/
    }else{
        return ES_OUT_OF_RANGE; /*the number is out of range*/
    }
}

uint8_t NVIC_enuGetActiveFlag(uint8_t Copy_u8IntNum){
    if(Copy_u8IntNum >= _INT_NUM_0_ && Copy_u8IntNum <= _INT_NUM_67_){
        // check the number if in IABR0, IABR1 or IABR2 range
        if(Copy_u8IntNum <= _INT_NUM_31_ && Copy_u8IntNum >= _INT_NUM_0_){
            return GET_BIT(NVIC_Regs->IABR0, (Copy_u8IntNum)); /*get the interrupt active flag*/
        }else if(Copy_u8IntNum <= _INT_NUM_63_ && Copy_u8IntNum >= _INT_NUM_32_){
            return GET_BIT(NVIC_Regs->IABR1, (Copy_u8IntNum - 32)); /*get the interrupt active flag*/
        }else if(Copy_u8IntNum <= _INT_NUM_67_ && Copy_u8IntNum >= _INT_NUM_64_){
            return GET_BIT(NVIC_Regs->IABR2, (Copy_u8IntNum - 64)); /*get the interrupt active flag*/
        }else{
            return ES_NOK; /*something went wrong*/
        }
    }else{
        return ES_OUT_OF_RANGE; /*the number is out of range*/
    }
}

ErrorStates_t NVIC_enuSetInterruptPriority(uint8_t Copy_u8IntNum, uint8_t Copy_u8GroupID, uint8_t Copy_u8PreempPrio, uint8_t Copy_u8SubPrio){
    // check boundaries
    if((Copy_u8IntNum >= _INT_NUM_0_ && Copy_u8IntNum <= _INT_NUM_67_) 
        && (Copy_u8GroupID >= _NVIC_PR_G1_ && Copy_u8GroupID <= _NVIC_PR_G5_)
        && (Copy_u8PreempPrio >= _NVIC_P_PREE_L1_ && Copy_u8PreempPrio <= _NVIC_P_PREE_L4_)
        && (Copy_u8SubPrio >= _NVIC_P_SUB_L1_ && Copy_u8SubPrio <= _NVIC_P_SUB_L4_)){
        // as the ipr supports byte access, there is no need to clear it first
        NVIC_Regs->IPRx[Copy_u8IntNum] = (Copy_u8PreempPrio << (8 - _NVIC_PRIO_BITS_ + Copy_u8GroupID)) | (Copy_u8SubPrio << (8 - _NVIC_PRIO_BITS_));
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t NVIC_enuGetInterruptPriority(uint8_t Copy_u8IntNum, uint8_t Copy_u8GroupID, uint8_t *Copy_pu8PreempPrio, uint8_t *Copy_pu8SubPrio){
    if(Copy_pu8PreempPrio != NULL && Copy_pu8SubPrio != NULL){
        if((Copy_u8IntNum >= _INT_NUM_0_ && Copy_u8IntNum <= _INT_NUM_67_)
           && (Copy_u8GroupID >= _NVIC_PR_G1_ && Copy_u8GroupID <= _NVIC_PR_G5_)){
            // read the ipr register corresponding to the interrupt number
            *Copy_pu8SubPrio = (NVIC_Regs->IPRx[Copy_u8IntNum] >> (8 - _NVIC_PRIO_BITS_));            
            // get the preemption priority regarding the group id
            *Copy_pu8PreempPrio = (*Copy_pu8SubPrio >> (_NVIC_PRIO_BITS_ - Copy_u8GroupID));
            // get the sub priority regarding the group id
            *Copy_pu8SubPrio = (*Copy_pu8SubPrio & ((uint8_t)0x0f >> Copy_u8GroupID));
            return ES_OK; // everything is ok
        }else{
            return ES_OUT_OF_RANGE; // interrupt num or group id is out of range
        }
    }else{
        return ES_NULL_POINTER; // null pointer passed
    }
}

