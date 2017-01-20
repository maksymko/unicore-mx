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

#ifndef NRF52_CLOCK_H
#define NRF52_CLOCK_H

#include <unicore-mx/nrf/common/clock_51_52.h>

#define clock_isr	irq0_isr

/* nRF52-specific Registers */
#define CLOCK_TRACECONFIG		(CLOCK_BASE + 0x55C)

/* nRF52-specific register values */

#define CLOCK_HFCLK_SRC_RC		(0)
#define CLOCK_HFCLK_SRC_XTAL		(1)

#define CLOCK_TRACECONFIG_TPSPEED_MASK		(3)
#define CLOCK_TRACECONFIG_TPSPEED_SHIFT		(0)

#define CLOCK_TRACECONFIG_TMUX_MASK		(3)
#define CLOCK_TRACECONFIG_TMUX_SHIFT		(16)

#define CLOCK_LFCLK_SRC_BYPASS		(1 << 16)
#define CLOCK_LFCLK_SRC_EXTERNAL		(1 << 17)

enum clock_tp_speed {
	CLOCK_TP_SPEED_32MHZ,
	CLOCK_TP_SPEED_16MHZ,
	CLOCK_TP_SPEED_8MHZ,
	CLOCK_TP_SPEED_4MHZ,
};

enum clock_tmux {
	CLOCK_TMUX_GPIO,
	CLOCK_TMUX_SERIAL,
	CLOCK_TMUX_PARALLEL,
};

#endif  /* NRF52_CLOCK_H */
