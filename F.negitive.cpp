//#include<stdio.h>
//int ar[10010]={0};
//int br[10010][10010]={0};
//int map[10010]={0};
//int main()
//{
//	int t=0;
//	scanf("%d",&t);
//	for(int i=0;i<t;i++)
//	{
//		scanf("%d",&ar[i]);
//		for(int j=0;j<ar[i];j++)
//		{
//			scanf("%d",&br[i][j]);
//		}		
//	}
//	int sum=0;
//	for(int i=0;i<t;i++)
//	{
//		for(int j=0;j<ar[i];j++)
//		{
//			if(br[i][j]<0)
//			{
//				//map[j]=1;
//				if(j>1&&br[i][j-1]<br[i][j+1])
//				{
//					if(br[i][j-1]+br[i][j]<(br[i][j-1]+br[i][j])*(-1))
//					{
//						br[i][j-1]*=-1;
//						br[i][j]*=-1;
//					}
//				}
//				else
//				{
//					if(j<ar[i]-1&&br[i][j+1]+br[i][j]<(br[i][j+1]+br[i][j])*(-1))
//					{
//						br[i][j+1]*=-1;
//						br[i][j]*=-1;
//					}
//				}
//			}
//			//sum+=br[i][j];
//		}
//		for(int j=0;j<ar[i];j++)
//		{
//			sum+=br[i][j];
//		}
//		printf("%d\n",sum);
//	}
//	return 0;
//}



#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) 
	{
        int n;
        scanf("%d", &n);
        long long *arr = (long long *)malloc(n * sizeof(long long));
        
        int flag = 0;
        long long sum = 0;
        long long mint = 1000000000; 

        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
            sum += labs(arr[i]);
            
            if (arr[i] < 0) {
                flag++;
            }
            
            if (labs(arr[i]) < mint) {
                mint = labs(arr[i]);
            }
        }

        if (flag % 2 == 0) {
            printf("%lld\n", sum);
        } else {
            printf("%lld\n", sum - 2 * mint);
        }

        free(arr);
    }

    return 0;
}