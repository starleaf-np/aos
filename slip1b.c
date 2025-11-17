#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void handler() {
    printf("Alarm fired!\n");
}
int main() {
    signal(SIGALRM, handler);
    if (fork() == 0) { 
        sleep(2);
        kill(getppid(), SIGALRM);
    } 
    else {
        printf("Waiting for alarm...\n");
        pause();
    }
    return 0;
}