#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int arr[N][3]={0};
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	int point=0;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if((arr[i][0]-arr[j][0]>=-5)&&(arr[i][0]-arr[j][0]<=5)&&(arr[i][1]-arr[j][1]>=-5)&&(arr[i][1]-arr[j][1]<=5)&&(arr[i][2]-arr[j][2]>=-5)&&(arr[i][2]-arr[j][2]<=5)&&(arr[i][0]+arr[i][1]+arr[i][2]-arr[j][0]-arr[j][1]-arr[j][2]>=-10)&&(arr[i][0]+arr[i][1]+arr[i][2]-arr[j][0]-arr[j][1]-arr[j][2]<=10))
			{
				point++;
			}
		}
	}
	printf("%d",point);
}