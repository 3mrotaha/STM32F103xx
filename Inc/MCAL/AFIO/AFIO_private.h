/**
 * @file AFIO_private.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contians the private APIs for
 *        the implementer.
 * @version 1
 * @date 2023-09-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _AFIO_PRIVATE_H_
#define _AFIO_PRIVATE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/STM32F103xx.h"

// AFIO base address.
#define AFIO_BASE   0x40010000
// AFIO Registers
typedef struct ST_AFIO_Regs{
    uint32_t EVCR;
    uint32_t MAPR1;
    uint32_t EXTICR[4];
    uint32_t __RESERVED_;
    uint32_t MAPR2;
}ST_AFIO_Regs_t;

// AFIO instants
#define AFIO_Regs   ((volatile ST_AFIO_Regs_t*) AFIO_BASE)

#endif