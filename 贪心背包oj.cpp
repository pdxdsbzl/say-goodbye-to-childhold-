//#include<stdio.h>
////problem:pw.float,or will fail.
//int main()
//{
//	int n,c;
//	scanf("%d%d",&n,&c);
//	int arr[n][2];
//	for(int i=0;i<=n-1;i++)
//	{
//		for(int k=0;k<=1;k++)
//		{
//			scanf("%d",&arr[i][k]);
//		}
//	}
//	float pw[n];//problem here!!!!
//	for(int i=0;i<=n-1;i++)
//	{
//		pw[i]=(float)arr[i][1]/arr[i][0];
//	}
//	float pw2[n];//problem here!!!!
//	for(int i=0;i<=n-1;i++)
//	{
//		pw2[i]=pw[i];
//	}
//	float tmp=0;
//	for(int i=0;i<=n-2;i++)//Attention!!!!must be n-2!!!can't be n-1!!!!or will fail!!will more a 0.000000!!!!
//    {
//      for(int k=0;k<=n-2-i;k++)//k<=n-1-i
//      {
//        if(pw2[k]<pw2[k+1])//from big to small
//          {
//    	tmp=pw2[k];
//    	pw2[k]=pw2[k+1];
//    	pw2[k+1]=tmp;
//	      }
//      }  
//    }
////    for(int i=0;i<=n-1;i++)//test
////    {
////    	printf("%f  ",pw[i]);
////	}
////    printf("\n");
////	for(int i=0;i<=n-1;i++)//test
////    {
////    	printf("%f  ",pw2[i]);
////	}
////TO here ,it's OK.
//    int sumc=0;
//    int sumv=0;
//    int flag=0;
//    for(int k=0;k<=n-1;k++)
//    {
//       for(int i=0;i<=n-1;i++)
//       {
//    	   if(pw[i]==pw2[k])
//    	   {
//    	   	if(sumc+arr[i][0]>c)
//    	   	   {
//    	   	   	flag=1;
//			   break;
//			   }
//			   else
//			   {
//			   	sumc+=arr[i][0];
//    	        sumv+=arr[i][1];
//    	        flag=0;
//    	        break;//Problem!!!here!!!don't forget it!!
//			   }
//		   }
//	   }
//	   if(flag==1)
//	   break;
//    }
//    printf("%d\n%d",sumc,sumv);
//    return 0;
//}
#include <stdio.h>

int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    // 定义数组来存储物品的重量和价值
    int weight[n], value[n];
    float pw[n];

    // 依次输入每种物品的重量和价值
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &weight[i], &value[i]);
        pw[i] = (float)value[i] / weight[i]; // 计算单位重量的价值
    }

    // 冒泡排序，按照 pw 进行降序排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (pw[j] < pw[j + 1]) {
                float temp = pw[j];
                pw[j] = pw[j + 1];
                pw[j + 1] = temp;
                // 对应交换 weight 和 value 数组中的元素
                int temp2 = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp2;
                int temp3 = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp3;
            }
        }
    }

    // 贪心选择装入背包的物品
    int sumc = 0, sumv = 0;
    for (int i = 0; i < n; i++) {
        // 如果当前物品仍可以放入背包
        if (sumc + weight[i] <= c) {
           sumc += weight[i];
            sumv += value[i];
        } else { // 已经不能放入背包时，输出结果并退出循环
            break;
        }
    }

    printf("%d\n%d", sumc, sumv);
    return 0;
}
