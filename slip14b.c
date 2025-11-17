#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    struct stat s;
    printf("Inode: %ld\n", (long)s.st_ino);
    printf("Hard links: %ld\n", (long)s.st_nlink);
    printf("Size: %ld bytes\n", (long)s.st_size);
    printf("Permissions: %o\n", s.st_mode & 0777);
    printf("Last Access: %s", ctime(&s.st_atime));
    printf("Last Modify: %s", ctime(&s.st_mtime));
    return 0;
}