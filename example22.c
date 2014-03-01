#include<stdio.h>
#include<sys/types.h>
#include<netdb.h>

int main(int argc,char* argv[])
{
    struct servent * serv;
    if((serv=getservbyname(argv[1],argv[2]))==NULL)
    {
        printf("serv error!\n");
        return -1;
    }
    printf("service name:%s\n",serv->s_name);
    printf("service port:%d\n",ntohs(serv->s_port));
    return 0;
}
