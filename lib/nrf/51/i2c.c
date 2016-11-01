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

#include <unicore-mx/nrf/i2c.h>

void i2c_enable(uint32_t i2c)
{
	I2C_ENABLE(i2c) = I2C_ENABLE_VALUE;
}

void i2c_disable(uint32_t i2c)
{
	I2C_ENABLE(i2c) = 0;
}

void i2c_start_tx(uint32_t i2c, uint8_t data)
{
	I2C_TASK_STARTTX(i2c) = 1;
	I2C_TXD(i2c) = data;
}

void i2c_start_rx(uint32_t i2c)
{
	I2C_TASK_STARTRX(i2c) = 1;
}

void i2c_send_stop(uint32_t i2c)
{
	I2C_TASK_STOP(i2c) = 1;
}

void i2c_set_fast_mode(uint32_t i2c)
{
	I2C_FREQUENCY(i2c) = I2C_FREQUENCY_400K;
}

void i2c_set_standard_mode(uint32_t i2c)
{
	I2C_FREQUENCY(i2c) = I2C_FREQUENCY_100K;
}

void i2c_set_frequency(uint32_t i2c, uint32_t freq)
{
	I2C_FREQUENCY(i2c) = freq;
}

void i2c_enable_interrupts(uint32_t i2c, uint32_t interrupts)
{
	I2C_INTEN(i2c) = interrupts;
}

void i2c_disable_interrupts(uint32_t i2c, uint32_t interrupts)
{
	I2C_INTENCLR(i2c) = interrupts;
}

void i2c_send_data(uint32_t i2c, uint8_t data)
{
	I2C_TXD(i2c) = data;
}

uint8_t i2c_get_data(uint32_t i2c)
{
	return (uint8_t)I2C_RXD(i2c);
}

void i2c_select_pins(uint32_t i2c, uint8_t scl_pin, uint8_t sda_pin)
{
	I2C_PSELSCL(i2c) = scl_pin;
	I2C_PSELSDA(i2c) = sda_pin;
}

void i2c_set_address(uint32_t i2c, uint8_t addr)
{
	I2C_ADDRESS(i2c) = addr;
}


