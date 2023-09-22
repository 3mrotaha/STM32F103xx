#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_
#include "../../LIB/std_types.h"

// port ids
#define _GPIO_PORTA_ 0
#define _GPIO_PORTB_ 1
#define _GPIO_PORTC_ 2
#define _GPIO_PORTD_ 3
#define _GPIO_PORTE_ 4

// pin ids
#define _GPIO_PIN_0_ 0
#define _GPIO_PIN_1_ 1
#define _GPIO_PIN_2_ 2
#define _GPIO_PIN_3_ 3
#define _GPIO_PIN_4_ 4
#define _GPIO_PIN_5_ 5
#define _GPIO_PIN_6_ 6
#define _GPIO_PIN_7_ 7
#define _GPIO_PIN_8_ 8
#define _GPIO_PIN_9_ 9
#define _GPIO_PIN_10_ 10
#define _GPIO_PIN_11_ 11
#define _GPIO_PIN_12_ 12
#define _GPIO_PIN_13_ 13
#define _GPIO_PIN_14_ 14
#define _GPIO_PIN_15_ 15

// gpio pin MODE
#define _GPIO_INPUT_ 0
#define _GPIO_OUTPUT_2MHZ_ 2
#define _GPIO_OUTPUT_10MHZ_ 1
#define _GPIO_OUTPUT_50MHZ_ 3
// gpio pin CONFIGURATION
// INPUT CONFIGURATION
#define _GPIO_INPUT_ANALOG_ 0
#define _GPIO_INPUT_FLOAT_ 1
#define _GPIO_INPUT_PULLUP_DOWN_ 2
// OUTPUT CONFIGURATION
#define _GPIO_OUTPUT_PUSHPULL_ 0
#define _GPIO_OUTPUT_OPENDRAIN_ 1
#define _GPIO_ALT_OUTPUT_PUSHPULL_ 2
#define _GPIO_ALT_OUTPUT_OPENDRAIN_ 3

// PORT STATE
#define _ENABLE_PORT_   1
#define _DISABLE_PORT_  0

/*
 * LOCKING
 */
#define _LOCKED_ 1
#define _UNLOCKED_ 0

/*
 * port values & pin connectivity
 */
#define _HIGH_ 1
#define _LOW_ 0
#define _GPIO_INPUT_PULLUP_ 1
#define _GPIO_INPUT_PULLDOWN_ 0

/*
 * GPIO Configuration Registers
 */
typedef struct
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
} ST_GPIO_Regs;

// GPIOx Registers Base Addresses
#define GPIOA_BASE 0x40010800UL
#define GPIOB_BASE 0x40010C00UL
#define GPIOC_BASE 0x40011000UL
#define GPIOD_BASE 0x40011400UL
#define GPIOE_BASE 0x40011800UL
// GPIO Instants
#define GPIOA_Regs ((volatile ST_GPIO_Regs *)GPIOA_BASE)
#define GPIOB_Regs ((volatile ST_GPIO_Regs *)GPIOB_BASE)
#define GPIOC_Regs ((volatile ST_GPIO_Regs *)GPIOC_BASE)
#define GPIOD_Regs ((volatile ST_GPIO_Regs *)GPIOD_BASE)
#define GPIOE_Regs ((volatile ST_GPIO_Regs *)GPIOE_BASE)

#define _CONCAT_H_(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) 0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0
#define _CONCAT_(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) _CONCAT_H_(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)

#define _CR_BITS_H_(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) ((b0 | (b1 << 2)) | ((b2 | (b3 << 2)) << 4) | ((b4 | (b5 << 2)) << 8) | ((b6 | (b7 << 2)) << 12) | ((b8 | (b9 << 2)) << 16) | ((b10 | (b11 << 2)) << 20) | ((b12 | (b13 << 2)) << 24) | ((b14 | (b15 << 2)) << 28))
#define _CR_BITS_(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) _CR_BITS_H_(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)

#endif