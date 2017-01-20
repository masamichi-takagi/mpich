/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2010 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#ifndef PMIP_PMI_H_INCLUDED
#define PMIP_PMI_H_INCLUDED

#include "hydra.h"
#include "common.h"

static inline uint64_t rdtsc_light() {
    uint64_t x;
#ifdef __MIC__
    __asm__ __volatile__("rdtsc;" "shl $32, %%rdx;" "or %%rdx, %%rax":"=a"(x):: "%rdx", "memory");
#else
    __asm__ __volatile__("rdtscp;" "shl $32, %%rdx;" "or %%rdx, %%rax":"=a"(x)::"%rcx", "%rdx", "memory");
#endif
return x;
}
extern uint64_t rdtsc_sum[16];
extern uint64_t rdtsc_start;

/* PMI-1 specific definitions */
extern struct HYD_pmcd_pmip_pmi_handle *HYD_pmcd_pmip_pmi_v1;

/* PMI-2 specific definitions */
extern struct HYD_pmcd_pmip_pmi_handle *HYD_pmcd_pmip_pmi_v2;

struct HYD_pmcd_pmip_pmi_handle {
    const char *cmd;
     HYD_status(*handler) (int fd, char *args[]);
};

extern struct HYD_pmcd_pmip_pmi_handle *HYD_pmcd_pmip_pmi_handle;

#endif /* PMIP_PMI_H_INCLUDED */
