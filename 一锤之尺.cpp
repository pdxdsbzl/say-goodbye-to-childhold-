#include<stdio.h>
int main()
{
	int a,i=1,k=0;
	scanf("%d",&a);
	for(;;)
	{
		if(a<1024)
		{
			break;
		}
		a=a/1024;
		k++;
	}
	for(;;)
	{
		if(a==1)
		{
			break;			
		}
		a=a/2;
		i++;
		
	}
	printf("%d",i+k*10);
	return 0;
}