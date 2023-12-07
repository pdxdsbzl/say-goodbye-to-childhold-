#include<stdio.h>
int main()
{
	float h,m;
	scanf("%f%f",&m,&h);
	float b=m/(h*h);
//	printf("%f",b);
	if(b<18.5)
	printf("Underweight");
    if(b>24)
	{
	printf("%.4f\n",b);
	printf("Overweight");
}
	if(b>=18.5&&b<=24)
	printf("Normal");
	
}