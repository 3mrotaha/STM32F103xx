/**
 * @file RCC_interface.h
 * @author Amr M. Taha (amr.taha1261@gmail.com)
 * @brief this file contains the RCC APIs used
 *        by the user during the application.
 * @version 1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/Error_States.h"
#include "RCC_private.h"

/*
 * @ref SYSTEM_CLOCK_SOURCES
 * use these definitions to set the system clock source
 * 
 * HIGH_EXTERNAL_OSC -> High Speed External Oscillator
 * HIGH_EXTERNAL_BYPASS_OSC -> High Speed External Oscillator with Bypass
 * HIGH_INTERNAL_OSC -> High Speed Internal Oscillator
 * PLL_INTERNAL_OSC -> PLL with High Speed Internal Oscillator
 * PLL_EXTERNAL_OSC -> PLL with High Speed External Oscillator
 */
#define HIGH_EXTERNAL_OSC               RCC_HSE
#define HIGH_EXTERNAL_BYPASS_OSC        RCC_HSE_BYPASS
#define HIGH_INTERNAL_OSC               RCC_HSI
#define PLL_CLK                         RCC_PLL

/*
* @ref CLOCK_SECURITY_SYSTEM
*/
#define CLK_SECURITY_ENABLE     CSS_ENABLE
#define CLK_SECURITY_DISABLE    CSS_DISABLE

/*
 * @ref PLL_MULTI_VALUES
 * use these definitions to set the PLL multiplication value
 * 
 */
#define PLL_MULTIPLICATION_2            PLL_2
#define PLL_MULTIPLICATION_3            PLL_3
#define PLL_MULTIPLICATION_4            PLL_4
#define PLL_MULTIPLICATION_5            PLL_5
#define PLL_MULTIPLICATION_6            PLL_6
#define PLL_MULTIPLICATION_7            PLL_7
#define PLL_MULTIPLICATION_8            PLL_8
#define PLL_MULTIPLICATION_9            PLL_9
#define PLL_MULTIPLICATION_10           PLL_10
#define PLL_MULTIPLICATION_11           PLL_11
#define PLL_MULTIPLICATION_12           PLL_12
#define PLL_MULTIPLICATION_13           PLL_13
#define PLL_MULTIPLICATION_14           PLL_14
#define PLL_MULTIPLICATION_15           PLL_15
#define PLL_MULTIPLICATION_16           PLL_16

/*
 * @ref PLL_SOURCES
*/
#define PLL_HIGH_INTERNAL_OSC           PLL_HSI
#define PLL_HIGH_EXTERNAL_OSC           PLL_HSE
#define PLL_HIGH_EXTERNAL_DIV2_OSC      PLL_HSE_DIV2
#define PLL_NOT_ENABLED                 PLL_DISABLED

/* 
 *  @ref MCU_CLOCK_OUTPUT
 * this definitions are used to set the clock output on
 * the MCO pin.
 */
#define MCO_SYS_CLK_SELECTED            MCO_SYS_CLK
#define MCO_HSI_CLK_SELECTED            MCO_HSI_CLK
#define MCO_HSE_CLK_SELECTED            MCO_HSE_CLK
#define MCO_NO_CLK_OUTPUT               MCO_NO_CLK
#define MCO_PLL_DIV_2_CLK               MCO_PLLDIV2_CLK
/*
 *  @ref USB_PRESCALERS
 */
#define USB_CLK_DIV_BY_1_5              USB_DIVBY_1_5
#define USB_CLK_NOT_DIVIDED             USB_NOT_DIVIDED

/*
 * @ref ADC_Prescalers
 */
#define ADC_CLK_DIVIDED_BY_2            PCLK2_2
#define ADC_CLK_DIVIDED_BY_4            PCLK2_4
#define ADC_CLK_DIVIDED_BY_6            PCLK2_6
#define ADC_CLK_DIVIDED_BY_8            PCLK2_8

/*
 * @ref ABP1_Prescalers 
 */
#define ABP1_CLK_NOT_DIVIDED            _NOT_DIVIVED_
#define ABP1_CLK_DIVIDED_BY_2           HCLK_2
#define ABP1_CLK_DIVIDED_BY_4           HCLK_4
#define ABP1_CLK_DIVIDED_BY_8           HCLK_8
#define ABP1_CLK_DIVIDED_BY_16          HCLK_16

/*
 * @ref ABP2_Prescalers 
 */
#define ABP2_CLK_NOT_DIVIDED            _NOT_DIVIVED_
#define ABP2_CLK_DIVIDED_BY_2           HCLK_2
#define ABP2_CLK_DIVIDED_BY_4           HCLK_4
#define ABP2_CLK_DIVIDED_BY_8           HCLK_8
#define ABP2_CLK_DIVIDED_BY_16          HCLK_16

/*
 * @ref AHB_Prescalers 
 */
#define AHB_CLK_NOT_DIVIDED                 _NOT_DIVIVED_
#define AHB_CLK_DIVIDED_BY_2                SYSCLK_2
#define AHB_CLK_DIVIDED_BY_4                SYSCLK_4
#define AHB_CLK_DIVIDED_BY_8                SYSCLK_8
#define AHB_CLK_DIVIDED_BY_16               SYSCLK_16
#define AHB_CLK_DIVIDED_BY_64               SYSCLK_64
#define AHB_CLK_DIVIDED_BY_128              SYSCLK_128
#define AHB_CLK_DIVIDED_BY_256              SYSCLK_256
#define AHB_CLK_DIVIDED_BY_512              SYSCLK_512

/*
* @ref Peripheral IDs
* used in case of reset and clock enable/disable
*/
// BUS IDs
#define APB_1_ID                            _APB1_ID_
#define APB_2_ID                            _APB2_ID_
#define AHB_ID                              _AHB_ID_
// USE THIS TO SELECT ALL Peripherals on a specific bus
#define ALL_PERIPHERALS                     _ALL_PERIPHERALS_
// GPIOs
#define IO_PORTA_ID                         _IO_A_ID_
#define IO_PORTB_ID                         _IO_B_ID_
#define IO_PORTC_ID                         _IO_C_ID_
#define IO_PORTD_ID                         _IO_D_ID_
#define IO_PORTE_ID                         _IO_E_ID_
#define IO_PORTF_ID                         _IO_F_ID_
#define IO_PORTG_ID                         _IO_G_ID_
// AFIO
#define AFIO_ID                             _AFIO_ID_
// ADCs
#define ADC_1_ID                            _ADC1_ID_
#define ADC_2_ID                            _ADC2_ID_
#define ADC_3_ID                            _ADC3_ID_
// TIMERs   
#define TIMER_1_ID                          _TMR1_ID_
#define TIMER_2_ID                          _TMR2_ID_
#define TIMER_3_ID                          _TMR3_ID_
#define TIMER_4_ID                          _TMR4_ID_
#define TIMER_5_ID                          _TMR5_ID_
#define TIMER_6_ID                          _TMR6_ID_
#define TIMER_7_ID                          _TMR7_ID_
#define TIMER_8_ID                          _TMR8_ID_
#define TIMER_9_ID                          _TMR9_ID_
#define TIMER_10_ID                         _TMR10_ID_
#define TIMER_11_ID                         _TMR11_ID_
#define TIMER_12_ID                         _TMR12_ID_
#define TIMER_13_ID                         _TMR13_ID_
#define TIMER_14_ID                         _TMR14_ID_
// SPIs
#define SPI_1_ID                            _SPI_1_ID_
#define SPI_2_ID                            _SPI_2_ID_
#define SPI_3_ID                            _SPI_3_ID_
// UARTs
#define UART_1_ID                           _UART_1_ID_
#define UART_2_ID                           _UART_2_ID_
#define UART_3_ID                           _UART_3_ID_
#define UART_4_ID                           _UART_4_ID_
#define UART_5_ID                           _UART_5_ID_
// I2Cs
#define I2C_1_ID                            _I2C_1_ID_
#define I2C_2_ID                            _I2C_2_ID_
// CAN
#define CAN_ID                              _CAN_ID_
// USB
#define USB_ID                              _USB_ID_
// DAC
#define DAC_ID                              _DAC_ID_
// POWER INTERFACE & BACKUP INTERFACE
#define PWR_ID                              _PWR_ID_
#define BACKUP_ID                           _BACKUP_ID_
// WINDOW WATCHDOG
#define WWDOG_ID                            _WWDG_ID_
// SDIO
#define SDIO_ID                             _SDIO_ID_
// FSMC
#define FSMC_ID                             _FSMC_ID_
// CRC
#define CRC_ID                              _CRC_ID_
// FLITF
#define FLITF_ID                          _FLITF_ID_
// DMA
#define DMA_1_ID                          _DMA_1_ID_
#define DMA_2_ID                          _DMA_2_ID_
// SRAM
#define SRAM_ID                           _SRAM_ID_

/***************************************************
 * Name: RCC_vidInit
 * Params: void
 * Returns: void
 * Functionality: Initialize the System Clocks
 * Precondition: set the difinition values in the
 *               RCC_config.h file.
 * Postcondition: None
 ***************************************************/
void RCC_vidInit(void);

/***************************************************
* @name   - 
* @param  -
* @return -
* @brief  -
* @pre    -
* @post   -
***************************************************/
ErrorStates_t RCC_enuEnablePeripheralClock(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID);

/***************************************************
* @name   - 
* @param  -
* @return -
* @brief  -
* @pre    -
* @post   -
***************************************************/
ErrorStates_t RCC_enuDisablePeripheralClock(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID);

/***************************************************
* @name   - 
* @param  -
* @return -
* @brief  -
* @pre    -
* @post   -
***************************************************/
ErrorStates_t RCC_enuResetPeripheral(uint8_t Copy_u8BusID, uint8_t Copy_u8PeripheralID);

#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
