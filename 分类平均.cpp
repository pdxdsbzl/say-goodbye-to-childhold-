#include<stdio.h>
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	double sum1,sum2;
	int p1=0;
    int p2=0;
	for(int i=1;i<=n;i++)
	{
		if(i%k==0)
		{
			sum2+=i;
			p2++;
			continue;
		}
		p1++;
		sum1+=i;
	}
	printf("%.1f ",sum2/p2);
	printf("%.1f",sum1/p1);
    return 0;
}