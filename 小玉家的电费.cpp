#include<stdio.h>
int main()
{
	int m;
	double n=0.0;
	scanf("%d",&m);
	if(m<=150)
	{
		n=m*0.4463;
	}
	if(m>150&&m<=400)
	{
		n=150*0.4463+(m-150)*0.4663;
		
	}
	if(m>400)
	{
		n=150*0.4463+250*0.4663+(m-400)*0.5663;
	}
	n=(int)((n*10)+0.5)/10.0;
	printf("%.1lf",n);
//	double u=100.0*n;
//	int v=(int)u;
//	if(v%10<5)
//	printf("%.1lf",n);
//	else
//	{
//		printf("%.1lf",n+0.1);
//	}
}