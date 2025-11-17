#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
pid_t pid;
void child_done(int sig) {
    printf("Child finished.\n");
}
void alarm_handler(int sig) {
    printf("Time over! Killing child...\n");
    kill(pid, SIGKILL);
}
int main() 
{
    signal(SIGCHLD, child_done);
    signal(SIGALRM, alarm_handler);
    pid = fork();
    if (pid == 0) 
    {
        execlp("sleep", "sleep", "10", NULL);
        perror("execlp");
        exit(1);
    }
    else {
        alarm(5);
        wait(NULL);
    }
    return 0;
}