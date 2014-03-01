#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int  main()
{
    FILE* fp;
    char buf[256];
    if((fp=freopen("/home/hyc/11","w",stderr))==NULL)
    {
       printf("error stderr");
       exit(1);
    }
    fputs("I like UNIX.\n",stderr);
    fclose(fp);
    if((fp=freopen("/home/hyc/11.txt","r",stdin))==NULL)
    {
       printf("error");
       exit(1);
    }
    memset(buf,0,256);
    fgets(buf,256,stdin);
    printf("buf=[%s]",buf);
    fclose(fp);
    return 0;
}
