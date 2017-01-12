/*
 * This file is part of the unicore-mx project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NRF52_MEMORYMAP_H
#define NRF52_MEMORYMAP_H

#include <unicore-mx/nrf/common/memorymap_51_52.h>

#define FLASH_BASE			(0x00000000)
#define CODE_RAM_BASE			(0x800000)

#define PPBE_BASE			(PPB_BASE + 0x40000)

#define ETM_BASE			(PPBE_BASE + 0x1000)
#define EXT_PPB_BASE			(PPBE_BASE + 0x2000)

#define ROM_TABLE			(PPB_BASE + 0xff0000)

#define SRAM_BASE			(0x20000000)

/* NRF52 specific peripherals */
#define BPROT_BASE			(APB_BASE + 0x0000)

#define UARTE0_BASE			(APB_BASE + 0x2000)

#define SPIM0_BASE			(APB_BASE + 0x3000)
#define SPIS0_BASE			(APB_BASE + 0x3000)
#define TWIM0_BASE			(APB_BASE + 0x3000)
#define TWIS0_BASE			(APB_BASE + 0x3000)

#define SPIM1_BASE			(APB_BASE + 0x4000)
#define SPIS1_BASE			(APB_BASE + 0x4000)
#define TWIS1_BASE			(APB_BASE + 0x4000)
#define TWIM1_BASE			(APB_BASE + 0x4000)

#define NFCT_BASE			(APB_BASE + 0x5000)

#define SAADC_BASE			(APB_BASE + 0x7000)

#define COMP_BASE			(APB_BASE + 0x13000)

#define EGU0_BASE			(APB_BASE + SWI0_BASE)

#define EGU1_BASE			(APB_BASE + SWI1_BASE)

#define EGU2_BASE			(APB_BASE + SWI2_BASE)

#define EGU3_BASE			(APB_BASE + SWI3_BASE)

#define EGU4_BASE			(APB_BASE + SWI4_BASE)

#define EGU5_BASE			(APB_BASE + SWI5_BASE)

#define TIMER3_BASE			(APB_BASE + 0x1a000)

#define TIMER4_BASE			(APB_BASE + 0x1b000)

#define PWM0_BASE			(APB_BASE + 0x1c000)

#define PDM_BASE			(APB_BASE + 0x1d000)

#define MWU_BASE			(APB_BASE + 0x20000)

#define PWM1_BASE			(APB_BASE + 0x21000)

#define PWM2_BASE			(APB_BASE + 0x22000)

#define SPIS2_BASE			(APB_BASE + 0x23000)

#define SPIM2_BASE			(APB_BASE + 0x23000)

#define I2S_BASE			(APB_BASE + 0x25000)

#define FPU_BASE			(APB_BASE + 0x26000)

/* This is the redesigned, nrf51 incompatible GPIO peripheral  */
#define P0_BASE			(AHB_BASE)
#define GPIO0_BASE		(AHB_BASE)

#endif  /* NRF52_MEMORYMAP_H */
