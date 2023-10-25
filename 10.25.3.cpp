#include<stdio.h>
#include<math.h>
int main()
{/*
	int n,i;
	float pi;
	scanf("%d",&n);
	long m=pow(10,n);
	for(pi=0,i=1;(2*i-1)<=m;i++)
	{
		if(i%2==1)
		pi=pi+4/(2*i-1);
		else
		pi=pi-4/(2*i-1);
		
	}
	printf("%f",pi);*/
	double sum=0;
	int n;
	scanf("%d",&n);
	n = n*-1;
	int factor = 1;
	for(int i=1;1.0/i>pow(10,n);i+=2){
		sum+=factor*1.0/i;
		factor = factor*-1;
	}
	printf("%lf\n",sum*4);
	return 0;
}