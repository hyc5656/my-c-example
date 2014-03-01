#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    struct stat buf;
    stat("/home/hyc/myweb1/",&buf);
    if(S_ISDIR(buf.st_mode))
        printf("aefef\n");
    else
        printf("faefafa");
    return 0;
}
