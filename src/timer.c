#include <stdio.h>
#include <sys/resource.h>

#include "timer.h"

void print_times() {

  struct rusage usage;

  getrusage(RUSAGE_SELF, &usage);

  printf("User time: %ld.%06ld\n", usage.ru_utime.tv_sec,
         usage.ru_utime.tv_usec);

  printf("System time: %ld.%06ld\n", usage.ru_stime.tv_sec,
         usage.ru_stime.tv_usec);
}
