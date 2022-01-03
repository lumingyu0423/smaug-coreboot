/*
 * This file is part of the coreboot project.
 *
 * Copyright 2014 Google Inc.
 * Copyright (c) 2015, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <console/console.h>
#include <soc/sdram_configs.h>
#include <boardid.h>

static const struct sdram_params sdram_configs[] = {
#include "bct/sdram-unused.inc"				/* ram_code = 0000 */
#include "bct/sdram-unused.inc"				/* ram_code = 0001 */
#include "bct/sdram-samsung-3GB-204.inc"		/* ram_code = 0010 */
#include "bct/sdram-samsung-4GB-204.inc"		/* ram_code = 0011 */
};

uint32_t ram_code(void)
{
	return 2; /* smaug have lony one sdram mode. use samsung-3GB. */
}

const struct sdram_params *get_sdram_config()
{
	uint32_t rc = ram_code();

	printk(BIOS_INFO, "SDRAM code: %d\n", rc);

	if (rc >= ARRAY_SIZE(sdram_configs) ||
		sdram_configs[rc].MemoryType == NvBootMemoryType_Unused) {
		die("Invalid SDRAM code.");
	}

	return &sdram_configs[rc];
}
