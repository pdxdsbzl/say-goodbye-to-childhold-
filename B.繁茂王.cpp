#include<stdio.h>
int ar[10010][10010];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
//	int ar[2*n][2*m]={0};
	for(int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ar[2*x-1][2*y]=1;
		ar[2*x+1][2*y]=1;
		ar[2*x][2*y-1]=1;
		ar[2*x][2*y+1]=1;
	}
	int point=0;
	for(int i=0;i<2*n+2;i++)
	{
		for(int j=0;j<2*m+2;j++)
		{
			if(ar[i][j]==1)
			point++;
		}
	}
	printf("%d",point);
	return 0;
}