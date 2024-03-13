#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct addrinfo hints = {0}, *addr;
    struct pollfd clients[17];
    int fd, n, i;

    /* Use TCP/IPv4, our own address, and a specified port: */
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, argv[1], &hints, &addr);

    /* Create a socket bound to that port and listen for new connections: */
    fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    bind(fd, addr->ai_addr, addr->ai_addrlen);
    listen(fd, 1);

    /* Add the listening socket to the array of polled descriptors: */
    clients[0].fd = fd;
    clients[0].events = POLLIN;
    n = 1;

    /* Run until no clients connect for 10 seconds: */
    while (poll(clients, n, n > 1 ? -1 : 10000) > 0) {
        /* Note that poll returns the *number* of descriptors that have data
         *  to be read, not *which* descriptor. */
        for (i = 0; i < n; i++) {
            if (clients[i].revents & POLLIN) {
                if (clients[i].fd == fd) {
                    /* Accept the next new connection and add it to the array
                     *  of descriptors to be polled: */
                    clients[n].fd = accept(fd, NULL, NULL);
                    clients[n].events = POLLIN;

                    /* Set that connection to non-blocking: */
                    fcntl(clients[n].fd, F_SETFL, O_NONBLOCK);
                    n++;
                }
                else {
                    /* Copy from the socket to stdout: */
                    char buf[5];
                    int m;

                    while ((m = read(clients[i].fd, buf, 4)) > 0) {
                        write(STDOUT_FILENO, buf, m);
                    }

                    /* With the connections made non-blocking, we can
                     *  distinguish between "no data for now" and "no data
                     *  will ever come in the future": */
                    if (m == 0) {
                        close(clients[i].fd);
                        clients[i] = clients[n - 1];
                        n--;
                    }
                }
            }
        }
    }

    close(fd);
    freeaddrinfo(addr);

    return EXIT_SUCCESS;
}
