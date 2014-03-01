#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid;
    char buf[256];
    if(pipe(fd)<0)
    {
        printf("pipe error!\n");
        return -1;
    }
    if((pid=fork())<0)
    {
        printf("fork error!\n");
        return -1;
    }
    else if(pid==0)
    {
        close(fd[1]);
        dup2(fd[0],0);
        close(fd[0]);
        memset(buf,0,256);
        gets(buf);
        printf("recv %s",buf);
    }
    close(fd[0]);
 //   dup2(fd[1],1);
 //   close(fd[1]);
    write(fd[1],"hello",strlen("hello"));
//    sleep(3);
    write(fd[1],"world",strlen("world"));
 //   puts("h");
    return 0;
}
