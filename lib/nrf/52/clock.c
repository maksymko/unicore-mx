/** @addtogroup clock_defines
 *
 * @brief <b>Access functions for the NRF51 Clock Controller </b>
 * @ingroup NRF51_defines
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

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

#include <stdint.h>

#include <unicore-mx/nrf/clock.h>

void clock_set_lfclk_src(enum clock_lfclk_src lfclk_src)
{
	uint32_t reg_src = CLOCK_LFCLK_SRC_MASKED(lfclk_src);
	if (lfclk_src == CLOCK_LFCLK_SRC_XTAL) {
		reg_src |= CLOCK_LFCLK_SRC_EXTERNAL;
	}
}
