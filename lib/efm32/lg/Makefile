##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
## Copyright (C) 2012 chrysn <chrysn@fsfe.org>
## Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
##
## This library is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this library. If not, see <http://www.gnu.org/licenses/>.
##

LIBNAME		= libucmx_efm32lg
SRCLIBDIR	?= ../..
FAMILY		= EFM32LG

PREFIX		?= arm-none-eabi
#PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
AR		= $(PREFIX)-ar
TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -I../../../include -fno-common \
		  -mcpu=cortex-m3 $(FP_FLAGS) -mthumb -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -D$(FAMILY)
TGT_CFLAGS      += $(DEBUG_FLAGS)
# ARFLAGS	= rcsv
ARFLAGS		= rcs
OBJS		=

OBJS		= gpio.o cmu.o prs.o adc.o dma.o timer.o dac.o
OBJS		+= usbd.o usbd_ep0.o usbd_standard.o
OBJS		+= usbd_dwc_otg.o usbd_efm32lg.o
OBJS		+= usbd_msc.o
OBJS		+= usbd_control.o usbd_string.o

# FIXME: usb host not being compiled

VPATH += ../:../../cm3
VPATH += ../../usbd:../../usbd/class:../../usbd/backend:../../usbd/misc

include ../../Makefile.include

