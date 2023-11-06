#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int c;
    scanf("%d",&c);
    scanf("%d",&n);
    int w[n]={0};
    int v[n]={0};
    int sum1,sum2;
    int tem1=0;
    int tem2=0;
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=pow(2,n)-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            int m=((i & (1<<j))>> j);
            if(sum1+m*w[j]>=c)//here!!!!!!!!!!!!!!!!!!!!!!!!!!!!1problem!!!!!!!!!!!
            break;
            sum1+=m*w[j];
            sum2+=m*v[j];
        }
        if(sum2>tem2)
        {
            tem2=sum2;
            tem1=sum1;
        }
        sum1=0;
    	sum2=0;
    }
    printf("%d %d",tem1,tem2);
    return 0;
}
