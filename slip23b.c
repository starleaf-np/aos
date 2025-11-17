#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) 
{
  struct stat s;
  for (int i = 1; i < argc; i++) 
  {
    if (stat(argv[i], &s) == 0) 
      {
        printf("\nFile: %s\n Inode: %ld\n", argv[i],s.st_ino);
        if (S_ISREG(s.st_mode)) printf("Type: Regular file\n");
        else if (S_ISDIR(s.st_mode)) printf("Type: Directory\n");
        else if (S_ISCHR(s.st_mode)) printf("Type: Character Device\n");
        else if (S_ISBLK(s.st_mode)) printf("Type: Block Device\n");
        else if (S_ISFIFO(s.st_mode)) printf("Type: FIFO / Pipe\n");
        else printf("Type: Unknown\n");
      }
  }
    return 0;
}