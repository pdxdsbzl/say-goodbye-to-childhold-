#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,sum;//a是一开始钱数;b是酒后瓶子数;c是酒后盖子数;d是钱后酒数;e是最终剩钱数;
	scanf("%d",&a);
	d=a/2;
	e=a%2;
	for(h=0,b=d,c=d;b%2>=1||c%4>=1;b=b%2,c=c%4)
	{
		f=b/2;
		g=c/4;
		h=h+f+g;
	}
	sum=d+h;
	printf("%d\n%d\n%d\n%d\n",sum,b,c,e);
}