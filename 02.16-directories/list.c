#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    struct dirent *entry;
    DIR *dir;

    /* Every process has a current working directory within the filesystem;
     *  this changes the CWD within the program, much like if we had run "cd"
     *  before running the program: */
    chdir(argv[1]);

    /* In theory, we could read through the directory as though it were a file,
     *  but the format of a directory is not standardized, and we probably
     *  cannot or do not want to do that manually. */
    dir = opendir(".");

    /* To read from a directory is to iterate over its mappings -- readdir is
     *  essentially fgets, but for directories. */
    while ((entry = readdir(dir)) != NULL) {
        /* Note that a dirent is only guaranteed to contain a filename and the
         *  inode number to which it maps. Any other information ought to be
         *  gleaned by using the filename to stat the file. */
        stat(entry->d_name, &buf); 
        printf("%s -> %ld (%d bytes)\n", entry->d_name, entry->d_ino, buf.st_size);

        /* Further note that the contents of a dirent are only guaranteed to
         *  persist until the directory is closed or readdir is called again.
         *  If we need any of that information later, we need to allocate a
         *  copy ourselves. */
    }

    closedir(dir);

    return 0;
}
