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

#ifndef NRF52_UART_H
#define NRF52_UART_H

#include <unicore-mx/nrf/common/uart_51_52.h>

/* In nRF52 the peripheral is calle UARTE for UART with EasyDMA */
#define UARTE		UARTE0_BASE

/* UARTE-specific Tasks */
#define UART_TASK_FLUSHRX(uart)			MMIO32((uart) + 0x02C)

/* UARTE-specific Events */
#define UART_EVENT_ENDTX(uart)			MMIO32((uart) + 0x120)
#define UART_EVENT_RXSTARTED(uart)			MMIO32((uart) + 0x14C)
#define UART_EVENT_TXSTARTED(uart)			MMIO32((uart) + 0x150)
#define UART_EVENT_TXSTOPPED(uart)			MMIO32((uart) + 0x158)

/* UARTE-specific Registers */
#define UART_SHORTS(uart)			periph_shorts(uart)

#define UART_RXDPTR(uart)			MMIO32((uart) + 0x534)
#define UART_RXDMAXCNT(uart)			MMIO32((uart) + 0x538)
#define UART_RXDAMOUNT(uart)			MMIO32((uart) + 0x53C)

#define UART_TXDPTR(uart)			MMIO32((uart) + 0x544)
#define UART_TXDMAXCNT(uart)			MMIO32((uart) + 0x548)
#define UART_TXDAMOUNT(uart)			MMIO32((uart) + 0x54C)

/* UARTE-specific Register contents */
#define UART_SHORTS_ENDRX_STARTRX		(1 << 5)
#define UART_SHORTS_ENDRX_STOPRX		(1 << 6)

#define UART_INTEN_ENDRX			(1 << 4)
#define UART_INTEN_ENDTX			(1 << 8)
#define UART_INTEN_RXSTARTED			(1 << 19)
#define UART_INTEN_TXSTARTED			(1 << 20)
#define UART_INTEN_TXSTOPPED			(1 << 22)

#define UART_ENABLE_ENABLED			(8)

#define UART_PSEL_PIN_SHIFT			(0)
#define UART_PSEL_PIN_MASK			(0x1f)
#define UART_PSEL_MAX_PIN			(31)

/* nRF51 compatibility define */
#define UART_MAX_PIN			(31)
#define UART_PSEL_OFF			(0xff)
#define UART_PSEL_DISCONNECT		(1 << 31)

#define UART_PSEL_VAL(p)		((p) <= UART_PSEL_MAX_PIN ? (p) : UART_PSEL_DISCONNECT)

#endif  /* NRF52_UART_H */
