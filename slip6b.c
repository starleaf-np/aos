#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>
int main() {
    int n;
    printf("Enter number of child processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (fork() == 0) {
            for (long j = 0; j < 10000000; j++);  
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        wait(NULL);
    struct rusage r;
    getrusage(RUSAGE_CHILDREN, &r);
    printf("\nTotal User Time: %ld.%06ld sec\n",
           r.ru_utime.tv_sec, r.ru_utime.tv_usec);
    printf("Total Kernel Time: %ld.%06ld sec\n",
           r.ru_stime.tv_sec, r.ru_stime.tv_usec);
    return 0;
}