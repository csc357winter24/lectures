/* Copies the contents of one file into another using system calls. */

#include <fcntl.h>
#include <unistd.h>

/* A system call is more expensive than an ordinary function call: a system
 *  call has to temporarily increase the process's privilege and securely
 *  transfer control to and from the OS. Increasing the size of the buffer does
 *  not decrease the number of characters read and written, but it does
 *  decrease the number of system calls that have to be made. */
#define SIZE 4096

int main(int argc, char *argv[]) {
    char buf[SIZE];
    int n;

    /* The open system call returns an integer file descriptor, not a pointer
     *  to a FILE structure: */
    int src, dest;

    src = open(argv[1], O_RDONLY);
    dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);


    /* The read, write, and close system calls expect integer file descriptors,
     *  not pointers to FILE structures: */
    while ((n = read(src, buf, sizeof(char) * SIZE)) > 0) {
        write(dest, buf, sizeof(char) * n);
    }

    close(src);
    close(dest);

    return 0;
}
