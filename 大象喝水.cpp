#include<stdio.h>
int main()
{
	int h,r;
	scanf("%d%d",&h,&r);
	float s=3.14*r*r*h;
	float v=s/1000.0;
	int m=(int)20/v+1;
	printf("%d",m);
}