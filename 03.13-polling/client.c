#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct addrinfo hints = {0}, *addr;
    int fd, n;
    char buf[5];

    /* Use TCP/IPv4 and a specified address and port: */
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(argv[1], argv[2], &hints, &addr);

    /* Create a socket and connect it to the server: */
    fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    connect(fd, addr->ai_addr, addr->ai_addrlen);

    /* Copy from stdin to the socket: */
    while ((n = read(STDIN_FILENO, buf, 4)) > 0) {
        int i = 0;
        while (i < n) {
            i += write(fd, buf + i, n - i);
        }
    }

    close(fd);
    freeaddrinfo(addr);

    return EXIT_SUCCESS;
}
