#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int csock;
    struct sockaddr_in addrsock;
    char buf[256];
    struct hostent *host_name;
    if((host_name=gethostbyname("hyc-ubuntu"))==NULL)
    {
        printf("host error\n");
        return -1;
    }
    addrsock.sin_family=AF_INET;
    addrsock.sin_port=htons(9001);
    addrsock.sin_addr=*(struct in_addr *)host_name->h_addr_list[0];
    csock=socket(AF_INET,SOCK_STREAM,0);
    connect(csock,(struct sockaddr*)&addrsock,sizeof(addrsock));
    while(1)
    {
        fgets(buf,256,stdin);
        send(csock,buf,256,0);
        if(strncasecmp(buf,"exit",4)==0)
            break;
 //       recv(csock,buf,256,0);
 //       printf("get %s",buf);
    }
    close(csock);
    return 0;
}
