#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int tmp=0;
	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	if(b>c)
	{
		tmp=b;
		b=c;
		c=tmp;
	}
	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	int flag=c;
	char str[4];
	scanf("%s[^\n]",&str);
//	printf("%d %d %d",a,b,c);
	if(strcmp(str,"ABC")==0)
	{
		printf("%d %d %d",a,b,flag);
	}
	if(strcmp(str,"ACB")==0)
	{
		printf("%d %d %d",a,flag,b);
	}
	if(strcmp(str,"BAC")==0)
	{
		printf("%d %d %d",b,a,flag);
	}
	if(strcmp(str,"BCA")==0)
	{
		printf("%d %d %d",b,flag,a);
	}
	if(strcmp(str,"CAB")==0)
	{
		printf("%d %d %d",flag,a,b);
	}
	if(strcmp(str,"CBA")==0)
	{
		printf("%d %d %d",flag,b,a);
	}
}