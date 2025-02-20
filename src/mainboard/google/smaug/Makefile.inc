##
## This file is part of the coreboot project.
##
## Copyright 2018 Andre Heider <a.heider@gmail.com>
## Copyright 2015 Google Inc.
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; version 2 of the License.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

# Add a handler for BCT config files
$(call add-special-class,bct-cfg)
bct-cfg-handler= $(eval $(obj)/generated/bct.cfg: $(1)$(2))

$(obj)/generated/bct.cfg:
	@printf "    CAT        $(subst $(obj)/,,$(@))\n"
	cat $^ > $@

CFLAGS_common += -Wno-unused-function

subdirs-y += bct

bootblock-y += bootblock.c
bootblock-y += pmic.c
bootblock-y += reset.c
bootblock-y += cbfs_usb.c

verstage-y += reset.c

romstage-y += pmic.c
romstage-y += reset.c
romstage-y += romstage.c
romstage-y += sdram_configs.c
romstage-y += cbfs_usb.c

ramstage-y += mainboard.c
ramstage-y += reset.c
ramstage-y += pmic.c
ramstage-y += sdram_configs.c
ramstage-y += cbfs_usb.c

bootblock-y += memlayout.ld
romstage-y += memlayout.ld
ramstage-y += memlayout.ld
verstage-y += memlayout.ld
