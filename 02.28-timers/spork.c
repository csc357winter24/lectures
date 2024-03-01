#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

/* NOTE: For simplicity, we assume that only one child will be sporked at a
 *       time. This needs to be global so that it is accessible to the
 *       handler.*/
static pid_t child = 0;

/* NOTE: This is technically not quite safe; there is theoretically a very
 *       small chance that the sporked child exits before the timer, and
 *       during that window of time, its PID is reused for a different process,
 *       which would then be killed. */
static void handler(int signum) {
    kill(child, SIGKILL);
}

/* spork: Creates a new resource-limited process. */
pid_t spork(time_t timeout) {
    struct rlimit limit;
    struct sigaction action;
    struct itimerval timer;

    if ((child = fork()) == 0) {
        /* Lower to the child's soft and hard limits on number of processes: */
        limit.rlim_cur = 1;
        limit.rlim_max = 1;
        setrlimit(RLIMIT_NPROC, &limit);
    }
    else {
        /* Install a signal handler for SIGALRM -- this has to happen before
         *  the timer is started, otherwise there is a chance that the timer
         *  could go off before we know how to respond. */
        action.sa_handler = handler;
        action.sa_flags = SA_RESTART;
        sigemptyset(&action.sa_mask);
        sigaction(SIGALRM, &action, NULL);

        /* Set a timer for the given number of seconds: */
        timer.it_value.tv_sec = timeout;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        setitimer(ITIMER_REAL, &timer, NULL);
    }

    return child;
}
