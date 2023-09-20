/*
 * STM32F103xx.h
 *
 *  Created on: Sep 17, 2023
 *      Author: amrmo
 */

#ifndef STM32F103XX_H_
#define STM32F103XX_H_

/*
 * Base addresses for SoC modules
 */
// Memories
#define FLASH_BASE		0x08000000UL
#define SYS_MEM_BASE	0x1FFFF000UL
#define SRAM_BASE		0x20000000UL
// Peripherals
#define MCU_PERIPHERALS_BASE	0x40000000UL
// CORTEX-M3 INTERNAL PERIPHERALS
#define CORTEX_M3_INT_PERIPHERALS_BASE	0xE0000000UL


#endif /* STM32F103XX_H_ */
