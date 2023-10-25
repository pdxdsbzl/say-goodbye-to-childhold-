#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(y=1;y<=i;y++)
		printf("%d*%d\t",y,i);
	}
}