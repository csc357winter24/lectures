#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

/* NOTE: For simplicity, we assume that only one
 *       child will be sporked at a time. */
static pid_t child = 0;

static void handler(int signum) {
}

/* spork: Creates a new resource-limited process. */
pid_t spork(time_t timeout) {
    if ((child = fork()) == 0) {
    }
    else {
    }

    return child;
}
