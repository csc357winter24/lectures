#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handler(int signum) {
    /* We don't actually need to do anything in this handler; we just need
     *  to know that the signal went off. */
}

int main(void) {
    struct sigaction action;
    struct itimerval timer;
    int time = 0;

    action.sa_handler = handler;
    action.sa_flags = SA_RESTART;
    sigemptyset(&action.sa_mask);
    sigaction(SIGALRM, &action, NULL);

    /* Initialize a timer to go off after one second: */
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    /* After the timer elapses, reset it to one second: */
    timer.it_interval = timer.it_value;

    /* Start the timer -- note that the timer needs to be started after the
     *  handler is installed, otherwise the signal could be sent before we
     *  specify how to respond: */
    setitimer(ITIMER_REAL, &timer, NULL);

    while(1) {
        /* "Busy waiting" with a loop that does nothing is a waste of CPU time.
         *  Instead, we should pause execution until a signal arrives. */
        pause();

        /* Since we now respond to the signal within the main program, we have
         *  access to all the data that is in scope within the main program; we
         *  aren't limited to the globals that are in scope within handlers. */
        printf("%d\n", ++time);
    }

    return EXIT_SUCCESS;
}
