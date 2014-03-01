#include<stdio.h>
#include<setjmp.h>

int j=0;

int main()
{
    int i,m=0;
    jmp_buf b;
    i=setjmp(b);
    int k=0;
    printf("j=%d,i=%d,k=%d,m=%d\n",j++,i,k++,m++);
    if(j>3)
        return 10;
    sleep(1);
    longjmp(b,1);
}
