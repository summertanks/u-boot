/*
 * Copyright (C) 2021 Harkirat S Virk
 *
 * Configuration settings for the Caisteal MKV.
 */

#ifndef __MX6UL_CAISTEAL_CONFIG_H
#define __MX6UL_CAISTEAL_CONFIG_H

#include <asm/arch/imx-regs.h>
#include <linux/sizes.h>
#include "mx6_common.h"
#include <asm/mach-imx/gpio.h>

#define PHYS_SDRAM_SIZE	SZ_512M

/* USB */
#define CONFIG_MXC_USB_PORTSC	(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_USBD_HS

/* Size of malloc() pool */
#define CONFIG_MXC_UART_BASE		UART1_BASE

/* MMC Configs */
#ifdef CONFIG_FSL_USDHC
#define CFG_SYS_FSL_ESDHC_ADDR	USDHC2_BASE_ADDR
#define CFG_SYS_FSL_USDHC_NUM	2
#endif

/* I2C configs */
#ifdef CONFIG_CMD_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_MXC_I2C1		/* enable I2C bus 1 */
#define CONFIG_SYS_I2C_MXC_I2C2		/* enable I2C bus 2 */
#define CONFIG_SYS_I2C_SPEED		100000
#endif

// #define CONFIG_SYS_MMC_IMG_LOAD_PART	1

#define CONFIG_MFG_ENV_SETTINGS \
	"initrd_addr=0x86800000\0" \
	"initrd_high=0xffffffff\0" \
	"emmc_dev=1\0"\
	"emmc_ack=1\0"\
	"sd_dev=1\0"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"script=boot.scr\0" \
	"image=zImage\0" \
	"console=ttymxc0\0" \
	"fdt_high=0xffffffff\0" \
	"initrd_high=0xffffffff\0" \
	"fdt_file=imx6ul-caisteal.dtb\0" \
	"fdt_addr=0x83000000\0" \
	"tee_addr=0x84000000\0" \
	"load_addr=0x80800000\0" \
	"boot_fdt=try\0" \
	"args=setenv bootargs console=${console},${baudrate} \0"

#define CONFIG_BOOTCOMMAND \
	"run args; " \
        "bootz ${load_addr} - ${fdt_addr}; \0" \

/* Miscellaneous configurable options */
#define CONFIG_SYS_HZ			1000

/* Physical Memory Map */
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE
// #define CONFIG_SYS_INIT_SP_OFFSET (CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
// #define CONFIG_SYS_INIT_SP_ADDR (CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* environment organization */
#define CONFIG_IOMUX_LPSR

#define CONFIG_SOFT_SPI

/* QSPI device */
#ifdef CONFIG_FSL_QSPI
#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define FSL_QSPI_FLASH_NUM		1
#define FSL_QSPI_FLASH_SIZE		SZ_32M
#endif


#endif
