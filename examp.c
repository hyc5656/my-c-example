#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
/*  管道、进程和execl的练习*/
int main()
{
    pid_t id1,id2;
    int pip[2];
    if(pipe(pip)==-1)
    {
        printf("error pipe!!\n");
        exit(1);
    }
    if((id1=fork())==0)
    {
        close(pip[0]);
        close(1);
        dup(pip[1]);
        close(pip[1]);
        execl("/bin/ls","ls",NULL);
        printf("ls is running!\n");
    }
//    close(pip[1]);
    if((id2=fork())==0)
    {
        close(pip[1]);
        close(0);
        dup(pip[0]);
        close(pip[0]);
        execl("/bin/grep","grep","examp.c",NULL);
        printf("grep this example file\n");
    }
    waitpid(id1,0,NULL);
    waitpid(id2,0,NULL);
    return 0;
}
