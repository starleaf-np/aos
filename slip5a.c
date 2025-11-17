#include <stdio.h>
#include <dirent.h>
int main() 
{
    DIR *d;
    struct dirent *de;
    int count = 0;
    d = opendir(".");
    if (d == NULL) {
        printf("Cannot open directory.\n");
        return 1;
    }
    while ((de = readdir(d)) != NULL) {
        printf("%s\n", de->d_name);
        count++;
    }
    closedir(d);
    printf("\nTotal files: %d\n", count);
    return 0;
}