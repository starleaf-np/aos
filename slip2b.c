#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
int count = 0;
void handler(int sig) {
    count++;
    if (count == 1)
        printf("\nCtrl-C pressed! Press again to exit.\n");
    else {
        printf("\nExiting...\n");
        exit(0);
    }
}
int main() {
    signal(SIGINT, handler);
    while (1) { 
        printf("I am in while loop waiting for Ctrl-C...\n");
    }
    return 0;
}