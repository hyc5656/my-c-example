#include<unistd.h>
#include<termio.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
    struct termio otm,ntm;
    char buf[2048];
    ioctl(0,TCGETA,&otm);
    ntm=otm;
    ntm.c_iflag |=IUCLC; //将大写字符变为小写
    ntm.c_lflag &=~ECHO;
    ioctl(0,TCSETA,&ntm);
    scanf("%s",buf);
    ioctl(0,TCSETA,&otm);
    return 0;
}

