#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	double y;
	y=(pow((1+pow(5,0.5))/2,n)-pow((1-pow(5,0.5))/2,n))/pow(5,0.5);
	printf("%.2lf",y);
	return 0;
}