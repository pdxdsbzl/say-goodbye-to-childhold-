#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b<=c||a+c<=b||b+c<=a)
	{
		printf("Not triangle");
		return 0;
	}
	if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
	{
		printf("Right triangle\n");
	}
	if(a*a+b*b>c*c&&a*a+c*c>b*b&&b*b+c*c>a*a)
	{
		printf("Acute triangle\n");
	}
	if(a*a+b*b<c*c||a*a+c*c<b*b||b*b+c*c<a*a)
	{
		printf("Obtuse triangle\n");
	}
	if(a==b||a==c||c==b)
	{
		printf("Isosceles triangle\n");
	}
	if(a==b&&a==c)
	{
		printf("Equilateral triangle\n");
	}
	return 0;
}