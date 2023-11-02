/*int JC(int n)//JC¼´½×³Ë
 {
	   if(1==n)
    return 1;
    else
    return n*JC(n-1);
}
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m=JC(n);
	printf("%d",m);
}*/
int Fib(int n)
{
	if(n<=2)
	return 1;
	else
	return Fib(n-1)+Fib(n-2);
}
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int ret=Fib(n);
	printf("%d",ret);
}