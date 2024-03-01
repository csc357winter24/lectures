#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handler(int signum) {
    /* This handler doesn't actually have to do anything, we just need to
     *  change the default response to SIGALRM, which is to terminate. */
}

int main(void) {
    struct sigaction action;
    struct itimerval timer;
    int i = 0;

    action.sa_handler = handler;
    action.sa_flags = SA_RESTART;
    sigemptyset(&action.sa_mask);
    sigaction(SIGALRM, &action, NULL);

    /* Initialize a timer for one second: */
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;

    /* Every time the timer elapses, reset it to one second: */
    timer.it_interval = timer.it_value;

    /* Start the timer: */
    setitimer(ITIMER_REAL, &timer, NULL);

    while(1) {
        /* Rather than busy-waiting, we can just halt execution until a signal
         *  is sent -- and now that we're effectively responding to the signal
         *  in the main program, we have access to all of the main program's
         *  information: */
        pause();
        printf("%d\n", ++i);
    }

    return EXIT_SUCCESS;
}
