#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() 
{
    pid_t pid = fork();
    int status;
    if (pid == 0) {
        printf("Child running...\n");
        exit(5);
    }
    else {
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exit status: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}