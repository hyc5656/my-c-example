#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/select.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>

#define max 256

int main()
{
    int hsock,nsock[max];
    struct sockaddr_in sin;
    struct sockaddr *addrsin=(struct sockaddr*)&sin;
    char buf[1024];
    fd_set fdset;
    struct timeval w;
    int i,n=0;
    sin.sin_family=AF_INET;
    sin.sin_port=htons(9001);
    sin.sin_addr.s_addr=htonl(INADDR_ANY);
    hsock=socket(AF_INET,SOCK_STREAM,0);
    bind(hsock,addrsin,sizeof(sin));
    listen(hsock,10);
    while(1)
    {
        FD_ZERO(&fdset);
        FD_SET(hsock,&fdset);
        for(i=0;i<n;i++)
            FD_SET(nsock[i],&fdset);
        w.tv_sec=0;
        w.tv_usec=100000;
        int maxfd=0;
        for(i=0;i<n;i++)
            if(nsock[i]>maxfd)
                maxfd=nsock[i];
        if(hsock>maxfd)
            maxfd=hsock;
        int ret=select(maxfd+1,&fdset,NULL,NULL,&w);
        if(ret==0)
            continue;
        else if(ret==-1)
        {
            printf("select error!\n");
            return -1;
        }
        else
        {
            if(FD_ISSET(hsock,&fdset))
            {
                nsock[n++]=accept(hsock,NULL,NULL);
                if(n==256)
                    n=0;
            }
            else
            {
                for(i=0;i<n;i++)
                {
                    if(FD_ISSET(nsock[i],&fdset))
                    {
                        memset(buf,0,1024);
                        read(nsock[i],buf,1024);
                        printf("get %s",buf);
                        if(strncasecmp(buf,"exit",4)==0)
                        {
                            printf("this client is leaving!!\n");
                            close(nsock[i]);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
