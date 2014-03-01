#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main()
{
    time_t time1,time2;
    struct tm now;
    time(&time1);
    sleep(10);
    time(&time2);
    now=*localtime(&time2);
    printf("%d\\%d\\%d %d:%d:%d\n",now.tm_year+1990,now.tm_mon,now.tm_mday,now.tm_hour,now.tm_min,now.tm_sec);
    printf("start=%d,end=%d,difftime=%d",(int)time1,(int)time2,(int)time2-time1);
    return 0;
}
