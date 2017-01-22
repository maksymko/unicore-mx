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

#include <unicore-mx/nrf/memorymap.h>
#include <unicore-mx/nrf/uart.h>

/** @brief Send buffer synchronously.
 *
 * @param[in] uart uint32_t uart base
 * @param[in] buffer const uint8_t* buffer to send
 * @param[in] len uint16_t length of the buffer
 */
void uart_send_buffer_blocking(uint32_t uart, const uint8_t *buffer, uint16_t len)
{
	if ((uint32_t)buffer < SRAM_BASE) {
		/* The buffer is not in SRAM, can't do EasyDMA, use local buffer */
		volatile uint8_t local_buffer;
		UART_TXDPTR(uart) = (uint32_t)&local_buffer;
		UART_TXDMAXCNT(uart) = 1;
		for (int i = 0; i < len; ++i) {
			local_buffer = *(buffer + i);
			periph_trigger_task(UART_TASK_STARTTX(uart));
			periph_wait_event(UART_EVENT_ENDTX(uart));
		}
	} else {
		do {
			uint8_t to_transfer = len > 0xff ? 0xff : (uint8_t)len;

			UART_TXDPTR(uart) = (uint32_t)buffer;
			UART_TXDMAXCNT(uart) = to_transfer;
			periph_trigger_task(UART_TASK_STARTTX(uart));
			len -= to_transfer;
			buffer += to_transfer;
			periph_wait_event(UART_EVENT_ENDTX(uart));
		} while (len);
	}

	periph_trigger_task(UART_TASK_STOPTX(uart));
	periph_wait_event(UART_EVENT_TXSTOPPED(uart));
}

/** @brief Send zero terminated string synchronously.
 *
 * In this implementation the string can't be longer than 255 bytes.
 *
 * @param[in] uart uint32_t uart base
 * @param[in] buffer const char* string to send
 */
void uart_send_string_blocking(uint32_t uart, const char *str)
{
	uint16_t len = 0;
	for (int i = 0; i < 0xff && *(str + i); ++i, ++len);
	uart_send_buffer_blocking(uart, (const uint8_t *)str, len);
}
