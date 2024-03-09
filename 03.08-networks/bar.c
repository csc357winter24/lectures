#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    struct addrinfo hints, *addrs, *addr;

    /* The type of address we would like to use; "AF_INET" indicates IPv4;
     *  we could use "AF_INET6" for IPv6 or "AF_UNSPEC" if we didn't know
     *  or didn't care: */
    hints.ai_family = AF_INET;

    /* The type of protocol we would like to use; "SOCK_STREAM" indicates TCP;
     *  we could use "SOCK_DGRAM" for UDP, which is faster but less reliable: */
    hints.ai_socktype = SOCK_STREAM;

    /* Note that the port is a string instead of an integer, because it could
     *  be specified as a well-known service name like "ssh" instead: */
    getaddrinfo("unix1.csc.calpoly.edu", "22", &hints, &addrs);

    /* It is possible that there are multiple ways to connect to the same
     *  device, so the result is a linked list of addresses: */
    addr = addrs;

    while (addr != NULL) {
        uint32_t ipaddr = ntohl(((struct sockaddr_in *)addr->ai_addr)->sin_addr.s_addr);

        printf("%d.%d.%d.%d\n",
         (ipaddr & 0xFF000000) >> 24,
         (ipaddr & 0x00FF0000) >> 16,
         (ipaddr & 0x0000FF00) >> 8,
         (ipaddr & 0x000000FF) >> 0);

        addr = addr->ai_next;
    }

    /* Note that this does not establish a connection, nor does it guarantee
     *  that the desired connection would be accepted; it simply provides the
     *  information necessary to initiate a connection. */

    freeaddrinfo(addrs);

    return EXIT_SUCCESS;
}
