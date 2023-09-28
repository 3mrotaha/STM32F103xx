/**
 * @file NVIC_private.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the private API's
 *        for implementer.
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H
#include "../../LIB/STM32F103xx.h"
#include "../../LIB/std_types.h"

#define NVIC_BASE (CORTEX_M3_INT_PERIPHERALS_BASE + 0xE100)
#define SCB_AIRCR *((volatile uint32_t*)(CORTEX_M3_INT_PERIPHERALS_BASE + 0xED00 + 0x0C))
#define _PERIORITY_REGISTERS_NUM_ 68
#define _NVIC_PRIO_BITS_           4
// NVIC registers
typedef struct ST_NVIC_Regs{
    uint32_t ISER0; 
    uint32_t ISER1;
    uint32_t ISER2;
    uint32_t __RESERVED0__[29];
    uint32_t ICER0;
    uint32_t ICER1;
    uint32_t ICER2;
    uint32_t __RESERVED1__[29];
    uint32_t ISPR0;
    uint32_t ISPR1;
    uint32_t ISPR2;
    uint32_t __RESERVED2__[29];
    uint32_t ICPR0;
    uint32_t ICPR1;
    uint32_t ICPR2;
    uint32_t __RESERVED3__[29];
    uint32_t IABR0;
    uint32_t IABR1;
    uint32_t IABR2;
    uint32_t __RESERVED4__[61];
    uint8_t IPRx[_PERIORITY_REGISTERS_NUM_];
}ST_NVIC_Regs_t;

// NVIC instant 
#define NVIC_Regs   ((volatile ST_NVIC_Regs_t*) NVIC_BASE)

// INTERRUPTS NUMBERS
#define _INT_NUM_0_ 0
#define _INT_NUM_1_ 1
#define _INT_NUM_2_ 2
#define _INT_NUM_3_ 3
#define _INT_NUM_4_ 4
#define _INT_NUM_5_ 5
#define _INT_NUM_6_ 6
#define _INT_NUM_7_ 7
#define _INT_NUM_8_ 8
#define _INT_NUM_9_ 9
#define _INT_NUM_10_ 10
#define _INT_NUM_11_ 11
#define _INT_NUM_12_ 12
#define _INT_NUM_13_ 13
#define _INT_NUM_14_ 14
#define _INT_NUM_15_ 15
#define _INT_NUM_16_ 16
#define _INT_NUM_17_ 17
#define _INT_NUM_18_ 18
#define _INT_NUM_19_ 19
#define _INT_NUM_20_ 20
#define _INT_NUM_21_ 21
#define _INT_NUM_22_ 22
#define _INT_NUM_23_ 23
#define _INT_NUM_24_ 24
#define _INT_NUM_25_ 25
#define _INT_NUM_26_ 26
#define _INT_NUM_27_ 27
#define _INT_NUM_28_ 28
#define _INT_NUM_29_ 29
#define _INT_NUM_30_ 30
#define _INT_NUM_31_ 31
#define _INT_NUM_32_ 32
#define _INT_NUM_33_ 33
#define _INT_NUM_34_ 34
#define _INT_NUM_35_ 35
#define _INT_NUM_36_ 36
#define _INT_NUM_37_ 37
#define _INT_NUM_38_ 38
#define _INT_NUM_39_ 39
#define _INT_NUM_40_ 40
#define _INT_NUM_41_ 41
#define _INT_NUM_42_ 42
#define _INT_NUM_43_ 43
#define _INT_NUM_44_ 44
#define _INT_NUM_45_ 45
#define _INT_NUM_46_ 46
#define _INT_NUM_47_ 47
#define _INT_NUM_48_ 48
#define _INT_NUM_49_ 49
#define _INT_NUM_50_ 50
#define _INT_NUM_51_ 51
#define _INT_NUM_52_ 52
#define _INT_NUM_53_ 53
#define _INT_NUM_54_ 54
#define _INT_NUM_55_ 55
#define _INT_NUM_56_ 56
#define _INT_NUM_57_ 57
#define _INT_NUM_58_ 58
#define _INT_NUM_59_ 59
#define _INT_NUM_60_ 60
#define _INT_NUM_61_ 61
#define _INT_NUM_62_ 62
#define _INT_NUM_63_ 63
#define _INT_NUM_64_ 64
#define _INT_NUM_65_ 65
#define _INT_NUM_66_ 66
#define _INT_NUM_67_ 67

#define _NVIC_PR_G0_    0
#define _NVIC_PR_G1_    1
#define _NVIC_PR_G2_    2
#define _NVIC_PR_G3_    3
#define _NVIC_PR_G4_    4

#define _NVIC_P_PREE_L0_ 0
#define _NVIC_P_PREE_L1_ 1
#define _NVIC_P_PREE_L2_ 2
#define _NVIC_P_PREE_L3_ 3
#define _NVIC_P_PREE_L4_ 4
#define _NVIC_P_PREE_L5_ 5
#define _NVIC_P_PREE_L6_ 6
#define _NVIC_P_PREE_L7_ 7
#define _NVIC_P_PREE_L8_ 8
#define _NVIC_P_PREE_L9_ 9
#define _NVIC_P_PREE_L10_ 10
#define _NVIC_P_PREE_L11_ 11
#define _NVIC_P_PREE_L12_ 12
#define _NVIC_P_PREE_L13_ 13
#define _NVIC_P_PREE_L14_ 14
#define _NVIC_P_PREE_L15_ 15

#define _NVIC_P_SUB_L0_ 0
#define _NVIC_P_SUB_L1_ 1
#define _NVIC_P_SUB_L2_ 2
#define _NVIC_P_SUB_L3_ 3
#define _NVIC_P_SUB_L4_ 4
#define _NVIC_P_SUB_L5_ 5
#define _NVIC_P_SUB_L6_ 6
#define _NVIC_P_SUB_L7_ 7
#define _NVIC_P_SUB_L8_ 8
#define _NVIC_P_SUB_L9_ 9
#define _NVIC_P_SUB_L10_ 10
#define _NVIC_P_SUB_L11_ 11
#define _NVIC_P_SUB_L12_ 12
#define _NVIC_P_SUB_L13_ 13
#define _NVIC_P_SUB_L14_ 14
#define _NVIC_P_SUB_L15_ 15

#define _INT_ENABLE_    1
#define _INT_DISABLE_   0

#endif /* _NVIC_PRIVATE_H */
