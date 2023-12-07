#include<stdio.h>
int main()
{
	double s;
	int k;
	long long i;
	scanf("%d",&k);
	for(i=1;;i++)
	{
		s+=1.0/i;
		if(s>k)
		break;
	}
	printf("%lld",i);
	return 0;
} 