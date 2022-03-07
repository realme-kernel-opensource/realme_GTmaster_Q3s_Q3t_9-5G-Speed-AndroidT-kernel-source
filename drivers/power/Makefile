# SPDX-License-Identifier: GPL-2.0-only
obj-$(CONFIG_POWER_AVS)		+= avs/
obj-$(CONFIG_POWER_RESET)	+= reset/
obj-$(CONFIG_POWER_SUPPLY)	+= supply/

ifeq ($(strip $(BRAND_SHOW_FLAG)), realme)
subdir-ccflags-y += -DOPLUS_CHG_SUSPEND_UI_SOC_OPT
endif


ifeq ($(strip $(BRAND_SHOW_FLAG)), oneplus)
	obj-$(CONFIG_OPLUS_SM8350_CHARGER)	+= oplus_chg/
else
	obj-$(CONFIG_OPLUS_SM8350_CHARGER)	+= oplus/
endif
#endif
