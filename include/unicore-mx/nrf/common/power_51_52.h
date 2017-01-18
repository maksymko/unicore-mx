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

#ifndef NRF_51_52_POWER_H
#define NRF_51_52_POWER_H

#include <unicore-mx/cm3/common.h>
#include <unicore-mx/nrf/memorymap.h>

/* Tasks */
#define POWER_TASK_CONSTLAT			MMIO32(POWER_BASE + 0x078)
#define POWER_TASK_LOWPWR			MMIO32(POWER_BASE + 0x07C)

/* Events */
#define POWER_EVENT_POFWARN			MMIO32(POWER_BASE + 0x108)

/* Registers */
#define POWER_INTENSET			periph_intenset(POWER_BASE)
#define POWER_INTENCLR			periph_intenclr(POWER_BASE)
#define POWER_RESETREAS			MMIO32(POWER_BASE + 0x400)
#define POWER_SYSTEMOFF			MMIO32(POWER_BASE + 0x500)
#define POWER_POFCON			MMIO32(POWER_BASE + 0x510)
#define POWER_GPREGRET			MMIO32(POWER_BASE + 0x51C)
#define POWER_DCDCEN			MMIO32(POWER_BASE + 0x578)

/* Register Contents */
#define POWER_INTEN_POFWARN			(1 << 2)
#define POWER_INTEN_SLEEPENTER			(1 << 5)
#define POWER_INTEN_SLEEPEXIT			(1 << 6)

#define POWER_RESETREAS_RESETPIN			(1 << 0)
#define POWER_RESETREAS_DOG			(1 << 1)
#define POWER_RESETREAS_SREQ			(1 << 2)
#define POWER_RESETREAS_LOCKUP			(1 << 3)

#define POWER_SYSTEMOFF_SYSTEMOFF			(1 << 0)

#define POWER_POFCON_POF			(1 << 0)

#define POWER_DCDCEN_DCDCEN			(1 << 0)

#endif  /* NRF_51_52_POWER_H */
