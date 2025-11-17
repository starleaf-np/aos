#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main() {
    int fd[2];
    pid_t pid;
    char buffer[50];
    pipe(fd);
    pid = fork();
    if (pid == 0) {
        close(fd[0]);
        write(fd[1], "Hello World\n", 12);
        write(fd[1], "Hello SPPU\n", 11);
        write(fd[1], "Linux is Funny\n", 16);
        close(fd[1]);
    }
    else {
        close(fd[1]);
        printf("Messages from pipe:\n");
        while (read(fd[0], buffer, sizeof(buffer)) > 0) {
            printf("%s", buffer);
        }
        close(fd[0]);
    }
    return 0;
}