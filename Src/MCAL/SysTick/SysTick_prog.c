/*
 * SysTick_prog.c
 *
 *  Created on: Oct 4, 2023
 *      Author: amrmo
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/Math.h"
#include "../../../Inc/MCAL/RCC/RCC_interface.h"
#include "../../../Inc/MCAL/SysTick/SysTick_private.h"
#include "../../../Inc/MCAL/SysTick/SysTick_config.h"

void SysTick_vidDelayMs(uint32_t Copy_u32ms){
    // initialize system tick
    SET_BIT(SysTick_Regs->CTRL, 2); //clock source selection AHB
    CLEAR_BIT(SysTick_Regs->CTRL, 1); // inbterrupt disable
    uint32_t sysClk;
    RCC_enuGetSysClk(&sysClk);
    f32_t ovfTime = (((f32_t)0x00FFFFFF)/((f32_t)sysClk/1000.0));
    f32_t ovfNum = Copy_u32ms / ovfTime;
    uint32_t ovfPreload = 0x00FFFFFF * (ovfNum - (uint32_t) ovfNum);
    uint32_t ovfNum_int = (uint32_t) ovfNum;
    
    if(ovfPreload == 0){
        SysTick_Regs->VAL = 0;
        SysTick_Regs->LOAD = 0x00FFFFFF;
    }else{
        SysTick_Regs->VAL = 0;
        SysTick_Regs->LOAD = ovfPreload;
        ovfNum_int = (uint32_t) ovfNum + 1;
    }

    SET_BIT(SysTick_Regs->CTRL, 0); // enable systick
    while(ovfNum_int != 0){
        if(GET_BIT(SysTick_Regs->CTRL, 16)){
            ovfNum_int--;
            CLEAR_BIT(SysTick_Regs->CTRL, 16);
            SysTick_Regs->VAL = 0;
            SysTick_Regs->LOAD = 0x00FFFFFF;
        }
    }
}
