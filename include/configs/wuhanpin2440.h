/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <gj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * (C) Copyright 2009-2010
 * Michel Pollet <buserror@gmail.com>
 *
 * (C) Copyright 2012
 * Gabriel Huau <contact@huau-gabriel.fr>
 *
 * Configuation settings for the MINI2440 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

//#define CONFIG_SYS_TEXT_BASE 0x0
#define CONFIG_S3C2440_GPIO
#define DEBUG 1

/*
 * High Level Configuration Options
 */
#define CONFIG_ARM920T			/* This is an ARM920T Core	*/
#define CONFIG_S3C24X0			/* in a SAMSUNG S3C24X0 SoC */
#define CONFIG_S3C2440			/* in a SAMSUNG S3C2440 SoC */
#define CONFIG_MINI2440			/* on a MIN2440 Board       */

#define MACH_TYPE_MINI2440	1999
#define CONFIG_MACH_TYPE	MACH_TYPE_MINI2440

/*
 * We don't use lowlevel_init
 */
//#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_BOARD_EARLY_INIT_F

/*
 * input clock of PLL
 */
/* MINI2440 has 12.0000MHz input clock */
#define CONFIG_SYS_CLK_FREQ	12000000

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN	(CONFIG_ENV_SIZE + 2048*1024)

/*
 * Hardware drivers
 */
#define CONFIG_DRIVER_DM9000
#define CONFIG_DRIVER_DM9000_NO_EEPROM
#define CONFIG_DM9000_BASE				0x20000300
#define DM9000_IO		CONFIG_DM9000_BASE
#define DM9000_DATA		(CONFIG_DM9000_BASE+4)

/*
 * select serial console configuration
 */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1

/*
 * allow to overwrite serial and ethaddr
 */
#define CONFIG_ENV_OVERWRITE

/*
 * Command definition
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PORTIO
#define CONFIG_CMD_REGINFO
#define CONFIG_CMD_SAVES

/*
 * Miscellaneous configurable options
 */
#define CONFIG_LONGHELP
#define CONFIG_SYS_PROMPT	"MINI2440 => "
#define CONFIG_SYS_CBSIZE	256
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS	32
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE

#define CONFIG_SYS_MEMTEST_START	0x30000000
#define CONFIG_SYS_MEMTEST_END		0x34000000	/* 64MB in DRAM	*/

/* default load address	*/
#define CONFIG_SYS_LOAD_ADDR		0x32000000

/* boot parameters address */
#define CONFIG_BOOT_PARAM_ADDR		0x30000100

/*
 * the PWM TImer 4 uses a counter of 15625 for 10 ms, so we need
 * it to wrap 100 times (total 1562500) to get 1 sec.
 */
#define CONFIG_SYS_HZ			1562500

/*
 * valid baudrates
 */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }
#define CONFIG_BAUDRATE		115200

/*
 * Stack sizes
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(8*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

/*
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS        1          /* we have 1 bank of DRAM */
#define PHYS_SDRAM_SIZE             (64*1024*1024) /* 64MB of DRAM */
#define CONFIG_SYS_SDRAM_BASE       0x30000000
#define CONFIG_SYS_FLASH_BASE		0x0

/*
 * Stack should be on the SRAM because
 * DRAM is not init
 */
#ifdef CONFIG_NAND_SPL
#define CONFIG_SYS_INIT_SP_ADDR 0x33200000
#else
#define CONFIG_SYS_INIT_SP_ADDR		(0x40001000 - GENERATED_GBL_DATA_SIZE)
#endif

/*
 * NOR FLASH organization
 * Now uses the standard CFI interface
 * FLASH and environment organization
 */
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_16BIT
#define CONFIG_SYS_MONITOR_BASE		0x0
/* max number of memory banks */
#define CONFIG_SYS_MAX_FLASH_BANKS	1
/* 512 * 4096 sectors, or 32 * 64k blocks */
#define CONFIG_SYS_MAX_FLASH_SECT	512
#define CONFIG_FLASH_SHOW_PROGRESS  1

#define CONFIG_FLASH_CFI_LEGACY
#define CONFIG_SYS_FLASH_LEGACY_1024Kx16

/*
 * nand flash
 */
#ifndef CONFIG_NAND_SPL       
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

#define CONFIG_SYS_NAND_BASE 0x4e000000
#define CONFIG_SYS_NAND_U_BOOT_DST 0x33000000    /*NUB load-addr      */
#define CONFIG_SYS_NAND_U_BOOT_START CONFIG_SYS_NAND_U_BOOT_DST       /* NUB start addr     */

#define CONFIG_SYS_NAND_U_BOOT_OFFS	(4 * 1024)      /* Offset to RAM U-Boot image */
#define CONFIG_SYS_NAND_U_BOOT_SIZE	0x80000  /*Size of RAM U-Boot image   */

/* NAND chip page size        */
#define CONFIG_SYS_NAND_PAGE_SIZE      2048
/* NAND chip block size             */
#define CONFIG_SYS_NAND_BLOCK_SIZE   (128 * 1024)
/* NAND chip page per block count  */
#define CONFIG_SYS_NAND_PAGE_COUNT 64
/* Location of the bad-block label */
#define CONFIG_SYS_NAND_BAD_BLOCK_POS  0
/* Extra address cycle for > 128MiB */
#define CONFIG_SYS_NAND_5_ADDR_CYCLE
 
/* Size of the block protected by one OOB(Spare Area in Samsung terminology) */
#define CONFIG_SYS_NAND_ECCSIZE   CONFIG_SYS_NAND_PAGE_SIZE
/* Number of ECC bytes per OOB - S3C6400 calculates 4 bytes ECC in 1-bitmode */
#define CONFIG_SYS_NAND_ECCBYTES      4
/* Number of ECC-blocks per NAND page */
#define CONFIG_SYS_NAND_ECCSTEPS       (CONFIG_SYS_NAND_PAGE_SIZE  / CONFIG_SYS_NAND_ECCSIZE)
/* Size of a single OOB region */
#define CONFIG_SYS_NAND_OOBSIZE  64
/* Number of ECC bytes per page */
#define CONFIG_SYS_NAND_ECCTOTAL      (CONFIG_SYS_NAND_ECCBYTES *CONFIG_SYS_NAND_ECCSTEPS)
/* ECC byte positions */
#define CONFIG_SYS_NAND_ECCPOS           {40, 41, 42, 43, 44, 45, 46, 47, \
                             48, 49, 50, 51, 52, 53, 54, 55, \
                             56, 57, 58, 59, 60, 61, 62, 63}
 
/* Put environment copies after the end ofU-Boot owned RAM */
#define CONFIG_NAND_ENV_DST   (0x33000000 + 0x80000)
#define CONFIG_ENV_OFFSET        0x80000
//#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_SIZE             0x4000    /* Total Size of Environment Sector */

/*
 * Config for NOR flash
 */
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_MY_ENV_OFFSET	0x40000
/* addr of environment */
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + CONFIG_MY_ENV_OFFSET)
/* 16k Total Size of Environment Sector */
#define CONFIG_ENV_SIZE		0x4000

/* ATAG configuration */
#define CONFIG_INITRD_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE

#endif	/* __CONFIG_H */
