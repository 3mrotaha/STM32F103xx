/*
 * SysTick_private.h
 *
 *  Created on: Oct 4, 2023
 *      Author: amrmo
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

#include "../../LIB/std_types.h"
#include "../../LIB/STM32F103xx.h"



#define SYSTICK_BASE	(CORTEX_M3_INT_PERIPHERALS_BASE + 0xE010)

typedef struct STK_Regs{
	uint32_t CTRL;
	uint32_t LOAD;
	uint32_t VAL;
	uint32_t CALIB;
}ST_STK_Regs_t;

#define SysTick_Regs ((volatile ST_STK_Regs_t*) SYSTICK_BASE)

#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
