/** @addtogroup adc_defines
 *
 * @brief <b>Access functions for the NRF51 ADC </b>
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

#include <unicore-mx/nrf/adc.h>

/** @brief Enable ADC */
void adc_enable(void)
{
	ADC_ENABLE = 1;
}

/** @brief Disable ADC */
void adc_disable(void)
{
	ADC_ENABLE = 0;
}

/** @brief Enable interrupts
 *
 * @param[in] mask uint32_t mask of the interrupts to enable.
 */
void adc_enable_interrupts(uint32_t mask)
{
	ADC_INTENSET = mask;
}

/** @brief Disable interrupts
 *
 * @param[in] mask uint32_t mask of the interrupts to disable.
 */
void adc_disable_interrupts(uint32_t mask)
{
	ADC_INTENCLR = mask;
}

#define __set_reg_masked(Reg, Mask, Shift, Val) do {\
	uint32_t reg_val = (Reg);\
	reg_val &= ~((Mask) << (Shift));\
	(Reg) = reg_val | (((Val) & Mask) << (Shift));\
} while (0)

/** @brief Set ADC Resolution.
 *
 * @param[in] resolution uint8_t ADC Resolution.
 */
void adc_set_resolution(uint8_t resolution)
{
	__set_reg_masked(ADC_CONFIG,
			ADC_CONFIG_RESOLUTION_MASK,
			ADC_CONFIG_RESOLUTION_SHIFT,
			resolution);
}

/** @brief Select ADC Input & Input Prescaling.
 *
 * @param[in] input uint8_t Input and prescaling constant.
 */
void adc_select_input(uint8_t input)
{
	__set_reg_masked(ADC_CONFIG,
			ADC_CONFIG_INPSEL_MASK,
			ADC_CONFIG_INPSEL_SHIFT,
			input);
}

/** @brief Select ADC Reference
 *
 * @param[in] ref uint8_t Reference Selection.
 */
void adc_select_ref(uint8_t ref)
{
	__set_reg_masked(ADC_CONFIG,
			ADC_CONFIG_REFSEL_MASK,
			ADC_CONFIG_REFSEL_SHIFT,
			ref);
}

/** @brief Select Analog Input Pin
 *
 * @param[in] ain_pin uint8_t AINx pin number (0-7). Anything out of the range
 * 	will be considered "disable".
 */
void adc_select_ain_pin(uint8_t ain_pin)
{
	ADC_CONFIG &= ~(ADC_CONFIG_PSEL_MASK << ADC_CONFIG_PSEL_SHIFT);
	if (ain_pin <= ADC_CONFIG_PSEL_AINMAX) {
		ADC_CONFIG |= ADC_CONFIG_PSEL_MASKED(ADC_CONFIG_PSEL_AIN(ain_pin));
	}
}

/** @brief Select External Reference.
 *
 * If external reference is enabled, i.e. if extref != 0,
 * this will also set REFSEL value to "External"
 *
 * @param[in] extref uint8_t External Reference Selection.
 */
void adc_select_extref(uint8_t extref)
{
	uint32_t reg_config = ADC_CONFIG;
	reg_config &= ~(ADC_CONFIG_EXTREFSEL_MASK << ADC_CONFIG_EXTREFSEL_SHIFT);
	if (extref != ADC_CONFIG_EXTREFSEL_NONE) {
		__set_reg_masked(reg_config,
				ADC_CONFIG_REFSEL_MASK,
				ADC_CONFIG_REFSEL_SHIFT,
				ADC_CONFIG_REFSEL_EXT);
		reg_config |= ADC_CONFIG_EXTREFSEL_MASKED(extref);
	}

	ADC_CONFIG = reg_config;
}

/** @brief Reset ADC Config to its default state.
 *
 * If external reference is enabled, i.e. if extref != 0,
 * this will also set REFSEL value to "External"
 *
 * @param[in] extref uint8_t External Reference Selection.
 */
void adc_reset_config(void)
{
	ADC_CONFIG = ADC_CONFIG_DEFAULT;
}

/** @brief Return result of the previous ADC conversion. */
uint16_t adc_get_result(void)
{
	return (uint16_t)ADC_RESULT;
}

/** @brief Perform single conversion synchronously and return result.
 */
uint16_t adc_convert_sync(void)
{
	ADC_TASK_START = 1;
	while (ADC_BUSY);
	return adc_get_result();
}
