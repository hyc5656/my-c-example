#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/errno.h>
#include<unistd.h>

extern int errno;
int createsock(int* s,int port,int maxl)
{
    struct sockaddr_in sin;
    struct sockaddr *addsin=(struct sockaddr*)&sin;
    sin.sin_family=AF_INET;
    sin.sin_port=port;
    sin.sin_addr.s_addr=htonl(INADDR_ANY);
    if((*s=socket(AF_INET,SOCK_STREAM,0))<=0)
    {
        printf("socket create error!!\n");
        exit(1);
    }
    bind(*s,addsin,sizeof(addsin));
    listen(*s,maxl);
    return 1;
}

int acceptsock(int* s,int ns)
{
    struct sockaddr_in sin;
    int sinsize;
    while(1)
    {
        sinsize=sizeof(sin);
        memset(&sin,0,sinsize);
        if((*s=accept(ns,(struct sockaddr*)&sin,&sinsize))>0)
            return 0;
        else if(errno==EINTR)
            continue;
        else
            exit(1);
    }
}


int main()
{
    int hsock,csock;
    char buf[256];
    struct sockaddr_in sina;
    struct sockaddr *addsin=(struct sockaddr*)&sina;
    sina.sin_family=AF_INET;
    sina.sin_port=htons(9001);
    sina.sin_addr.s_addr=htonl(INADDR_ANY);
    if((hsock=socket(AF_INET,SOCK_STREAM,0))<=0)
    {
        printf("socket create error!!\n");
        exit(1);
    }
    bind(hsock,addsin,sizeof(sina));
    listen(hsock,5);
    struct sockaddr_in sin;
    int sinsize;
    while(1)
    {
        sinsize=sizeof(sin);
        memset(&sin,0,sizeof(sin));
        if((csock=accept(hsock,(struct sockaddr *)&sin,&sinsize))>0)
        {
            while(recv(csock,buf,256,0))
            {
                if(strncasecmp(buf,"exit",4)!=0)
                {
                    printf("I get %s",buf);
                    send(csock,"<html><body>aaefaefaeferfg<input type='text' /></body></html>",sizeof("<html><body>aaefaefaeferfg<input type='text' /></body></html>"),0);
                    fsync(csock);
                }
            }
            close(csock);
            close(hsock);
        }
        else if(errno==EINTR)
            continue;
        else
            exit(1);
    }
    return 0;
}

