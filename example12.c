#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
    pid_t i,j;
    int status;
    if((i=fork())==0)
    {
        sleep(30);
        exit(10);
    }
    j=wait(&status);
    printf("child pid=%d,exit pid=%d,exit status=%d",i,j,status);
    return 0;
}
