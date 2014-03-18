//将整数转换为字符串
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n,i=0,tmp=0,sign=0;
	char str[50];
	printf("input a number:\n");
	if((scanf("%d",&n))==0)
	{
		printf("输入的不是整数\n");
		exit(-1);
	}
	if(n<0)
	{
		sign=1;
		n=abs(n);
	}
	tmp=n;
	do
	{
		str[i++]=tmp%10+48;
		tmp/=10;
	}while(tmp!=0);
	printf("%d转换成字符串后为:\n",n);
	if(sign==1)
		printf("-");
	for(tmp=i-1;tmp>=0;tmp--)
		printf("%c",str[tmp]);
	printf("\n");
	return 0;
}
