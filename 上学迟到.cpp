#include<stdio.h>
int main()
{
	int s,v;
	scanf("%d%d",&s,&v);
	float m=(float)s/v;
	if(m-(int)m!=0.0)
	{
		m=(int)m+1;
	}
	int n=(int)m+10;
//	printf("%d",n);
    if(n/60<=7||n==480)
	{
		int a=8-n/60-1;
		int b=n%60;
		int c=60-b;
		if(b!=0)
		printf("0%d:%02d",a,c);
		else
		printf("0%d:00",a+1);
	}
	else 
	{
		if(n<=(14+8)*60)
		{
			int a=24-(n/60-8)-1;
			int b=n%60;
			int c=60-b;
			if(b!=0)
			printf("%d:%02d",a,c);
			else
			printf("%d:00",a+1);
		}
		else
		{
			int a=24-(n/60-8)-1;
			int b=n%60;
			int c=60-b;
			if(b!=0)
			printf("0%d:%02d",a,c);
			else
			printf("0%d:00",a+1);
		}
	}
	return 0;
}




//#include <stdio.h>
//
//int main() {
//    int s, v;
//    scanf("%d%d", &s, &v);
//    
//    int m = s / v; // 路程除以速度，得到分钟数
//    if (s % v != 0) {
//        m += 1; // 如果有余数，需要加上1分钟
//    }
//    
//    int n = m + 10; // 加上垃圾分类的时间
//    
//    if (n / 60 <= 7 || n == 480) {
//        int a = 8 - n / 60 - 1;
//        int b = n % 60;
//        int c = 60 - b;
//        if (b != 0) {
//            printf("0%d:%02d", a, c); // 输出格式为 HH:MM，补0到两位
//        } else {
//            printf("0%d:00", a + 1);
//        }
//    } else {
//        if (n <= (14 + 8) * 60) {
//            int a = 24 - (n / 60 - 8) - 1;
//            int b = n % 60;
//            int c = 60 - b;
//            if (b != 0) {
//                printf("%d:%02d", a, c);
//            } else {
//                printf("%d:00", a + 1);
//            }
//        } else {
//            int a = 24 - (n / 60 - 8) - 1;
//            int b = n % 60;
//            int c = 60 - b;
//            if (b != 0) {
//                printf("0%d:%02d", a, c);
//            } else {
//                printf("0%d:00", a + 1);
//            }
//        }
//    }
//    
//    return 0;
//}