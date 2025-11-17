#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
int main() {
    DIR *d;
    struct dirent *de;
    struct stat s;
    long n;
    printf("Enter size (in bytes): ");
    scanf("%ld", &n);
    d = opendir(".");
    if (!d) {
        printf("Error opening directory.\n");
        return 1;
    }
    while ((de = readdir(d)) != NULL) {
        stat(de->d_name, &s);
        if (S_ISREG(s.st_mode) && s.st_size > n) {
            printf("%s (%ld bytes)\n", de->d_name, (long)s.st_size);
        }
    }
    closedir(d);
    return 0;
}