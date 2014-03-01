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
    if(mkfifo("fifo",S_IFIFO|0666)<0&&errno!=EEXIST)
        return -1;
    while(1)
    {
        if((fp=fopen("fifo","w"))==NULL)
            return -2;
        printf("please input:\n");
        fgets(buf,256,stdin);
        fputs(buf,fp);
        fputs("\n",fp);
        if(strncasecmp(buf,"exit",4)==0)
        break;
        fclose(fp);
    }
    return 0;
}
