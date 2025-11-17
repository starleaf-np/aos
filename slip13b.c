#include <stdio.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <prefix>\n", argv[0]);
        return 1;
    }
    DIR *d = opendir(".");
    struct dirent *de;
    while ((de = readdir(d)) != NULL) {
        if (strncmp(de->d_name, argv[1], strlen(argv[1])) == 0) {
            printf("%s\n", de->d_name);
        }
    }
    closedir(d);
    return 0;
}