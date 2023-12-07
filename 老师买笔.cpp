#include<stdio.h>
int main()
{
	int n;
	int arr1[3][2];
	scanf("%d",&n);
	for(int i=0;i<=2;i++)
	{
		scanf("%d%d",&arr1[i][0],&arr1[i][1]);
	}
	int point=0;
	for(int i=1;;i++)
	{
		if(arr1[0][0]*i>=n)
		{
			point =i;
			break;
		}
	}
	int a=point*arr1[0][1];
	for(int i=1;;i++)
	{
		if(arr1[1][0]*i>=n)
		{
			point =i;
			break;
		}
	}
	int b=point*arr1[1][1];
	for(int i=1;;i++)
	{
		if(arr1[2][0]*i>=n)
		{
			point =i;
			break;
		}
	}
	int c=point*arr1[2][1];
	if(a<=c&&a<=b)
	printf("%d",a);
	if(b<=a&&b<=c)
	printf("%d",b);
	if(c<=a&&c<=b)
	printf("%d",c);
}