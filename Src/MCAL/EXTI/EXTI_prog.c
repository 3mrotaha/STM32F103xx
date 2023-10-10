/**
 * @file EXTI_prog.c
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the implementation
 *        for the EXTI driver functions.
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/STM32F103xx.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/RCC/RCC_interface.h"
#include "../../../Inc/MCAL/NVIC/NVIC_interface.h"
#include "../../../Inc/MCAL/AFIO/AFIO_interface.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"

#include "../../../Inc/MCAL/EXTI/EXTI_private.h"
#include "../../../Inc/MCAL/EXTI/EXTI_config.h"


extern ST_EXTI_t EXTI_ASTconfig[ENABLED_EXIT_NUM];
static void (*EXTI_InterrutpHandlers[7]) (void*) = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
static void* EXTI_IntHandlerParam[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};


ErrorStates_t EXTI_enuInit(void){    
    if(ENABLED_EXIT_NUM <= MAX_INTERRUPT_NUM){
        // initialize the enabled interrupts
        for(int Iterator = 0; Iterator < ENABLED_EXIT_NUM; Iterator++){
            // enable the port clock
            RCC_enuEnablePeripheralClock(APB_2_ID, EXTI_ASTconfig[Iterator].EXTI_config.portId);
            // set the interrupt enable in the NVIC Interrupt enable register
            NVIC_enuEnableInterrupt(EXTI_ASTconfig[Iterator].EXTI_config.IRQ_number);
            // map the external interrupt pin to the desired register
            AFIO_enuEXTILineMap(EXTI_ASTconfig[Iterator].EXTI_config.EXTI_id, EXTI_ASTconfig[Iterator].EXTI_config.portId);
            // set the corresponding pin to input float
            GPIO_enuSetPinConfiguration(EXTI_ASTconfig[Iterator].EXTI_config.portId, EXTI_ASTconfig[Iterator].EXTI_config.EXTI_id, &(GPIO_PinConfig_t) {
                .mode = GPIO_INPUT,
                .config = GPIO_INPUT_FLOAT,
                .value = _LOW_ // this value is ignored.
            });
            // set external interrupt peripheral configuration 
            // enable corresponding interrupt mask
            SET_BIT(EXTI_Regs->IMR, EXTI_ASTconfig[Iterator].EXTI_config.EXTI_id);
            // set the trigger edge (rising, falling or both)   
            /*clear bits*/         
            EXTI_Regs->RTSR &= ~(BIT_MASK << EXTI_ASTconfig[Iterator].EXTI_config.EXTI_id);
            EXTI_Regs->FTSR &= ~(BIT_MASK << EXTI_ASTconfig[Iterator].EXTI_config.EXTI_id);
            EXTI_Regs->RTSR |= (GET_BIT(EXTI_ASTconfig[Iterator].edgeTrigger, 0) << EXTI_ASTconfig[Iterator].EXTI_config.EXTI_id);
            EXTI_Regs->FTSR |= (GET_BIT(EXTI_ASTconfig[Iterator].edgeTrigger, 1) << EXTI_ASTconfig[Iterator].EXTI_config.EXTI_id);
        }
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t EXTI_enuExtiSetConfiguration(ST_EXTI_t* Copy_pstExtiConfig){
    if(Copy_pstExtiConfig != NULL){
        // enable the gpio clock if it's disabled
        RCC_enuEnablePeripheralClock(APB_2_ID, Copy_pstExtiConfig->EXTI_config.portId);
        // alternative function pin
        AFIO_enuEXTILineMap(Copy_pstExtiConfig->EXTI_config.EXTI_id, Copy_pstExtiConfig->EXTI_config.portId);
        // set the GPIOx pin to input float
        GPIO_enuSetPinConfiguration(Copy_pstExtiConfig->EXTI_config.portId, Copy_pstExtiConfig->EXTI_config.EXTI_id, &(GPIO_PinConfig_t){
            .mode = GPIO_INPUT,
            .config = GPIO_INPUT_FLOAT,
            .value = GPIO_OUTPUT_LOW // this value is ignored
        });
        // Set the trigger edge
        CLEAR_BIT(EXTI_Regs->RTSR, Copy_pstExtiConfig->EXTI_config.EXTI_id);
        CLEAR_BIT(EXTI_Regs->FTSR, Copy_pstExtiConfig->EXTI_config.EXTI_id);
        EXTI_Regs->RTSR |= (GET_BIT(Copy_pstExtiConfig->edgeTrigger, 0) << Copy_pstExtiConfig->EXTI_config.EXTI_id);
        EXTI_Regs->FTSR |= (GET_BIT(Copy_pstExtiConfig->edgeTrigger, 1) << Copy_pstExtiConfig->EXTI_config.EXTI_id);
        // set the external interrupt mask
        EXTI_Regs->IMR |= (BIT_MASK << Copy_pstExtiConfig->EXTI_config.EXTI_id);
        // set the interrupt mask
        NVIC_enuEnableInterrupt(Copy_pstExtiConfig->EXTI_config.IRQ_number);
        return ES_OK;
    }else{
        return ES_NULL_POINTER;
    }
}

ErrorStates_t EXTI_enuEnableExtiMask(uint8_t Copy_u8ExIntID){
    if(Copy_u8ExIntID >= _EXTI0_ && Copy_u8ExIntID <= _EXTI15_){
        SET_BIT(EXTI_Regs->IMR, Copy_u8ExIntID); // set the corresponding bit in the interrupt mask register
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t EXTI_enuDisableExtiMask(uint8_t Copy_u8ExIntID){
    if(Copy_u8ExIntID >= _EXTI0_ && Copy_u8ExIntID <= _EXTI15_){
        CLEAR_BIT(EXTI_Regs->IMR, Copy_u8ExIntID); // clear the corresponding bit in the interrupt mask register
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t EXTI_enuGenerateSoftwareEvent(uint8_t Copy_u8ExIntID){
    if(Copy_u8ExIntID >= _EXTI0_ && Copy_u8ExIntID <= _EXTI15_){
        SET_BIT(EXTI_Regs->SWIER, Copy_u8ExIntID); // set the corresponding bit in the software interrupt event register
        /* this bit is cleared after clearing the corresponding bit in the pending register */
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE;
    }
}

ErrorStates_t EXTI_enuSetEdgeTrigger(uint8_t Copy_u8ExIntID, uint8_t Copy_u8EdgeID){
    if((Copy_u8ExIntID >= _EXTI0_ && Copy_u8ExIntID <= _EXTI15_) 
    && (Copy_u8EdgeID >= _EXTI_TRE_ && Copy_u8EdgeID <= _EXTI_TCH_)){
        EXTI_Regs->RTSR |= (GET_BIT(Copy_u8EdgeID, 0) << Copy_u8ExIntID); /*set the rising flag*/
        EXTI_Regs->FTSR |= (GET_BIT(Copy_u8EdgeID, 1) << Copy_u8ExIntID); /*set the falling flag*/
        return ES_OK;
    }else{
        return ES_OUT_OF_RANGE; // external interrupt id or edge id out of range
    }
}

ErrorStates_t EXTI_enuSetInterruptHandler(uint8_t Copy_u8ExIntID, void (*Copy_pvHandler)(void*), void* Copy_pvParameter){
    if(Copy_pvHandler != NULL && Copy_pvParameter != NULL){
        if(Copy_u8ExIntID >= _EXTI0_ && Copy_u8ExIntID <= _EXTI15_){
            switch (Copy_u8ExIntID)
            {
                case _EXTI0_:
                case _EXTI1_:     
                case _EXTI2_:            
                case _EXTI3_:             
                case _EXTI4_:
                    EXTI_InterrutpHandlers[Copy_u8ExIntID] = Copy_pvHandler;
                    EXTI_IntHandlerParam[Copy_u8ExIntID] = Copy_pvParameter;
                    break;                
                case _EXTI5_:
                case _EXTI6_:
                case _EXTI7_:
                case _EXTI8_:
                case _EXTI9_:
                    EXTI_InterrutpHandlers[5] = Copy_pvHandler;
                    EXTI_IntHandlerParam[5] = Copy_pvParameter;
                    break;                    
                case _EXTI10_:
                case _EXTI11_:
                case _EXTI12_:
                case _EXTI13_:
                case _EXTI14_:
                case _EXTI15_:
                    EXTI_InterrutpHandlers[6] = Copy_pvHandler;
                    EXTI_IntHandlerParam[6] = Copy_pvParameter;
                    break;                
                default:
                    return ES_NOK;
            }
        }else{
            return ES_OUT_OF_RANGE;
        }
        return ES_OK;
    }else{
        return ES_NULL_POINTER;
    }
}

void EXTI0_IRQHandler(){
    if(EXTI_InterrutpHandlers[_EXTI0_] != NULL && EXTI_IntHandlerParam[_EXTI0_] != NULL)
        EXTI_InterrutpHandlers[_EXTI0_](EXTI_IntHandlerParam[_EXTI0_]);
    SET_BIT(EXTI_Regs->PR, _EXTI0_); // clear the pending bit
}

void EXTI1_IRQHandler(){
    if(EXTI_InterrutpHandlers[_EXTI1_] != NULL && EXTI_IntHandlerParam[_EXTI1_] != NULL)
        EXTI_InterrutpHandlers[_EXTI1_](EXTI_IntHandlerParam[_EXTI1_]);
    SET_BIT(EXTI_Regs->PR, _EXTI1_); // clear the pending bit
}

void EXTI2_IRQHandler(){
    if(EXTI_InterrutpHandlers[_EXTI2_] != NULL && EXTI_IntHandlerParam[_EXTI2_] != NULL)
        EXTI_InterrutpHandlers[_EXTI2_](EXTI_IntHandlerParam[_EXTI2_]);
    SET_BIT(EXTI_Regs->PR, _EXTI2_); // clear the pending bit
}

void EXTI3_IRQHandler(){
    if(EXTI_InterrutpHandlers[_EXTI3_] != NULL && EXTI_IntHandlerParam[_EXTI3_] != NULL)
        EXTI_InterrutpHandlers[_EXTI3_](EXTI_IntHandlerParam[_EXTI3_]);
    SET_BIT(EXTI_Regs->PR, _EXTI3_); // clear the pending bit
}

void EXTI4_IRQHandler(){
    if(EXTI_InterrutpHandlers[_EXTI4_] != NULL && EXTI_IntHandlerParam[_EXTI4_] != NULL)
        EXTI_InterrutpHandlers[_EXTI4_](EXTI_IntHandlerParam[_EXTI4_]);
    SET_BIT(EXTI_Regs->PR, _EXTI4_); // clear the pending bit
}

void EXTI9_5_IRQHandler(){
    if(EXTI_InterrutpHandlers[_EXTI5_] != NULL && EXTI_IntHandlerParam[_EXTI5_] != NULL)
        EXTI_InterrutpHandlers[_EXTI5_](EXTI_IntHandlerParam[_EXTI5_]);
    EXTI_Regs->PR &= ~(BIT_MASK_5 << _EXTI5_); // clear the pending bit
}

void EXTI15_10_IRQHandler(){
    if(EXTI_InterrutpHandlers[_EXTI6_] != NULL && EXTI_IntHandlerParam[_EXTI6_] != NULL)
        EXTI_InterrutpHandlers[_EXTI6_](EXTI_IntHandlerParam[_EXTI6_]);
    EXTI_Regs->PR &= ~(BIT_MASK_6 << _EXTI6_); // clear the pending bit
}
