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

#ifndef NRF51_ADC_H
#define NRF51_ADC_H

#include <unicore-mx/cm3/common.h>
#include <unicore-mx/nrf/memorymap.h>

/* Only one ADC on this device. */
#define ADC0			ADC_BASE

/* Tasks */
#define ADC_TASK_START			MMIO32(ADC0)
#define ADC_TASK_STOP			MMIO32(ADC0 + 0x004)

/* Events */
#define ADC_EVENT_END			MMIO32(ADC0 + 0x100)

/* Registers */
#define ADC_INTEN			MMIO32(ADC0 + 0x300)
#define ADC_INTENSET			MMIO32(ADC0 + 0x304)
#define ADC_INTENCLR			MMIO32(ADC0 + 0x308)
#define ADC_BUSY			MMIO32(ADC0 + 0x400)
#define ADC_ENABLE			MMIO32(ADC0 + 0x500)
#define ADC_CONFIG			MMIO32(ADC0 + 0x504)
#define ADC_RESULT			MMIO32(ADC0 + 0x508)

/* Register Contents */
#define ADC_INTEN_END			(1 << 0)

#define ADC_CONFIG_RESOLUTION_MASK			(3)
#define ADC_CONFIG_RESOLUTION_SHIFT			(0)
#define ADC_CONFIG_RESOLUTION_MASKED(V)			(((V) & ADC_CONFIG_RESOLUTION_MASK) << ADC_CONFIG_RESOLUTION_SHIFT)

#define ADC_CONFIG_RESOLUTION_8BIT			(0)
#define ADC_CONFIG_RESOLUTION_9BIT			(1)
#define ADC_CONFIG_RESOLUTION_10BIT			(2)

#define ADC_CONFIG_INPSEL_MASK			(7)
#define ADC_CONFIG_INPSEL_SHIFT			(2)
#define ADC_CONFIG_INPSEL_MASKED(V)			(((V) & ADC_CONFIG_INPSEL_MASK) << ADC_CONFIG_INPSEL_SHIFT)

#define ADC_CONFIG_INPSEL_AINOPRESC			(0)
#define ADC_CONFIG_INPSEL_AITWOTHIRDS			(1)
#define ADC_CONFIG_INPSEL_AIONETHIRD			(2)
#define ADC_CONFIG_INPSEL_SUPTWOTHIRDS			(5)
#define ADC_CONFIG_INPSEL_SUPONETHIRD			(6)

#define ADC_CONFIG_REFSEL_MASK			(3)
#define ADC_CONFIG_REFSEL_SHIFT			(5)
#define ADC_CONFIG_REFSEL_MASKED(V)			(((V) & ADC_CONFIG_REFSEL_MASK) << ADC_CONFIG_REFSEL_SHIFT)

#define ADC_CONFIG_REFSEL_VBG			(0)
#define ADC_CONFIG_REFSEL_EXT			(1)
#define ADC_CONFIG_REFSEL_SUPHALF			(2)
#define ADC_CONFIG_REFSEL_SUPTHIRD			(3)

#define ADC_CONFIG_PSEL_MASK			(0xff)
#define ADC_CONFIG_PSEL_SHIFT			(8)
#define ADC_CONFIG_PSEL_MASKED(V)			(((V) & ADC_CONFIG_PSEL_MASK) << ADC_CONFIG_PSEL_SHIFT)

#define ADC_CONFIG_PSEL_DIS			(0)
#define ADC_CONFIG_PSEL_AIN0			(1)
#define ADC_CONFIG_PSEL_AIN1			(2)
#define ADC_CONFIG_PSEL_AIN2			(4)
#define ADC_CONFIG_PSEL_AIN3			(8)
#define ADC_CONFIG_PSEL_AIN4			(16)
#define ADC_CONFIG_PSEL_AIN5			(32)
#define ADC_CONFIG_PSEL_AIN6			(64)
#define ADC_CONFIG_PSEL_AIN7			(128)
#define ADC_CONFIG_PSEL_AIN(N)			(1 << (N))
#define ADC_CONFIG_PSEL_AINMAX			(7)
#define ADC_CONFIG_PSEL_AIN_NONE		(0xff)

#define ADC_CONFIG_EXTREFSEL_MASK			(3)
#define ADC_CONFIG_EXTREFSEL_SHIFT			(16)
#define ADC_CONFIG_EXTREFSEL_MASKED(V)			(((V) & ADC_CONFIG_EXTREFSEL_MASK) << ADC_CONFIG_EXTREFSEL_SHIFT)

#define ADC_CONFIG_EXTREFSEL_NONE			(0)
#define ADC_CONFIG_EXTREFSEL_AREF0			(1)
#define ADC_CONFIG_EXTREFSEL_AREF1			(2)

/* Default value of the CONFIG register after reset */
#define ADC_CONFIG_DEFAULT			(0x18)

BEGIN_DECLS

void adc_enable(void);
void adc_disable(void);
void adc_enable_interrupts(uint32_t mask);
void adc_disable_interrupts(uint32_t mask);
void adc_set_resolution(uint8_t resolution);
void adc_select_input(uint8_t input);
void adc_select_ref(uint8_t ref);
void adc_select_ain_pin(uint8_t ain_pin);
void adc_select_extref(uint8_t extref);
void adc_reset_config(void);
uint16_t adc_get_result(void);
uint16_t adc_convert_sync(void);

END_DECLS

#endif  /* NRF51_ADC_H */
