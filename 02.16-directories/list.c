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

    /* Every process has a current working directory within the filesystem and
     *  relative to which it accesses files (this is like running "cd", but
     *  inside of the program instead of before we run the program): */
    chdir(argv[1]);

    /* Directories are special: they are files, but we probably don't want to
     *  read from them like ordinary files, and we are not allowed to write to
     *  them like ordinary files. */
    dir = opendir(".");

    /* To read from a directory is to iterate over its entries, each of which
     *  is a filename-to-inode mapping: */
    while ((entry = readdir(dir)) != NULL) {
        /* Note that a dirent is only guaranteed to contain a filename and an
         *  inode. Further note that a dirent is only guaranteed to persist
         *  until the directory is closed or readdir is called again; if we
         *  needed the name, we should save a copy ourselves. If we want any
         *  more information about a file, now that we have its filename, we
         *  can stat it: */
        stat(entry->d_name, &buf);
        printf("%s -> %ld (%d bytes)\n", entry->d_name, entry->d_ino, buf.st_size);
    }

    closedir(dir);

    return 0;
}
