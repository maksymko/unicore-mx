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

#ifndef NRF52_PERIPH_H
#define NRF52_PERIPH_H

#include <unicore-mx/nrf/common/periph_51_52.h>

/* NRF52-Specific Peripheral IDs */
#define PERIPH_BPROT_ID		(0x00)
#define PERIPH_UARTE_ID		(0x02)
#define PERIPH_SPIM0_ID		(0x03)
#define PERIPH_SPIS0_ID		(0x03)
#define PERIPH_TWIM0_ID		(0x03)
#define PERIPH_TWIS0_ID		(0x03)
#define PERIPH_I2C0_ID		(0x03)
#define PERIPH_SPIM1_ID		(0x04)
#define PERIPH_SPIS1_ID		(0x04)
#define PERIPH_TWIM1_ID		(0x04)
#define PERIPH_TWIS1_ID		(0x04)
#define PERIPH_I2C1_ID		(0x04)
#define PERIPH_NFCT_ID		(0x05)
#define PERIPH_SAADC_ID		(0x07)
#define PERIPH_COMP_ID		(0x13)
#define PERIPH_EGU0_ID		(0x14)
#define PERIPH_EGU1_ID		(0x15)
#define PERIPH_EGU2_ID		(0x16)
#define PERIPH_EGU3_ID		(0x17)
#define PERIPH_EGU4_ID		(0x18)
#define PERIPH_EGU5_ID		(0x19)
#define PERIPH_TIMER3_ID		(0x1a)
#define PERIPH_TIMER4_ID		(0x1b)
#define PERIPH_PWM0_ID		(0x1c)
#define PERIPH_PDM_ID		(0x1d)
#define PERIPH_MWU_ID		(0x20)
#define PERIPH_PWM1_ID		(0x21)
#define PERIPH_PWM2_ID		(0x22)
#define PERIPH_SPIS2_ID		(0x23)
#define PERIPH_SPIM2_ID		(0x23)
#define PERIPH_RTC2_ID		(0x24)
#define PERIPH_I2S_ID		(0x25)
#define PERIPH_FPU_ID		(0x26)

#define periph_clear_event(event) do {\
	(event) = 0;\
	(void)(event);\
} while (0)

#endif  /* NRF52_PERIPH_H */
