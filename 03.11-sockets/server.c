#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct addrinfo hints = {0}, *addr;

    /* Use TCP/IPv4: */
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    /* Use our own address and a specified port: */
    hints.ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, argv[1], &hints, &addr);

    freeaddrinfo(addr);

    return EXIT_SUCCESS;
}
