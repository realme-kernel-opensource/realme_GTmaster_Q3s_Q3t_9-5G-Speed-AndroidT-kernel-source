/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2020 Oplus. All rights reserved.
 */


#ifndef _OPLUS_SCHED_SLIDE_H_
#define _OPLUS_SCHED_SLIDE_H_

#include "sched_assist_common.h"

extern int sysctl_slide_boost_enabled;
extern int sysctl_boost_task_threshold;
extern int sysctl_frame_rate;

extern u64 _slide_get_boost_load(int cpu);
extern void slide_calc_boost_load(struct rq *rq, unsigned int *flag, int cpu);
extern int sched_frame_rate_handler(struct ctl_table *table, int write, void __user *buffer, size_t *lenp, loff_t *ppos);
extern int sysctl_sched_slide_boost_handler(struct ctl_table *table, int write, void __user *buffer, size_t *lenp, loff_t *ppos);
extern int sysctl_sched_animation_type_handler(struct ctl_table *table, int write, void __user *buffer, size_t *lenp, loff_t *ppos);
extern int sysctl_sched_boost_task_threshold_handler(struct ctl_table *table, int write, void __user *buffer, size_t *lenp, loff_t *ppos);
extern int sysctl_sched_assist_input_boost_ctrl_handler(struct ctl_table * table, int write, void __user * buffer, size_t * lenp, loff_t * ppos);

static void inline slide_set_boost_load(u64 *load, int cpu)
{
	u64 tmpload = *load;
    if (sched_assist_scene(SA_SLIDE) || sched_assist_scene(SA_INPUT)) {
		tmpload = max_t(u64, tmpload, _slide_get_boost_load(cpu));
		*load = tmpload;
	}

}

#endif /* _OPLUS_SCHED_SLIDE_H_ */
