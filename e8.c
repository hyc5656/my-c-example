//字符串循环右移n位
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 1024

void loopmove(char* str,int n)
{
	if(str==NULL)	//各种错误检测，这里只写一个示范
		return;
	int left=strlen(str)-n;
	char *d=(char *)malloc(max*sizeof(char));
	if(d==NULL)
	return;
	strcpy(d,str+left);		//循环右移n位，所以把移动的n个字符先赋值
	strcpy(d+n,str);
	*(d+strlen(str))='\0';
	strcpy(str,d);
}

int main(void)
{
	char *tmp=(char *)malloc(max);
	if(tmp==NULL) exit(-1);
	strcpy(tmp,"abcabcabc");
	loopmove(tmp,2);
	printf("%s\n",tmp);
	return 0;
}
