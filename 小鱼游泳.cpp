#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int u=a*60+b;
	int v=c*60+d;
	int t=v-u;
	int e=t/60;
	printf("%d %d",e,t-e*60);
}