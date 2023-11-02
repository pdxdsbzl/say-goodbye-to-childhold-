#include<stdio.h>
int main()
{
	int arr1[3][3]={0};
	int arr2[3][3]={0};
	int arr3[3][3]={0};
	int arr4[3][3]={0};
	int arr5[3][3]={0};
	int arr6[3][3]={0};
    for(int i=0;i<=2;i++)//1
    {
    	for(int j=0;j<=2;j++)
    	{
    		scanf("%d",&arr1[i][j]);
		}
	}
	  for(int i=0;i<=2;i++)//2
    {
    	for(int j=0;j<=2;j++)
    	{
    		scanf("%d",&arr2[i][j]);
		}
	}
	 for(int i=0;i<=2;i++)//3+
    {
    	for(int j=0;j<=2;j++)
    	{
    	arr3[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	for(int i=0;i<=2;i++)//4-
    {
    	for(int j=0;j<=2;j++)
    	{
    	arr4[i][j]=arr1[i][j]-arr2[i][j];
		}
	}
	for(int i=0;i<=2;i++)//5*
    {
    	for(int j=0;j<=2;j++)
    	{
    	arr5[i][j]=arr1[i][0]*arr2[0][j]+arr1[i][1]*arr2[1][j]+arr1[i][2]*arr2[2][j];
		}
	}
     for(int i=0;i<=2;i++)//6
    {
    	for(int j=0;j<=2;j++)
    	{
    	arr6[i][j]=arr1[j][i];
		}
	}
	  for(int i=0;i<=2;i++)
    {
    	for(int j=0;j<=2;j++)
    	{
    		printf("%d\t",arr3[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	  for(int i=0;i<=2;i++)
    {
    	for(int j=0;j<=2;j++)
    	{
    		printf("%d\t",arr4[i][j]);
		}
		printf("\n");
	}
		printf("\n");
		  for(int i=0;i<=2;i++)
    {
    	for(int j=0;j<=2;j++)
    	{
    		printf("%d\t",arr5[i][j]);
		}
		printf("\n");
	}
		printf("\n");
		  for(int i=0;i<=2;i++)
    {
    	for(int j=0;j<=2;j++)
    	{
    		printf("%d\t",arr6[i][j]);
		}
		printf("\n");
	}
	return 0;
}