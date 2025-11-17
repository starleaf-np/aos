#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main() 
{
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    printf("Output successfully redirected to output.txt\n");
    return 0;
}