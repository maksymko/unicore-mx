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

#ifndef NRF52_GPIO_H
#define NRF52_GPIO_H

#include <unicore-mx/nrf/common/gpio_51_52.h>

/* In nRF52 the instance of the peripheral is called P0 */

#define GPIO_BASE	GPIO0_BASE
#define P0			(GPIO_BASE)

/* nRF52-specific GPIO Registers */
#define GPIO_LATCH			MMIO32(GPIO_BASE + 0x520)
#define GPIO_DETECTMODE		MMIO32(GPIO_BASE + 0x524)

/* nRF52-specific Register contents */
#define GPIO_DETECTMODE_LDETECT		(1 << 0)

/* GPIO Tasks and Events specific to nRF52 */
#define GPIO_TASK_SET(n)		MMIO32(GPIO_BASE + 0x030 + 0x4 * (n))
#define GPIO_TASK_CLR(n)		MMIO32(GPIO_BASE + 0x060 + 0x4 * (n))

#endif  /* NRF52_GPIO_H */
