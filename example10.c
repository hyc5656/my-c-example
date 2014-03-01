#include<stdarg.h>
#include<stdio.h>

int mysum(int i,...)
{
    int r,j=0;
    va_list va_l;
    va_start(va_l,i);
    for(r=0;r<i;r++)
    {
        j+=va_arg(va_l,int);
    }
    va_end(va_l);
    return j;
}

int main(int argc,char* argv[])
{
    printf("mysun()=%d\n",mysum(2,1,4));
    printf("mysun()=%d\n",mysum(3,2,1,4));
    return 0;
}
