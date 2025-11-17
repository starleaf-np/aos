#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        while (1) {
            printf("Child running...\n");
            sleep(1);
        }
    } else {
        sleep(3);
        printf("Parent: Suspending child...\n");
        kill(pid, SIGSTOP);
        sleep(5);
        printf("Parent: Resuming child...\n");
        kill(pid, SIGCONT);
        sleep(3);
        printf("Parent: Terminating child...\n");
        kill(pid, SIGKILL);
        wait(NULL);
    }
    return 0;
}