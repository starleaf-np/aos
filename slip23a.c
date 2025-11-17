#include <stdio.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }
    DIR *d = opendir(".");
    struct dirent *de;
    while ((de = readdir(d)) != NULL) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(de->d_name, argv[i]) == 0)
                printf("%s is present.\n", argv[i]);
        }
    }
    closedir(d);
    return 0;
}