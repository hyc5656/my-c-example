#include<unistd.h>
#include<stdio.h>

int main()
{
    pid_t pid;
    if((pid=vfork())==0)
    {
        execl("/bin/ls","ls","/",NULL);

    }
    else if(pid>0)
    {
        fprintf(stdout,"fork chid pid=%d\n",pid);
    }
    else
    {
        printf("error!!");
        return 1;
    }
    return 0;
}
