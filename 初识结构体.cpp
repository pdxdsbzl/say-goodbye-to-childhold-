#include<stdio.h>
struct M
{
	int a;
	int d;
	int arr[10];	
};
struct N
{
	int b;
	int c;
	struct M m;
};
int main()
{
	struct N n={5,3,{2,1,{3,0,2}}};
	printf("%d",n.m.arr);
}