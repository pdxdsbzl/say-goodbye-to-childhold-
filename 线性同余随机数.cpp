//#include<stdio.h>
//#include<stdlib.h>
//int mod(int n)
//{
//	int seed,a,b,M;
//	if(n==0)
//	return seed;
//	if(n>0)
//	return (a*mod(n-1)+b)%M;
//}
//int main()
//{
//	int n,a,b,M,seed;
//	scanf("%d%d%d%d%d",&n,&seed,&a,&b,&M);
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d",mod(n));
//	}
//}
#include <stdio.h>
#include <time.h>
int mod(int N, int seed, int a, int b, int M) {
int randomNum;
for (int i = 0; i < N; i++) {
seed = (a * seed + b) % M;
randomNum = seed;
printf("%d ", randomNum);
}
}
int main() {
int N, seed, a, b, M;
scanf("%d %d %d %d %d", &N, &seed, &a, &b, &M);
mod(N, seed, a, b, M);
return 0;
}
