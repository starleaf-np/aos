#include <stdio.h>
#include <sys/resource.h>
int main() 
{
    struct rlimit r;
    getrlimit(RLIMIT_NOFILE, &r);
    printf("Current File Limit: soft=%ld  hard=%ld\n", r.rlim_cur, r.rlim_max);
    r.rlim_cur = 2048;
    setrlimit(RLIMIT_NOFILE, &r);
    getrlimit(RLIMIT_NOFILE, &r);
    printf("Updated File Limit: soft=%ld  hard=%ld\n", r.rlim_cur, r.rlim_max);
    getrlimit(RLIMIT_AS, &r);
    printf("Memory Limit: soft=%ld  hard=%ld\n", r.rlim_cur, r.rlim_max);
    return 0;
}