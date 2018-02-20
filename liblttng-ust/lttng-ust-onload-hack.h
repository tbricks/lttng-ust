#ifndef LTTNG_UST_ONLOAD_HACK_H
#define LTTNG_UST_ONLOAD_HACK_H

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

/* Have OpenOnload bless given fd.
 *
 * This fires OpenOnload's citp_fdtable_lookup() which in turn initializes
 * per-thread OpenOnload variables which in turn would prevent consequent
 * GLIBC's tls_get_addr_tail() invokation for that particular per-thread
 * variable, which internally takes dl_load_lock.  Take care to do it with
 * ust_lock not taken, so concurrent dlopen() firing lttng-ust code won't
 * deadlock.
 *
 * Return value: zero on success, nonzero otherwise.
 */
int lttng_ust_onload_hack_bless_fd(int fd);

#endif /* LTTNG_UST_ONLOAD_HACK_H */
