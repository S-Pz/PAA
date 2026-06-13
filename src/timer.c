#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "timer.h"

Time get_real_time() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return format_time(now.tv_sec, now.tv_usec);
}

Time get_cpu_time() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return format_time(usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
}

Time format_time(long int sec, long int usec) {
    Time total_time = sec + ((Time)usec / 1000000.0L);
    return total_time;
}

void print_elapsed_time(char* message, Time start, Time end) {
    Time elapsed_time = end - start;
    printf("%s = %Lf\n", message, elapsed_time);
}