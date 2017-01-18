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

#ifndef NRF52_POWER_H
#define NRF52_POWER_H

#include <unicore-mx/nrf/periph.h>
#include <unicore-mx/nrf/common/power_51_52.h>

#define power_isr	irq0_isr

#define POWER_EVENT_SLEEPENTER		MMIO32(POWER_BASE + 0x114)
#define POWER_EVENT_SLEEPEXIT		MMIO32(POWER_BASE + 0x118)

/* NRF52-Specific Registers */
#define POWER_GPREGRET2			MMIO32(POWER_BASE + 0x520)

/* RAM0 - RAM7 Power Control Registers */
#define POWER_RAM_POWER(idx)		MMIO32(POWER_BASE + 0x900 + 0x4 * (idx))
#define POWER_RAM_POWERSET(idx)		MMIO32(POWER_BASE + 0x904 + 0x4 * (idx))
#define POWER_RAM_POWERCLR(idx)		MMIO32(POWER_BASE + 0x908 + 0x4 * (idx))

#define POWER_RAM0_POWER			POWER_RAM_POWER(0)
#define POWER_RAM0_POWERSET			POWER_RAM_POWERSET(0)
#define POWER_RAM0_POWERCLR			POWER_RAM_POWERCLR(0)

#define POWER_RAM1_POWER			POWER_RAM_POWER(1)
#define POWER_RAM1_POWERSET			POWER_RAM_POWERSET(1)
#define POWER_RAM1_POWERCLR			POWER_RAM_POWERCLR(1)

#define POWER_RAM2_POWER			POWER_RAM_POWER(2)
#define POWER_RAM2_POWERSET			POWER_RAM_POWERSET(2)
#define POWER_RAM2_POWERCLR			POWER_RAM_POWERCLR(2)

#define POWER_RAM3_POWER			POWER_RAM_POWER(3)
#define POWER_RAM3_POWERSET			POWER_RAM_POWERSET(3)
#define POWER_RAM3_POWERCLR			POWER_RAM_POWERCLR(3)

#define POWER_RAM4_POWER			POWER_RAM_POWER(4)
#define POWER_RAM4_POWERSET			POWER_RAM_POWERSET(4)
#define POWER_RAM4_POWERCLR			POWER_RAM_POWERCLR(4)

#define POWER_RAM5_POWER			POWER_RAM_POWER(5)
#define POWER_RAM5_POWERSET			POWER_RAM_POWERSET(5)
#define POWER_RAM5_POWERCLR			POWER_RAM_POWERCLR(5)

#define POWER_RAM6_POWER			POWER_RAM_POWER(6)
#define POWER_RAM6_POWERSET			POWER_RAM_POWERSET(6)
#define POWER_RAM6_POWERCLR			POWER_RAM_POWERCLR(6)

#define POWER_RAM7_POWER			POWER_RAM_POWER(7)
#define POWER_RAM7_POWERSET			POWER_RAM_POWERSET(7)
#define POWER_RAM7_POWERCLR			POWER_RAM_POWERCLR(7)

/* NRF52-Specific Register Contents */
#define POWER_RESETREAS_OFF			(1 << 16)
#define POWER_RESETREAS_LPCOMP			(1 << 17)
#define POWER_RESETREAS_DIF			(1 << 18)
#define POWER_RESETREAS_NFC			(1 << 19)

#define POWER_POFCON_THRESHOLD_SHIFT			(1)
#define POWER_POFCON_THRESHOLD_MASK			(0xf << POWER_POFCON_THRESHOLD_SHIFT)
#define POWER_POFCON_THRESHOLD_MASKED(V)			(((V) << POWER_POFCON_THRESHOLD_SHIFT) & POWER_POFCON_THRESHOLD_MASK)

#define POWER_RAM_POWER_S0			(1 << 0)
#define POWER_RAM_POWER_S1			(1 << 1)
#define POWER_RAM_POWER_S0RET			(1 << 16)
#define POWER_RAM_POWER_S1RET			(1 << 17)

enum power_pofcon_threshold {
	POWER_POFCON_THRESHOLD_V17 = 4,
	POWER_POFCON_THRESHOLD_V18,
	POWER_POFCON_THRESHOLD_V19,
	POWER_POFCON_THRESHOLD_V20,
	POWER_POFCON_THRESHOLD_V21,
	POWER_POFCON_THRESHOLD_V22,
	POWER_POFCON_THRESHOLD_V23,
	POWER_POFCON_THRESHOLD_V24,
	POWER_POFCON_THRESHOLD_V25,
	POWER_POFCON_THRESHOLD_V26,
	POWER_POFCON_THRESHOLD_V27,
	POWER_POFCON_THRESHOLD_V28,
};

#endif  /* NRF52_POWER_H */
