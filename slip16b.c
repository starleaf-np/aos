#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void sighup()  { printf("Child: I got SIGHUP.\n"); }
void sigint()  { printf("Child: I got SIGINT.\n"); }
void sigquit() {
    printf("My Papa has Killed me!!!\n");
    exit(0);
}
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
    }
    if (pid == 0) {
        signal(SIGHUP, sighup);
        signal(SIGINT, sigint);
        signal(SIGQUIT, sigquit);
        while (1);
    }
    else {
        sleep(3); kill(pid, SIGHUP);
        sleep(3); kill(pid, SIGINT);
        sleep(3); kill(pid, SIGHUP);
        sleep(3); kill(pid, SIGINT);
        sleep(3); kill(pid, SIGQUIT);
    }
    return 0;
}