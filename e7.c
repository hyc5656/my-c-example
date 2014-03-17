//判断字符串是否是回文
#include<stdio.h>
#include<string.h>

int Ishuiwen(const char *p)
{
	int i,j;
	if(p==NULL)
		return -1;
	j=strlen(p);
	for(i=0;i<j/2;i++)
	{
		if(p[i]!=p[j-i-1])
			return 0;
	}
	return 1;
}

int main(void)
{
	char *p=NULL;
	printf("%d\n",Ishuiwen("123321"));
	printf("%d\n",Ishuiwen("abcabc"));
	printf("%d\n",Ishuiwen(p));
}
