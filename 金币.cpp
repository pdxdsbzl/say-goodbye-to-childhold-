#include<stdio.h>
int sum=0;
int point=0;
void JB(int k)
{
	int i=0;
	for(i=0;;i++)
	{
		if((1+i)*i/2<=k&&k<=(1+i+1)*(i+1)/2)
		{
			point=i;
			break;
		}
	}
	for(int j=1;j<=point;j++)
	{
		sum+=j*j;
	}
	sum+=(k-(1+point)*point/2)*(point+1);
}
int main()
{
	int k;
	scanf("%d",&k);
	JB(k);
	printf("%d",sum);
	return 0;
}