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

#ifndef NRF_51_52_RTC_H
#define NRF_51_52_RTC_H

#include <unicore-mx/cm3/common.h>
#include <unicore-mx/nrf/periph.h>
#include <unicore-mx/nrf/memorymap.h>

/* Common Tasks */
#define RTC_TASK_START(rtc)			MMIO32((rtc) + 0x000)
#define RTC_TASK_STOP(rtc)			MMIO32((rtc) + 0x004)
#define RTC_TASK_CLEAR(rtc)			MMIO32((rtc) + 0x008)
#define RTC_TASK_TRIGOVRFLW(rtc)			MMIO32((rtc) + 0x00C)

/* Common Events */
#define RTC_EVENT_TICK(rtc)			MMIO32((rtc) + 0x100)

#define RTC_EVENT_OVRFLW(rtc)			MMIO32((rtc) + 0x104)

#define RTC_EVENT_COMPARE(rtc, i)			MMIO32((rtc) + 0x140 + 0x4 * (i))

/* Common Registers */
#define RTC_INTENSET(rtc)			periph_intenset(rtc)
#define RTC_INTENCLR(rtc)			periph_intenclr(rtc)

#define RTC_EVTEN(rtc)			MMIO32((rtc) + 0x340)
#define RTC_EVTENSET(rtc)			MMIO32((rtc) + 0x344)
#define RTC_EVTENCLR(rtc)			MMIO32((rtc) + 0x348)

#define RTC_COUNTER(rtc)			MMIO32((rtc) + 0x504)
#define RTC_PRESCALER(rtc)			MMIO32((rtc) + 0x508)
#define RTC_CC(rtc, i)		MMIO32((rtc) + 0x540 + 0x4 * (i))

/* Register Contents */
#define RTC_INTEN_TICK			(1 << 0)
#define RTC_INTEN_OVRFLW			(1 << 1)
#define RTC_INTEN_COMPARE(n)			(1 << (16 + (n)))
#define RTC_INTEN_COMPARE0			(1 << 16)
#define RTC_INTEN_COMPARE1			(1 << 17)
#define RTC_INTEN_COMPARE2			(1 << 18)
#define RTC_INTEN_COMPARE3			(1 << 19)

#endif  /* NRF_51_52_RTC_H */
