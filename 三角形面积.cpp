#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,p;
	scanf("%lf%lf%lf",&a,&b,&c);
	p=(a+b+c)/2;
	double s=sqrt(p*(p-a)*(p-b)*(p-c));
	int s2=(int)s*100;
	int s1=(int)s*10;
	if((s2-s1*10)<5)
	{
		printf("%.1lf",s);
	}
	else
	printf("%.1lf",(float)(s1+1)/10);
}