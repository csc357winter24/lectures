#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct addrinfo hints = {0}, *addr;
    int fd, client, n;
    char buf[5];

    /* Use TCP/IPv4: */
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    /* Use our own address and a specified port. "AI_PASSIVE" indicates that
     *  we don't plan to actively create any new connections; we just want to
     *  passively wait for other processes to connect to us. */
    hints.ai_flags = AI_PASSIVE;
    getaddrinfo(NULL, argv[1], &hints, &addr);

    /* Use that information to create a socket and bind it to a specific port;
     *  clients will need to know this port to establish connections. */
    fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    bind(fd, addr->ai_addr, addr->ai_addrlen);

    /* Listen for new connections on the bound port; for simplicity, we'll
     *  assume that only one client will ever attempt to connect. If we had to
     *  handle multiple clients, we could request that they be queued up. */
    listen(fd, 1);

    /* Accept the next new connection. If we wanted to know whose connection we
     *  just accepted, we could pass additional pointers to structures which
     *  will be populated with information about the client, for example, if we
     *  only wanted to talk to clients with certain IP addresses. */
    client = accept(fd, NULL, NULL);

    /* Note that accept creates a new socket and returns a new file descriptor
     *  for use when communicating with the accepted client. The existing file
     *  descriptor and its bound port are left untouched, still listening for
     *  potential future connections. */
    while ((n = read(client, buf, 4)) > 0) {
        buf[n] = '\0';
        printf("Read \"%s\" from client.\n", buf);
    }

    close(client);
    close(fd);
    freeaddrinfo(addr);

    return EXIT_SUCCESS;
}
