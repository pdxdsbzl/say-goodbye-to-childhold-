//#include<stdio.h>
//unsigned long long  JC(int n)
//{
//	if(n==1)
//	return 1;
//	else
//	return JC(n-1)*n;
//}
//int main()
//{
//	unsigned long long sum=0;
//	int n;
//	scanf("%d",&n);
//	//printf("%lld",JC(n));
//	int m=n;
//	for(int i=0;i<m;i++)
//	{
//		n=n-i;
//		sum+=JC(n);
//		n=m;
//	}
//	printf("%lld",sum);
//	return 0;
//}




#include<stdio.h>
int main()
{
    int i,A[1005]={0},B[1005]={0},n,j;
    scanf("%d", &n);
    A[0]=B[0]=1;
    for (i=2;i<=n;i++)
	{
        for (j=0;j<100;j++)
            B[j]*=i;
        for (j=0;j<100;j++)
            if (B[j]>9)
			{
                B[j+1] += B[j]/10;
                B[j]%=10;
            }
        for (j=0;j<100;j++)
		{
            A[j]+=B[j];
            if (A[j]>9) 
			{
                A[j+1] += A[j]/10;
                A[j]%=10;
            }
        }
    }
    for (i=100;i>=0&&A[i]==0;i--);//索引，找到i.
    for (j=i;j>=0;j--) printf("%d", A[j]);
    return 0;
}