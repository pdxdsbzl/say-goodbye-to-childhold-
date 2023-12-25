#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int tmp=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%02d",tmp);
			tmp++;
		}
		printf("\n");
	}	
	printf("\n");
	 tmp=1;
	for(int i=1;i<=n;i++)
	{
			int m=n-i;
			while(m)
			{
				printf("  ");
				m--;
			}
		for(int j=1;j<=i;j++)
		{
			
			printf("%02d",tmp);
			tmp++;
		}
		printf("\n");
	}	
	return 0;
}