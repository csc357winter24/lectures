#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/* A signal handler takes as argument a number indicating which signal was
 *  generated, and returns nothing -- it has no caller to return to. */
void handler(int signum) {
    /* This is technically unsafe; printf is not async-signal-safe, and should
     *  not be called in a handler. Generally speaking, signal handlers often
     *  should just set a global flag for the main program to check later. */
    if (signum == SIGINT) {
        printf("But DYLAN lets HIS PROCESSES stay up as long as they want...\n");
    }
    else if (signum == SIGQUIT) {
        printf("But CLARA lets HER PROCESSES eat clock cycles before dinner!.\n");
    }
}

int main(void) {
    struct sigaction action;

    /* A pointer to a function to be called in response to a signal: */
    action.sa_handler = handler;

    /* A set of signals to be blocked while responding: */
    sigemptyset(&action.sa_mask);

    /* Additional options; SA_RESTART requests that interrupted system calls be
     *  restarted after the signal is handled: */
    action.sa_flags = SA_RESTART;

    /* To install a signal handler so as to ignore a SIGINT (Ctrl+c) or a
     *  SIGQUIT (Ctrl+\): */
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGQUIT, &action, NULL);

    /* SIGSTOP and SIGKILL cannot be blocked or handled: */
    sigaction(SIGSTOP, &action, NULL);
    sigaction(SIGKILL, &action, NULL);

    while (1);

    return EXIT_SUCCESS;
}
