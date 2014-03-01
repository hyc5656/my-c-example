#include<stdio.h>

int main()
{
    extern char **environ;
    char **p=environ;
    while(*p)
    {
        printf("%s\n",*p);
        p++;
    }
    return 0;
}
