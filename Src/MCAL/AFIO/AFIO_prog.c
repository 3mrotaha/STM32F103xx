/**
 * @file AFIO_prog.c
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the implementation
 *        of the AFIO APIs
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../../Inc/LIB/std_types.h"
#include "../../../Inc/LIB/STM32F103xx.h"
#include "../../../Inc/LIB/Error_States.h"
#include "../../../Inc/LIB/Math.h"

#include "../../../Inc/MCAL/EXTI/EXTI_private.h"
#include "../../../Inc/MCAL/GPIO/GPIO_private.h"

#include "../../../Inc/MCAL/AFIO/AFIO_private.h"
#include "../../../Inc/MCAL/AFIO/AFIO_interface.h"


ErrorStates_t AFIO_enuEXTILineMap(uint8_t Copy_u8Line, uint8_t Copy_u8MappedRegister){
    if((Copy_u8Line >= _EXTI0_ && Copy_u8Line <= _EXTI15_) && (Copy_u8MappedRegister >= _GPIO_PORTA_ && Copy_u8MappedRegister <= _GPIO_PORTE_)){
        uint8_t bitOffset = (Copy_u8Line % 4) * 4; // get the bit offset.
        AFIO_Regs->EXTICR[Copy_u8Line / 4] &= ~((uint32_t)0xf << bitOffset); // clear the bits
        AFIO_Regs->EXTICR[Copy_u8Line / 4] |= (Copy_u8MappedRegister << bitOffset); // set the port bits
        return ES_OK; /* everything is ok */
    }else{
        return ES_OUT_OF_RANGE; /* parameter out of range */
    }
}