//#include<stdio.h>
//int main()
//{
//	double m,n,u;
//	scanf("%lf",&m);
//	int l=(int)m;
//	u=m-l;
//	int t=m-u;
//	int a=(t)/100;
//	int b=(t-a*100)/10;
//	int c=(t-a*100-b*10);
//	int v=u*10;
//	printf("%d.%d%d%d",v,c,b,a);
//}
#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%c%c%c.%c", &a, &b, &c, &d);
	printf("%c.%c%c%c", d, c, b, a);
}