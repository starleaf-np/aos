#include <stdio.h>
#include <sys/stat.h>
int main(int c, char *v[]) 
{
    long s[50]; struct stat st;
    for (int i=1;i<c;i++) {
        stat(v[i], &st);
        s[i] = st.st_size;
    }
    for (int i=1;i<c;i++)
        for (int j=i+1;j<c;j++)
            if (s[i] > s[j]) 
            {
                long t=s[i]; 
                     s[i]=s[j]; 
                     s[j]=t;
                char *x=v[i]; 
                      v[i]=v[j]; 
                      v[j]=x;
            }
    for (int i=1;i<c;i++)
        printf("%s -> %ld bytes\n", v[i], s[i]);
}