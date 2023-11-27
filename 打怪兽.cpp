#include<stdio.h>
#include<math.h>
int main()
{
	int n=0;
	int m=0;
	scanf("%d%d",&n,&m);
	int sum=pow(2,n-1);
	if(sum>=m)
	{
		printf("Yes");
	}
	else
	printf("No");
	return 0;
}