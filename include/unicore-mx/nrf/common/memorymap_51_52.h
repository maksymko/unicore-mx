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

#ifndef NRF_51_52_MEMORYMAP_H
#define NRF_51_52_MEMORYMAP_H

#include <unicore-mx/cm3/common.h>

/* Factory Information Configuration Registers */
#define FICR_BASE			(0x10000000U)

/* User Information Configuration Registers */
#define UICR_BASE			(0x10001000U)

#define APB_BASE			(0x40000000U)
#define AHB_BASE			(0x50000000U)
#define PPB_BASE			(0xE0000000U)

/* Peripherals */
#define POWER_BASE			(APB_BASE)
#define CLOCK_BASE			(APB_BASE)

#define RADIO_BASE			(APB_BASE + 0x1000)

#define SPIS1_BASE			(APB_BASE + 0x4000)

#define GPIOTE_BASE			(APB_BASE + 0x6000)

#define TIMER0_BASE			(APB_BASE + 0x8000)

#define TIMER1_BASE			(APB_BASE + 0x9000)

#define TIMER2_BASE			(APB_BASE + 0xA000)

#define RTC0_BASE			(APB_BASE + 0xB000)

#define TEMP_BASE			(APB_BASE + 0xC000)

#define RNG_BASE			(APB_BASE + 0xD000)

/* AES ECB Mode Encryption */
#define ECB_BASE			(APB_BASE + 0xE000)

/* Accelerated Address Resolver */
#define AAR_BASE			(APB_BASE + 0xF000)

/* AES CCM Mode Encryption */
#define CCM_BASE			(APB_BASE + 0xF000)

#define WDT_BASE			(APB_BASE + 0x10000)
#define RTC1_BASE			(APB_BASE + 0x11000)
#define QDEC_BASE			(APB_BASE + 0x12000)
#define LPCOMP_BASE			(APB_BASE + 0x13000)

#define SWI0_BASE			(APB_BASE + 0x14000)
#define SWI1_BASE			(APB_BASE + 0x15000)
#define SWI2_BASE			(APB_BASE + 0x16000)
#define SWI3_BASE			(APB_BASE + 0x17000)
#define SWI4_BASE			(APB_BASE + 0x18000)
#define SWI5_BASE			(APB_BASE + 0x19000)

#define NVMC_BASE			(APB_BASE + 0x1E000)

#define PPI_BASE			(APB_BASE + 0x1F000)

#define RTC2_BASE			(APB_BASE + 0x24000)

#endif  /* NRF_51_52_MEMORYMAP_H */
