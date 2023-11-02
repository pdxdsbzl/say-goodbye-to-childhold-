#include <stdio.h>
//10进制换2进制
int tran2(int x)
{
int p=1,sum=0,a;
while (1)
{
a= x%2;
x/=2;
sum+=a*p;
p *= 10;
if(x<2)
{
sum += x*p;
break;
}
}
return sum;
}
int main() 
{
	int i;
	scanf("%d",&i);
printf("%d", tran2(i));//begin
int m=tran2(i)
int arr[10]={0};
for(;;)
{
	arr[k]=m
}
}
