/*
 * RCC_private.h
 *
 *  Created on: Sep 17, 2023
 *      Author: amrmo
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_
#include "../../LIB/std_types.h"
// Reset and Clock Control
#define RCC_BASE 0x40021000UL

/*
 * RCC Register definition structure
 */
typedef struct
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
} ST_RCC_Regs;

/*
 * RCC Clock Types
 */

#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2
#define RCC_HSE_BYPASS 5

/*
 * CLOCK SECURITY SYSTEM
 */
#define CSS_ENABLE 1
#define CSS_DISABLE 0

/*
 * PLL Multiplication Values
 */
#define PLL_2 0
#define PLL_3 1
#define PLL_4 2
#define PLL_5 3
#define PLL_6 4
#define PLL_7 5
#define PLL_8 6
#define PLL_9 7
#define PLL_10 8
#define PLL_11 9
#define PLL_12 10
#define PLL_13 11
#define PLL_14 12
#define PLL_15 13
#define PLL_16 14

/*
 * PLL_SOURCES
 */
#define PLL_HSI 0
#define PLL_HSE 1
#define PLL_HSE_DIV2 3
#define PLL_DISABLED 111

/*
 * PLL BITS
 */
#define RCC_CR_PLLON 24
#define RCC_CR_PLLRDY 25
#define RCC_CFGR_PLLMUL 18
#define RCC_CFGR_PLLSRC 16
#define RCC_CFGR_PLLSRC 16
#define RCC_CFGR_PLLXTPRE 17

/**
 * MCO_CLOCK_SOURCES
 */
#define MCO_NO_CLK 0
#define MCO_SYS_CLK 4
#define MCO_HSI_CLK 5
#define MCO_HSE_CLK 6
#define MCO_PLLDIV2_CLK 7

/*
 * AHB prescalers
 */
#define _NOT_DIVIVED_ 0
#define SYSCLK_2 8
#define SYSCLK_4 9
#define SYSCLK_8 10
#define SYSCLK_16 11
#define SYSCLK_64 12
#define SYSCLK_128 13
#define SYSCLK_256 14
#define SYSCLK_512 15

/*
 * APB1/2 prescalers
 */
#define HCLK_2 4
#define HCLK_4 5
#define HCLK_8 6
#define HCLK_16 7

/*
* ADC Prescalers
*/
#define PCLK2_2	0
#define PCLK2_4	1
#define PCLK2_6	2
#define PCLK2_8	3
/*
 *	USB Prescalers
 */
#define USB_DIVBY_1_5 0
#define USB_NOT_DIVIDED 1
/*
 * Peripherals IDs
 */
#define _APB1_ID_ 0
#define _APB2_ID_ 1
#define _AHB_ID_ 2

#define _ALL_PERIPHERALS_ 200

#define IO_A_ID 2
#define IO_B_ID 3
#define IO_C_ID 4
#define IO_D_ID 5
#define IO_E_ID 6
#define IO_F_ID 7
#define IO_G_ID 8

#define _AFIO_ID_ 0

#define _ADC1_ID_ 9
#define _ADC2_ID_ 10
#define _ADC3_ID_ 15

#define _TMR1_ID_ 11
#define _TMR2_ID_ 0
#define _TMR3_ID_ 1
#define _TMR4_ID_ 2
#define _TMR5_ID_ 3
#define _TMR6_ID_ 4
#define _TMR7_ID_ 5
#define _TMR8_ID_ 13
#define _TMR9_ID_ 19
#define _TMR10_ID_ 20
#define _TMR11_ID_ 21
#define _TMR12_ID_ 6
#define _TMR13_ID_ 7
#define _TMR14_ID_ 8

#define _SPI_1_ID_ 12
#define _SPI_2_ID_ 14
#define _SPI_3_ID_ 15

#define _UART_1_ID_ 14
#define _UART_2_ID_ 17
#define _UART_3_ID_ 18
#define _UART_4_ID_ 19
#define _UART_5_ID_ 20

#define _I2C_1_ID_ 21
#define _I2C_2_ID_ 22

#define _CAN_ID_ 25

#define _USB_ID_ 23

#define _DAC_ID_ 29

#define _PWR_ID_ 28

#define _BACKUP_ID_ 27

#define _WWDG_ID_ 11

#define _SDIO_ID_ 10

#define _FSMC_ID_ 8

#define _CRC_ID_ 6

#define _FLITF_ID_ 4

#define _DMA_1_ID_ 0
#define _DMA_2_ID_ 1

#define _SRAM_ID_ 2

/*
 * RCC Instants
 */
#define RCC_Regs ((volatile ST_RCC_Regs *)RCC_BASE)
#define AHBENR_RESET_VALUE 0x00000014
#define APB1ENR_RESET_VALUE 0x00000000
#define APB2ENR_RESET_VALUE 0x00000000
#define AHBENR_ALL_VALUE 0x00000557
#define APB1ENR_ALL_VALUE 0x3AFEC9FF
#define APB2ENR_ALL_VALUE 0x0038fffD
#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
