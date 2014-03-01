#include<stdio.h>
#include<sys/errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

extern int errno;
int main()
{
    FILE* fp;
    char buf[256];
    while(1)
    {
        if((fp=fopen("fifo","r"))==NULL)
            return -2;
        fgets(buf,256,fp);
        printf("get [%s]",buf);
        if(strncasecmp(buf,"exit",4)==0)
            break;
        fclose(fp);
    }
    return 0;
}
