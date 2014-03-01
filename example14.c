#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void fun(int s)
{
    if(s==SIGUSR1)
        printf("catch sigusr1!\n");
    else
        printf("other signal catch\n");
    signal(SIGUSR1,fun);
}

int main()
{
    signal(SIGUSR1,fun);
    while(1)
    {
        kill(getpid(),SIGUSR1);
    }
    return 0;
}
