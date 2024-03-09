#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    struct addrinfo hints = {0}, *addrs, *addr;

    /* The type of address we are requesting: "AF_INET" indicates IPv4; we
     *  could also use "AF_INET6" for IPv6 or "AF_UNSPEC" if we don't know or
     *  don't care: */
    hints.ai_family = AF_INET;

    /* The type of connection we are requesting: "SOCK_STREAM" indicates TCP;
     *  we could also use "SOCK_DGRAM" UDP, which is faster but less
     *  reliable: */
    hints.ai_socktype = SOCK_STREAM;

    /* Note that the port is a string because it could alternatively be the
     *  name of a well-known service, such as "ssh" instead of "22": */
    getaddrinfo("unix1.csc.calpoly.edu", "22", &hints, &addrs);

    /* It's possible that there are multiple ways to access the device we're
     *  trying to connect to, so getaddrinfo produces a linked list of
     *  addresses, not just one. */
    addr = addrs;

    while (addr != NULL) {
        /* Each address will be big-endian, "network order"; we might have to
         *  convert it into little-endian, whatever the "host order" is: */
        uint32_t ipaddr = ntohl(((struct sockaddr_in *)addr->ai_addr)->sin_addr.s_addr);

        /* Note that this does not establish a connection, nor does it
         *  guarantee that the device on the other end would accept a
         *  connection. It simply provides the information we would need to
         *  connect. */
        printf("%d\n", (ipaddr & 0xFF000000) >> 24);
        printf("%d\n", (ipaddr & 0x00FF0000) >> 16);
        printf("%d\n", (ipaddr & 0x0000FF00) >> 8);
        printf("%d\n", (ipaddr & 0x000000FF) >> 0);

        addr = addr->ai_next;
    }

    freeaddrinfo(addrs);

    return EXIT_SUCCESS;
}
