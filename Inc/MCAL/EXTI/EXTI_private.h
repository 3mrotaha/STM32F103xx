/**
 * @file EXTI_private.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the private API's
 *        for implementer.
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#include "../../LIB/std_types.h"
#include "../../LIB/STM32F103xx.h"

// External interrupt base adress on APB2
#define EXTI_BASE 0x40010400

// External interrupt registers
typedef struct ST_EXTI_Regs{
    uint32_t IMR;
    uint32_t EMR;
    uint32_t RTSR;
    uint32_t FTSR;
    uint32_t SWIER;
    uint32_t PR;
}ST_EXTI_Regs_t;

// External interrupt instants
#define EXTI_Regs   ((volatile ST_EXTI_Regs_t*) EXTI_BASE)
// external interrupt numbers
#define _EXTI0_ 0
#define _EXTI1_ 1
#define _EXTI2_ 2
#define _EXTI3_ 3
#define _EXTI4_ 4
#define _EXTI5_ 5
#define _EXTI6_ 6
#define _EXTI7_ 7
#define _EXTI8_ 8
#define _EXTI9_ 9
#define _EXTI10_ 10
#define _EXTI11_ 11
#define _EXTI12_ 12
#define _EXTI13_ 13
#define _EXTI14_ 14
#define _EXTI15_ 15

/* External interrupt LINE 0 Port Mapping */
#define _EXTI_LINE0PA0_ ((ST_EXTI_config_t) {EXTI_LINE0, GPIO_PORTA, INT_NUM_6})
#define _EXTI_LINE0PB0_ ((ST_EXTI_config_t) {EXTI_LINE0, GPIO_PORTB, INT_NUM_6})
#define _EXTI_LINE0PC0_ ((ST_EXTI_config_t) {EXTI_LINE0, GPIO_PORTC, INT_NUM_6})
#define _EXTI_LINE0PD0_ ((ST_EXTI_config_t) {EXTI_LINE0, GPIO_PORTD, INT_NUM_6})
#define _EXTI_LINE0PE0_ ((ST_EXTI_config_t) {EXTI_LINE0, GPIO_PORTE, INT_NUM_6})

/* External interrupt LINE 1 Port Mapping */
#define _EXTI_LINE1PA1_ ((ST_EXTI_config_t) {EXTI_LINE1, GPIO_PORTA, INT_NUM_7})
#define _EXTI_LINE1PB1_ ((ST_EXTI_config_t) {EXTI_LINE1, GPIO_PORTB, INT_NUM_7})
#define _EXTI_LINE1PC1_ ((ST_EXTI_config_t) {EXTI_LINE1, GPIO_PORTC, INT_NUM_7})
#define _EXTI_LINE1PD1_ ((ST_EXTI_config_t) {EXTI_LINE1, GPIO_PORTD, INT_NUM_7})
#define _EXTI_LINE1PE1_ ((ST_EXTI_config_t) {EXTI_LINE1, GPIO_PORTE, INT_NUM_7})

/* External interrupt LINE 2 Port Mapping */
#define _EXTI_LINE2PA2_ ((ST_EXTI_config_t) {EXTI_LINE2, GPIO_PORTA, INT_NUM_8})
#define _EXTI_LINE2PB2_ ((ST_EXTI_config_t) {EXTI_LINE2, GPIO_PORTB, INT_NUM_8})
#define _EXTI_LINE2PC2_ ((ST_EXTI_config_t) {EXTI_LINE2, GPIO_PORTC, INT_NUM_8})
#define _EXTI_LINE2PD2_ ((ST_EXTI_config_t) {EXTI_LINE2, GPIO_PORTD, INT_NUM_8})
#define _EXTI_LINE2PE2_ ((ST_EXTI_config_t) {EXTI_LINE2, GPIO_PORTE, INT_NUM_8})

/* External interrupt LINE 3 Port Mapping */
#define _EXTI_LINE3PA3_ ((ST_EXTI_config_t) {EXTI_LINE3, GPIO_PORTA, INT_NUM_9})
#define _EXTI_LINE3PB3_ ((ST_EXTI_config_t) {EXTI_LINE3, GPIO_PORTB, INT_NUM_9})
#define _EXTI_LINE3PC3_ ((ST_EXTI_config_t) {EXTI_LINE3, GPIO_PORTC, INT_NUM_9})
#define _EXTI_LINE3PD3_ ((ST_EXTI_config_t) {EXTI_LINE3, GPIO_PORTD, INT_NUM_9})
#define _EXTI_LINE3PE3_ ((ST_EXTI_config_t) {EXTI_LINE3, GPIO_PORTE, INT_NUM_9})

/* External interrupt LINE 4 Port Mapping */
#define _EXTI_LINE4PA4_ ((ST_EXTI_config_t) {EXTI_LINE4, GPIO_PORTA, INT_NUM_10})
#define _EXTI_LINE4PB4_ ((ST_EXTI_config_t) {EXTI_LINE4, GPIO_PORTB, INT_NUM_10})
#define _EXTI_LINE4PC4_ ((ST_EXTI_config_t) {EXTI_LINE4, GPIO_PORTC, INT_NUM_10})
#define _EXTI_LINE4PD4_ ((ST_EXTI_config_t) {EXTI_LINE4, GPIO_PORTD, INT_NUM_10})
#define _EXTI_LINE4PE4_ ((ST_EXTI_config_t) {EXTI_LINE4, GPIO_PORTE, INT_NUM_10})

/* External interrupt LINE 5 Port Mapping */
#define _EXTI_LINE5PA5_ ((ST_EXTI_config_t) {EXTI_LINE5, GPIO_PORTA, INT_NUM_23})
#define _EXTI_LINE5PB5_ ((ST_EXTI_config_t) {EXTI_LINE5, GPIO_PORTB, INT_NUM_23})
#define _EXTI_LINE5PC5_ ((ST_EXTI_config_t) {EXTI_LINE5, GPIO_PORTC, INT_NUM_23})
#define _EXTI_LINE5PD5_ ((ST_EXTI_config_t) {EXTI_LINE5, GPIO_PORTD, INT_NUM_23})
#define _EXTI_LINE5PE5_ ((ST_EXTI_config_t) {EXTI_LINE5, GPIO_PORTE, INT_NUM_23})

/* External interrupt LINE 6 Port Mapping */
#define _EXTI_LINE6PA6_ ((ST_EXTI_config_t) {EXTI_LINE6, GPIO_PORTA, INT_NUM_23})
#define _EXTI_LINE6PB6_ ((ST_EXTI_config_t) {EXTI_LINE6, GPIO_PORTB, INT_NUM_23})
#define _EXTI_LINE6PC6_ ((ST_EXTI_config_t) {EXTI_LINE6, GPIO_PORTC, INT_NUM_23})
#define _EXTI_LINE6PD6_ ((ST_EXTI_config_t) {EXTI_LINE6, GPIO_PORTD, INT_NUM_23})
#define _EXTI_LINE6PE6_ ((ST_EXTI_config_t) {EXTI_LINE6, GPIO_PORTE, INT_NUM_23})

/* External interrupt LINE 7 Port Mapping */
#define _EXTI_LINE7PA7_ ((ST_EXTI_config_t) {EXTI_LINE7, GPIO_PORTA, INT_NUM_23})
#define _EXTI_LINE7PB7_ ((ST_EXTI_config_t) {EXTI_LINE7, GPIO_PORTB, INT_NUM_23})
#define _EXTI_LINE7PC7_ ((ST_EXTI_config_t) {EXTI_LINE7, GPIO_PORTC, INT_NUM_23})
#define _EXTI_LINE7PD7_ ((ST_EXTI_config_t) {EXTI_LINE7, GPIO_PORTD, INT_NUM_23})
#define _EXTI_LINE7PE7_ ((ST_EXTI_config_t) {EXTI_LINE7, GPIO_PORTE, INT_NUM_23})

/* External interrupt LINE 8 Port Mapping */
#define _EXTI_LINE8PA8_ ((ST_EXTI_config_t) {EXTI_LINE8, GPIO_PORTA, INT_NUM_23})
#define _EXTI_LINE8PB8_ ((ST_EXTI_config_t) {EXTI_LINE8, GPIO_PORTB, INT_NUM_23})
#define _EXTI_LINE8PC8_ ((ST_EXTI_config_t) {EXTI_LINE8, GPIO_PORTC, INT_NUM_23})
#define _EXTI_LINE8PD8_ ((ST_EXTI_config_t) {EXTI_LINE8, GPIO_PORTD, INT_NUM_23})
#define _EXTI_LINE8PE8_ ((ST_EXTI_config_t) {EXTI_LINE8, GPIO_PORTE, INT_NUM_23})

/* External interrupt LINE 9 Port Mapping */
#define _EXTI_LINE9PA9_ ((ST_EXTI_config_t) {EXTI_LINE9, GPIO_PORTA, INT_NUM_23})
#define _EXTI_LINE9PB9_ ((ST_EXTI_config_t) {EXTI_LINE9, GPIO_PORTB, INT_NUM_23})
#define _EXTI_LINE9PC9_ ((ST_EXTI_config_t) {EXTI_LINE9, GPIO_PORTC, INT_NUM_23})
#define _EXTI_LINE9PD9_ ((ST_EXTI_config_t) {EXTI_LINE9, GPIO_PORTD, INT_NUM_23})
#define _EXTI_LINE9PE9_ ((ST_EXTI_config_t) {EXTI_LINE9, GPIO_PORTE, INT_NUM_23})

/* External interrupt LINE 10 Port Mapping */
#define _EXTI_LINE10PA10_ ((ST_EXTI_config_t) {EXTI_LINE10, GPIO_PORTA, INT_NUM_40})
#define _EXTI_LINE10PB10_ ((ST_EXTI_config_t) {EXTI_LINE10, GPIO_PORTB, INT_NUM_40})
#define _EXTI_LINE10PC10_ ((ST_EXTI_config_t) {EXTI_LINE10, GPIO_PORTC, INT_NUM_40})
#define _EXTI_LINE10PD10_ ((ST_EXTI_config_t) {EXTI_LINE10, GPIO_PORTD, INT_NUM_40})
#define _EXTI_LINE10PE10_ ((ST_EXTI_config_t) {EXTI_LINE10, GPIO_PORTE, INT_NUM_40})

/* External interrupt LINE 11 Port Mapping */
#define _EXTI_LINE11PA11_ ((ST_EXTI_config_t) {EXTI_LINE11, GPIO_PORTA, INT_NUM_40})
#define _EXTI_LINE11PB11_ ((ST_EXTI_config_t) {EXTI_LINE11, GPIO_PORTB, INT_NUM_40})
#define _EXTI_LINE11PC11_ ((ST_EXTI_config_t) {EXTI_LINE11, GPIO_PORTC, INT_NUM_40})
#define _EXTI_LINE11PD11_ ((ST_EXTI_config_t) {EXTI_LINE11, GPIO_PORTD, INT_NUM_40})
#define _EXTI_LINE11PE11_ ((ST_EXTI_config_t) {EXTI_LINE11, GPIO_PORTE, INT_NUM_40})

/* External interrupt LINE 12 Port Mapping */
#define _EXTI_LINE12PA12_ ((ST_EXTI_config_t) {EXTI_LINE12, GPIO_PORTA, INT_NUM_40})
#define _EXTI_LINE12PB12_ ((ST_EXTI_config_t) {EXTI_LINE12, GPIO_PORTB, INT_NUM_40})
#define _EXTI_LINE12PC12_ ((ST_EXTI_config_t) {EXTI_LINE12, GPIO_PORTC, INT_NUM_40})
#define _EXTI_LINE12PD12_ ((ST_EXTI_config_t) {EXTI_LINE12, GPIO_PORTD, INT_NUM_40})
#define _EXTI_LINE12PE12_ ((ST_EXTI_config_t) {EXTI_LINE12, GPIO_PORTE, INT_NUM_40})

/* External interrupt LINE 13 Port Mapping */
#define _EXTI_LINE13PA13_ ((ST_EXTI_config_t) {EXTI_LINE13, GPIO_PORTA, INT_NUM_40})
#define _EXTI_LINE13PB13_ ((ST_EXTI_config_t) {EXTI_LINE13, GPIO_PORTB, INT_NUM_40})
#define _EXTI_LINE13PC13_ ((ST_EXTI_config_t) {EXTI_LINE13, GPIO_PORTC, INT_NUM_40})
#define _EXTI_LINE13PD13_ ((ST_EXTI_config_t) {EXTI_LINE13, GPIO_PORTD, INT_NUM_40})
#define _EXTI_LINE13PE13_ ((ST_EXTI_config_t) {EXTI_LINE13, GPIO_PORTE, INT_NUM_40})

/* External interrupt LINE 14 Port Mapping */
#define _EXTI_LINE14PA14_ ((ST_EXTI_config_t) {EXTI_LINE14, GPIO_PORTA, INT_NUM_40})
#define _EXTI_LINE14PB14_ ((ST_EXTI_config_t) {EXTI_LINE14, GPIO_PORTB, INT_NUM_40})
#define _EXTI_LINE14PC14_ ((ST_EXTI_config_t) {EXTI_LINE14, GPIO_PORTC, INT_NUM_40})
#define _EXTI_LINE14PD14_ ((ST_EXTI_config_t) {EXTI_LINE14, GPIO_PORTD, INT_NUM_40})
#define _EXTI_LINE14PE14_ ((ST_EXTI_config_t) {EXTI_LINE14, GPIO_PORTE, INT_NUM_40})

/* External interrupt LINE 15 Port Mapping */
#define _EXTI_LINE15PA15_ ((ST_EXTI_config_t) {EXTI_LINE15, GPIO_PORTA, INT_NUM_40})
#define _EXTI_LINE15PB15_ ((ST_EXTI_config_t) {EXTI_LINE15, GPIO_PORTB, INT_NUM_40})
#define _EXTI_LINE15PC15_ ((ST_EXTI_config_t) {EXTI_LINE15, GPIO_PORTC, INT_NUM_40})
#define _EXTI_LINE15PD15_ ((ST_EXTI_config_t) {EXTI_LINE15, GPIO_PORTD, INT_NUM_40})
#define _EXTI_LINE15PE15_ ((ST_EXTI_config_t) {EXTI_LINE15, GPIO_PORTE, INT_NUM_40})

#define MAX_INTERRUPT_NUM 16

#define _EXTI_TFE_ 0x1
#define _EXTI_TRE_ 0x2
#define _EXTI_TCH_ 0x3

#endif
