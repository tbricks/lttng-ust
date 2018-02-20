#include <stdint.h>
#include "lttng-ust-onload-hack.h"

struct onload_stat {
  int32_t   stack_id;
  char*     stack_name;
  int32_t   endpoint_id;
  int32_t   endpoint_state;
};

__attribute__((weak))
int onload_fd_stat(int fd, struct onload_stat* stat)
{
       return 0;
}

int lttng_ust_onload_hack_bless_fd(int fd) {
       struct onload_stat fd_stat;
       return onload_fd_stat(fd, &fd_stat);
}
