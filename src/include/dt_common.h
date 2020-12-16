#ifndef __DT_COMMON_H__
#define __DT_COMMON_H__

#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef NSEC_PER_SEC
#define NSEC_PER_SEC  1000000000
#endif
#ifndef NSEC_PER_MSEC
#define NSEC_PER_MSEC 1000000
#endif
#ifndef NSEC_PER_USEC
#define NSEC_PER_USEC 1000
#endif

#ifndef D_ERROR
#define D_ERROR(...)	fprintf(stderr, __VA_ARGS__)
#endif

static inline uint64_t dtrace_get_ntime(void)
{
	struct timespec	tv;
	int rc;

	rc = clock_gettime(CLOCK_MONOTONIC, &tv);
	if (rc) {
		D_ERROR("%s failed!\n", __func__);
		return 0;
	}

	return (tv.tv_sec * NSEC_PER_SEC + tv.tv_nsec); /* nano seconds */
}

static inline uint64_t dtrace_get_time(void)
{
	struct timespec	tv;
	int rc;

	rc = clock_gettime(CLOCK_MONOTONIC, &tv);
	if (rc) {
		D_ERROR("%s failed!\n", __func__);
		return 0;
	}

	return tv.tv_sec; /* seconds */
}

#endif /* __DT_COMMON_H__ */
