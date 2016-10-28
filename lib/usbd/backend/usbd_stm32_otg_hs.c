/*
 * This file is part of the unicore-mx project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include <string.h>
#include <unicore-mx/cm3/common.h>
#include <unicore-mx/stm32/tools.h>
#include <unicore-mx/stm32/otg_hs.h>
#include <unicore-mx/usbd/usbd.h>
#include "../usbd_private.h"
#include "dwc_otg_private.h"

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 512

/* Number of endpoints */
#define ENDPOINT_COUNTS 4

static usbd_device *stm32_otg_hs_usbd_init(void);

static uint32_t doeptsiz[ENDPOINT_COUNTS];
static struct dwc_otg_private_data private_data;
static struct usbd_device _usbd_dev;

const struct usbd_backend usbd_stm32_otg_hs = {
	.init = stm32_otg_hs_usbd_init,
	.set_address = dwc_otg_set_address,
	.ep_setup = dwc_otg_ep_setup,
	.set_ep_type = dwc_otg_set_ep_type,
	.set_ep_size = dwc_otg_set_ep_size,
	.ep_reset = dwc_otg_endpoints_reset,
	.set_ep_stall = dwc_otg_set_ep_stall,
	.get_ep_stall = dwc_otg_get_ep_stall,
	.set_ep_nak = dwc_otg_set_ep_nak,
	.ep_write_packet = dwc_otg_ep_write_packet,
	.ep_read_packet = dwc_otg_ep_read_packet,
	.poll = dwc_otg_poll,
	.enable_sof = dwc_otg_enable_sof,
	.disconnect = dwc_otg_disconnect,
	.frame_number  = dwc_otg_frame_number,
	.set_address_before_status = true,
};

/** Initialize the USB device controller hardware of the STM32. */
static usbd_device *stm32_otg_hs_usbd_init(void)
{
	private_data.base_address = USB_OTG_HS_BASE;
	private_data.rx_fifo_size = RX_FIFO_SIZE;
	private_data.fifo_mem_top = RX_FIFO_SIZE;
	private_data.doeptsiz = doeptsiz;
	private_data.ep_count = ENDPOINT_COUNTS;
	_usbd_dev.backend_data = &private_data;

	if (OTG_HS_CID >= 0x00002000) { /* 2.0 */
		/* Enable VBUS detection and power up the PHY. */
		OTG_HS_GCCFG = OTG_GCCFG_VBDEN | OTG_GCCFG_PWRDWN;
		DWC_OTG_GOTGCTL(USB_OTG_HS_BASE) |= DWC_OTG_GOTGCTL_BVALOEN |
										DWC_OTG_GOTGCTL_BVALOVAL;
	} else { /* 1.x */
		/* Enable VBUS sensing in device mode and power up the PHY. */
		OTG_HS_GCCFG = OTG_GCCFG_VBUSBSEN | OTG_GCCFG_PWRDWN;
	}

	dwc_otg_init(&_usbd_dev);

	return &_usbd_dev;
}
