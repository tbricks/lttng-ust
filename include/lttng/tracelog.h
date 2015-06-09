#ifndef _LTTNG_UST_TRACELOG_H
#define _LTTNG_UST_TRACELOG_H

/*
 * Copyright (C) 2013-2015  Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <lttng/lttng-ust-tracelog.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TP_TRACELOG_CB_TEMPLATE(level) \
	extern void _lttng_ust_tracelog_##level(const char *file, \
		int line, const char *func, const char *fmt, ...)

TP_TRACELOG_CB_TEMPLATE(emerg);
TP_TRACELOG_CB_TEMPLATE(alert);
TP_TRACELOG_CB_TEMPLATE(crit);
TP_TRACELOG_CB_TEMPLATE(err);
TP_TRACELOG_CB_TEMPLATE(warning);
TP_TRACELOG_CB_TEMPLATE(notice);
TP_TRACELOG_CB_TEMPLATE(info);
TP_TRACELOG_CB_TEMPLATE(debug_system);
TP_TRACELOG_CB_TEMPLATE(debug_program);
TP_TRACELOG_CB_TEMPLATE(debug_process);
TP_TRACELOG_CB_TEMPLATE(debug_module);
TP_TRACELOG_CB_TEMPLATE(debug_unit);
TP_TRACELOG_CB_TEMPLATE(debug_function);
TP_TRACELOG_CB_TEMPLATE(debug_line);
TP_TRACELOG_CB_TEMPLATE(debug);

#undef TP_TRACELOG_CB_TEMPLATE

#define tracelog(level, fmt, ...)					\
	do {								\
		STAP_PROBEV(tracepoint_lttng_ust_tracelog, level, ## __VA_ARGS__); \
		if (caa_unlikely(__tracepoint_lttng_ust_tracelog___## level.state)) \
			_lttng_ust_tracelog_##level(__FILE__, __LINE__, __func__, \
				fmt, ## __VA_ARGS__); \
	} while (0)

#ifdef __cplusplus
}
#endif

#endif /* _LTTNG_UST_TRACELOG_H */
