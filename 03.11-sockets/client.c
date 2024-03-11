#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct addrinfo hints = {0}, *addr;
    int fd, n = 0;
    char buf[15] = "Hello, server!";

    /* Use TCP/IPv4: */
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    /* Use a specified address and port: */
    getaddrinfo(argv[1], argv[2], &hints, &addr);

    /* Use the first address produced by getaddrinfo to create a socket: */
    fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    connect(fd, addr->ai_addr, addr->ai_addrlen);

    /* It is possible that, for one reason or another, the entire buffer could
     *  not be sent at once. It is our responsibility to make sure we try to
     *  send the rest of the data later. */
    while (n < 14) {
        n += write(fd, buf + n, 14 - n);
    }

    close(fd);
    freeaddrinfo(addr);

    return EXIT_SUCCESS;
}
