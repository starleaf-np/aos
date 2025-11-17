#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
int main() {
    DIR *d;
    struct dirent *de;
    struct stat s;
    int month;
    printf("Enter month number (1-12): ");
    scanf("%d", &month);
    d = opendir(".");
    if (!d) {
        printf("Cannot open directory.\n");
        return 1;
    }
    while ((de = readdir(d)) != NULL) {
        stat(de->d_name, &s);
        struct tm *t = localtime(&s.st_mtime);
        if ((t->tm_mon + 1) == month) {
            printf("%s\n", de->d_name);
        }
    }
    closedir(d);
    return 0;
}