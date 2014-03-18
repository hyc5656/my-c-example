//计算一个Byte中bit为1的个数
#include<stdio.h>

int main(void)
{
	int i;
	int count=0;
	char M=0x99;
	printf("%8x中bit为1的个数是:\n",M);
	for(i=0;i<8;i++)
	{
		if(((1<<i)&M)!=0)	//必须为!=0
		{
			count++;
		}
		printf("%x\n",(1<<i)&M);
	}
	printf("%d\n",count);
	return 0;
}
