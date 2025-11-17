#include <stdio.h>
#include <unistd.h>
int main() 
{
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    char buffer[50];
    if (pid == 0) {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {
        close(fd[0]);
        write(fd[1], "Hello from parent!", 19);
        close(fd[1]);
    }
    return 0;
}