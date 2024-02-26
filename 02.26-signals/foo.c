#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/* A signal handler takes as argument the number of the signal that triggered
 *  the handler, and returns nothing -- it has no caller to return to. */
void handler(int signum) {
    /* This is technically unsafe; it is not safe to call printf inside a
     *  signal handler. Generally speaking, signal handlers often ought to
     *  set a flag to indicate a later action, rather than carrying out that
     *  action themselves... */
    if (signum == SIGINT) {
        printf("But HUJOE lets HIS PROCESSES stay up as long as they want!\n");
    }
    else if (signum == SIGQUIT) {
        printf("But SUMMER lets HER PROCESSES have as much CPU time as they want!\n");
    }
}

int main(void) {
    struct sigaction action;

    /* A pointer to a function that will be called in response to a signal: */
    action.sa_handler = handler;

    /* Any signals other than the signal we're responding to that should be
     *  blocked while we handle this signal: */
    sigemptyset(&action.sa_mask);

    /* Any other desired options; SA_RESTART indicates that interrupted system
     *  calls should be restarted after the signal is handled: */
    action.sa_flags = SA_RESTART;

    /* To install a handler so as to ignore SIGINTs (Ctrl+c) and SIGQUITs
     *  (Ctrl+\): */
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGQUIT, &action, NULL);

    /* Note that SIGSTOP (Ctrl+z) and SIGKILL cannot be blocked or handled: */
    sigaction(SIGSTOP, &action, NULL);
    sigaction(SIGKILL, &action, NULL);

    while(1);

    return EXIT_SUCCESS;
}
