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

#ifndef NRF_51_52_UART_H
#define NRF_51_52_UART_H

#include <unicore-mx/cm3/common.h>
#include <unicore-mx/nrf/periph.h>
#include <unicore-mx/nrf/memorymap.h>


/* Common Tasks */
#define UART_TASK_STARTRX(uart)			MMIO32((uart) + 0x000)
#define UART_TASK_STOPRX(uart)			MMIO32((uart) + 0x004)
#define UART_TASK_STARTTX(uart)			MMIO32((uart) + 0x008)
#define UART_TASK_STOPTX(uart)			MMIO32((uart) + 0x00C)

/* Common Events */
#define UART_EVENT_CTS(uart)			MMIO32((uart) + 0x100)
#define UART_EVENT_NCTS(uart)			MMIO32((uart) + 0x104)
#define UART_EVENT_RXDRDY(uart)			MMIO32((uart) + 0x108)
#define UART_EVENT_TXDRDY(uart)			MMIO32((uart) + 0x11C)
#define UART_EVENT_ERROR(uart)			MMIO32((uart) + 0x124)
#define UART_EVENT_RXTO(uart)			MMIO32((uart) + 0x144)

/* Common Registers */
#define UART_INTEN(uart)			periph_inten(uart)
#define UART_INTENSET(uart)			periph_intenset(uart)
#define UART_INTENCLR(uart)			periph_intenclr(uart)
#define UART_ERRORSRC(uart)			MMIO32((uart) + 0x480)
#define UART_ENABLE(uart)			MMIO32((uart) + 0x500)
#define UART_PSELRTS(uart)			MMIO32((uart) + 0x508)
#define UART_PSELTXD(uart)			MMIO32((uart) + 0x50C)
#define UART_PSELCTS(uart)			MMIO32((uart) + 0x510)
#define UART_PSELRXD(uart)			MMIO32((uart) + 0x514)
#define UART_BAUDRATE(uart)			MMIO32((uart) + 0x524)
#define UART_CONFIG(uart)			MMIO32((uart) + 0x56C)

/* Common Register Contents */
#define UART_INTEN_CTS			(1 << 0)
#define UART_INTEN_NCTS			(1 << 1)
#define UART_INTEN_RXDRDY			(1 << 2)
#define UART_INTEN_TXDRDY			(1 << 7)
#define UART_INTEN_ERROR			(1 << 9)
#define UART_INTEN_RXTO			(1 << 17)

#define UART_ERRORSRC_OVERRUN			(1 << 0)
#define UART_ERRORSRC_PARITY			(1 << 1)
#define UART_ERRORSRC_FRAMING			(1 << 2)
#define UART_ERRORSRC_BREAK			(1 << 3)

#define UART_ENABLE_DISABLED			(0)

enum uart_baud {
	UART_BAUD_1200 = 0x0004F000,
	UART_BAUD_2400 = 0x0009D000,
	UART_BAUD_4800 = 0x0013B000,
	UART_BAUD_9600 = 0x00275000,
	UART_BAUD_14400 = 0x003B0000,
	UART_BAUD_19200 = 0x004EA000,
	UART_BAUD_28800 = 0x0075F000,
	UART_BAUD_38400 = 0x009D5000,
	UART_BAUD_57600 = 0x00EBF000,
	UART_BAUD_76800 = 0x013A9000,
	UART_BAUD_115200 = 0x01D7E000,
	UART_BAUD_230400 = 0x03AFB000,
	UART_BAUD_250000 = 0x04000000,
	UART_BAUD_460800 = 0x075F7000,
	UART_BAUD_921600 = 0x0EBEDFA4,
	UART_BAUD_1M = 0x10000000,
};

#define UART_CONFIG_HWFC			(1)
#define UART_CONFIG_PARITY			(7 << 1)

#endif  /* NRF_51_52_UART_H */
