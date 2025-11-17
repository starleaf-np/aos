#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
pid_t pid;
void child_dead(int sig) {
    printf("Child process finished.\n");
}
void alarm_handler(int sig) {
    printf("Time over! Killing child...\n");
    kill(pid, SIGKILL);
}
int main() {
    signal(SIGCHLD, child_dead);
    signal(SIGALRM, alarm_handler);
    pid = fork();
    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(1);
    }
    else {
        alarm(5);
        wait(NULL);
    }
    return 0;
}