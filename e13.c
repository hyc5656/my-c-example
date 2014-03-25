/*输出和为一给定整数的所有组合
5=1+4；5=2+3（相加的数不能重复）
则输出
1，4；2，3
*/
#include<stdio.h>

int main(void)
{
	unsigned long i,j,k;
	printf("请输入整数:\n");
	if(scanf("%ld",&i)==0)
	{
		printf("输入不为整数!!\n");
		return -1;
	}
	j=i/2;
	for(k=1;k<=j;k++)
	{
		printf("%ld=%ld+%ld\n",i,k,i-k);
	}
	return 0;

}
