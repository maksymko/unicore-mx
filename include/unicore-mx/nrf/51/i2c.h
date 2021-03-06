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

#ifndef NRF51_I2C_H
#define NRF51_I2C_H

#include <unicore-mx/cm3/common.h>
#include <unicore-mx/nrf/memorymap.h>

/* I2C bus */

#define I2C0			I2C0_BASE
#define I2C1			I2C1_BASE

/* Tasks */

#define I2C_TASK_STARTRX(i2c)			MMIO32((i2c) + 0x000)
#define I2C0_TASK_STARTRX			I2C_TASK_STARTRX(I2C0)
#define I2C1_TASK_STARTRX			I2C_TASK_STARTRX(I2C1)

#define I2C_TASK_STARTTX(i2c)			MMIO32((i2c) + 0x008)
#define I2C0_TASK_STARTTX			I2C_TASK_STARTTX(I2C0)
#define I2C1_TASK_STARTTX			I2C_TASK_STARTTX(I2C1)

#define I2C_TASK_STOP(i2c)			MMIO32((i2c) + 0x014)
#define I2C0_TASK_STOP			I2C_TASK_STOP(I2C0)
#define I2C1_TASK_STOP			I2C_TASK_STOP(I2C1)

#define I2C_TASK_SUSPEND(i2c)			MMIO32((i2c) + 0x01c)
#define I2C0_TASK_SUSPEND			I2C_TASK_SUSPEND(I2C0)
#define I2C1_TASK_SUSPEND			I2C_TASK_SUSPEND(I2C1)

#define I2C_TASK_RESUME(i2c)			MMIO32((i2c) + 0x020)
#define I2C0_TASK_RESUME			I2C_TASK_RESUME(I2C0)
#define I2C1_TASK_RESUME			I2C_TASK_RESUME(I2C1)

/* Events */

#define I2C_EVENT_STOPPED(i2c)			MMIO32((i2c) + 0x104)
#define I2C0_EVENT_STOPPED			I2C_EVENT_STOPPED(I2C0)
#define I2C1_EVENT_STOPPED			I2C_EVENT_STOPPED(I2C1)

#define I2C_EVENT_RXREADY(i2c)			MMIO32((i2c) + 0x108)
#define I2C0_EVENT_RXREADY			I2C_EVENT_RXREADY(I2C0)
#define I2C1_EVENT_RXREADY			I2C_EVENT_RXREADY(I2C1)

#define I2C_EVENT_TXDSENT(i2c)			MMIO32((i2c) + 0x11c)
#define I2C0_EVENT_TXDSENT			I2C_EVENT_TXDSENT(I2C0)
#define I2C1_EVENT_TXDSENT			I2C_EVENT_TXDSENT(I2C1)

#define I2C_EVENT_ERROR(i2c)			MMIO32((i2c) + 0x124)
#define I2C0_EVENT_ERROR			I2C_EVENT_ERROR(I2C0)
#define I2C1_EVENT_ERROR			I2C_EVENT_ERROR(I2C1)

#define I2C_EVENT_BB(i2c)			MMIO32((i2c) + 0x138)
#define I2C0_EVENT_BB			I2C_EVENT_BB(I2C0)
#define I2C1_EVENT_BB			I2C_EVENT_BB(I2C1)

/* Registers */

#define I2C_SHORTS(i2c)			MMIO32((i2c) + 0x200)
#define I2C0_SHORTS			I2C_SHORTS(I2C0)
#define I2C1_SHORTS			I2C_SHORTS(I2C1)

#define I2C_INTEN(i2c)			MMIO32((i2c) + 0x300)
#define I2C0_INTEN			I2C_INTEN(I2C0)
#define I2C1_INTEN			I2C_INTEN(I2C1)

#define I2C_INTENSET(i2c)			MMIO32((i2c) + 0x304)
#define I2C0_INTENSET			I2C_INTENSET(I2C0)
#define I2C1_INTENSET			I2C_INTENSET(I2C1)

#define I2C_INTENCLR(i2c)			MMIO32((i2c) + 0x308)
#define I2C0_INTENCLR			I2C_INTENCLR(I2C0)
#define I2C1_INTENCLR			I2C_INTENCLR(I2C1)

#define I2C_ERRORSRC(i2c)			MMIO32((i2c) + 0x4c4)
#define I2C0_ERRORSRC			I2C_ERRORSRC(I2C0)
#define I2C1_ERRORSRC			I2C_ERRORSRC(I2C1)

#define I2C_ENABLE(i2c)			MMIO32((i2c) + 0x500)
#define I2C0_ENABLE			I2C_ENABLE(I2C0)
#define I2C1_ENABLE			I2C_ENABLE(I2C1)

#define I2C_PSELSCL(i2c)			MMIO32((i2c) + 0x508)
#define I2C0_PSELSCL			I2C_PSELSCL(I2C0)
#define I2C1_PSELSCL			I2C_PSELSCL(I2C1)

#define I2C_PSELSDA(i2c)			MMIO32((i2c) + 0x50c)
#define I2C0_PSELSDA			I2C_PSELSDA(I2C0)
#define I2C1_PSELSDA			I2C_PSELSDA(I2C1)

#define I2C_RXD(i2c)			MMIO32((i2c) + 0x518)
#define I2C0_RXD			I2C_RXD(I2C0)
#define I2C1_RXD			I2C_RXD(I2C1)

#define I2C_TXD(i2c)			MMIO32((i2c) + 0x51c)
#define I2C0_TXD			I2C_TXD(I2C0)
#define I2C1_TXD			I2C_TXD(I2C1)

#define I2C_FREQUENCY(i2c)			MMIO32((i2c) + 0x524)
#define I2C0_FREQUENCY			I2C_FREQUENCY(I2C0)
#define I2C1_FREQUENCY			I2C_FREQUENCY(I2C1)

#define I2C_ADDRESS(i2c)			MMIO32((i2c) + 0x588)
#define I2C0_ADDRESS			I2C_ADDRESS(I2C0)
#define I2C1_ADDRESS			I2C_ADDRESS(I2C1)

/* Register Contents */

#define I2C_SHORTS_BB_SUSPEND			(1 << 0)
#define I2C_SHORTS_BB_STOP			(1 << 1)

#define I2C_INTEN_STOPPED			(1 << 1)
#define I2C_INTEN_RXDREADY			(1 << 2)
#define I2C_INTEN_TXDSENT			(1 << 7)
#define I2C_INTEN_ERROR			(1 << 9)
#define I2C_INTEN_BB			(1 << 14)

#define I2C_ERRORSRC_OVERRUN			(1 << 0)
#define I2C_ERRORSRC_ANACK			(1 << 1)
#define I2C_ERRORSRC_DNACK			(1 << 2)

#define I2C_ENABLE_VALUE			(5)

#define I2C_FREQUENCY_100K			(0x01980000)
#define I2C_FREQUENCY_250K			(0x04000000)
#define I2C_FREQUENCY_400K			(0x06680000)

#define I2C_PSEL_OFF			(0xffffffff)

/* Compatibility defines */
#define i2c0_isr			twi0_isr
#define i2c1_isr			twi1_isr

BEGIN_DECLS

void i2c_enable(uint32_t i2c);
void i2c_disable(uint32_t i2c);
void i2c_start_tx(uint32_t i2c, uint8_t data);
void i2c_start_rx(uint32_t i2c);
void i2c_send_stop(uint32_t i2c);
void i2c_set_fast_mode(uint32_t i2c);
void i2c_set_standard_mode(uint32_t i2c);
void i2c_set_frequency(uint32_t i2c, uint32_t freq);
void i2c_enable_interrupts(uint32_t i2c, uint32_t interrupts);
void i2c_disable_interrupts(uint32_t i2c, uint32_t interrupts);
void i2c_send_data(uint32_t i2c, uint8_t data);
uint8_t i2c_get_data(uint32_t i2c);
void i2c_select_pins(uint32_t i2c, uint8_t scl_pin, uint8_t sda_pin);
void i2c_set_address(uint32_t i2c, uint8_t addr);
void i2c_enable_shorts(uint32_t i2c, uint32_t shorts);
void i2c_disable_shorts(uint32_t i2c, uint32_t shorts);
void i2c_resume(uint32_t i2c);

END_DECLS

#endif  /* NRF51_UART_H */
