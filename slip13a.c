#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        while (1)
            printf("Child running...\n");
    }
    else {
        sleep(2);
        printf("\nSuspending child...\n");
        kill(pid, SIGSTOP);
        sleep(2);
        printf("Resuming child...\n");
        kill(pid, SIGCONT);
        sleep(2);
        printf("Killing child...\n");
        kill(pid, SIGKILL);
    }
    return 0;
}