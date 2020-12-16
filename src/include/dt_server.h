#ifndef __DT_SERVER_H__
#define __DT_SERVER_H__

#include <dt_common.h>

/* Server tracer */

#define DTRACE_SERVER		1

typedef struct {
	uint64_t req_get;
	uint64_t vos_start;
	uint64_t vos_end;
	uint64_t reply_post;
} dtrace_server_t;

extern bool dtrace_server_on;
extern dtrace_server_t *dtrace_server;

#if DTRACE_SERVER

#define DTRACE_SERVER_REQ_GET()				\
{							\
	if (dtrace_server_on)				\
		dtrace_server_req_get();		\
}

#define DTRACE_SERVER_VOS_START()			\
{							\
	if (dtrace_server_on)				\
		dtrace_server_vos_start();		\
}

#define DTRACE_SERVER_VOS_END()				\
{							\
	if (dtrace_server_on)				\
		dtrace_server_vos_end();		\
}

#define DTRACE_SERVER_REPLY_POST()			\
{							\
	if (dtrace_server_on)				\
		dtrace_server_reply_post();		\
}


static inline void dtrace_server_req_get(void)
{
	dtrace_server->req_get = dtrace_get_ntime();
}

static inline void dtrace_server_vos_start(void)
{
	dtrace_server->vos_start = dtrace_get_ntime();
}

static inline void dtrace_server_vos_end(void)
{
	dtrace_server->vos_end = dtrace_get_ntime();
}

static inline void dtrace_server_reply_post(void)
{
	dtrace_server->reply_post = dtrace_get_ntime();
}

#else

#define DTRACE_SERVER_REQ_GET()		do {} while (0)
#define DTRACE_SERVER_REPLY_POST()	do {} while (0)
#define DTRACE_VOS_START()		do {} while (0)
#define DTRACE_VOS_END()		do {} while (0)

#endif /* DTRACE_SERVER */

#endif /* __DT_SERVER_H__ */
