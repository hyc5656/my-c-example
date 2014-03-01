#include<stdio.h>

int main()
{
    FILE *out,*in;
    char buf[256];
    out=popen("grep init","w");
    in=popen("ps aux","r");
    while(fgets(buf,256,in))
        fputs(buf,out);
    pclose(in);
    pclose(out);
    return 0;
}
