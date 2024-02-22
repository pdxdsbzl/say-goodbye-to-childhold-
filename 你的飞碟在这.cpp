#include<stdio.h>
#include<string.h>
char ar[10010]={0};
char br[10010]={0};
int main()
{
	scanf("%s",&ar);
	scanf("%s",&br);
	int la=strlen(ar);
	int lb=strlen(br);
	int sum1=1;
	int sum2=1;
	for(int i=0;i<la;i++)
	{
		sum1*=ar[i]-64;
	}
	for(int i=0;i<lb;i++)
	{
		sum2*=br[i]-64;
	}
	if(sum1%47==sum2%47)
	{
		printf("GO");
	}
	else
	printf("STAY");
	return 0;
}