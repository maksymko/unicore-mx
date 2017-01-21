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

#include <unicore-mx/nrf/uart.h>

/** @brief Send buffer synchronously.
 *
 * For compatibility with nRF51 API length of the buffer is left to be uint16_t,
 * however, only uint8_t is supported by this implementation.
 *
 * @param[in] uart uint32_t uart base
 * @param[in] buffer const uint8_t* buffer to send
 * @param[in] len uint16_t length of the buffer
 */
void uart_send_buffer_blocking(uint32_t uart, const uint8_t *buffer, uint16_t len)
{
	UART_TXDPTR(uart) = (uint32_t)buffer;
	UART_TXDMAXCNT(uart) = (uint8_t)len;
	periph_trigger_task(UART_TASK_STARTTX(uart));
	periph_wait_event(UART_EVENT_ENDTX(uart));
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
