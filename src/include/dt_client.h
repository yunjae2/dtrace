#ifndef __DT_CLIENT_H__
#define __DT_CLIENT_H__

#include <dt_common.h>

/* Client tracer */

#define DTRACE_CLIENT		1

typedef struct {
	uint64_t start;
	uint64_t req;
	uint64_t req_post;
	uint64_t reply;
	uint64_t reply_get;
	uint64_t end;
} dtrace_client_t;

extern bool dtrace_client_on;
extern dtrace_client_t *dtrace_client;

#if DTRACE_CLIENT

#define DTRACE_CLIENT_START()			\
{							\
	if (dtrace_client_on)				\
		dtrace_client_start();		\
}

#define DTRACE_CLIENT_REQ()			\
{							\
	if (dtrace_client_on)				\
		dtrace_client_req();		\
}

#define DTRACE_CLIENT_REQ_POST()			\
{							\
	if (dtrace_client_on)				\
		dtrace_client_req_post();		\
}

#define DTRACE_CLIENT_REPLY_GET()			\
{							\
	if (dtrace_client_on)				\
		dtrace_client_reply_get();		\
}

#define DTRACE_CLIENT_REPLY()			\
{							\
	if (dtrace_client_on)				\
		dtrace_client_reply();		\
}

#define DTRACE_CLIENT_END()			\
{							\
	if (dtrace_client_on)				\
		dtrace_client_end();		\
}

static inline void dtrace_client_start(void)
{
	if (!dtrace_client_on) {
		dtrace_client_on = false;
		return;
	}

	dtrace_client->start = dtrace_get_ntime();
	dtrace_client->req = -1;
	dtrace_client->reply = -1;
	dtrace_client->end = -1;
}

static inline void dtrace_client_req(void)
{
	dtrace_client->req = dtrace_get_ntime();
}

static inline void dtrace_client_req_post(void)
{
	dtrace_client->req_post = dtrace_get_ntime();
}

static inline void dtrace_client_reply_get(void)
{
	dtrace_client->reply_get = dtrace_get_ntime();
}

static inline void dtrace_client_reply(void)
{
	dtrace_client->reply = dtrace_get_ntime();
}

static inline void dtrace_client_end(void)
{
	dtrace_client->end = dtrace_get_ntime();
}

#else

#define DTRACE_CLIENT_START()	do {} while (0)
#define DTRACE_CLIENT_REQ()	do {} while (0)
#define DTRACE_CLIENT_REQ_POST()	do {} while (0)
#define DTRACE_CLIENT_REPLY_GET()	do {} while (0)
#define DTRACE_CLIENT_REPLY()	do {} while (0)
#define DTRACE_CLIENT_END()	do {} while (0)

#endif

#endif /* __DT_CLIENT_H__ */
