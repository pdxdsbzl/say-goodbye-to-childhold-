//#include <stdio.h>
//// 线性同余法生成浮点数
//float mod(int seed, int a, int c, int m) {
//    seed = (a * seed + c) % m;
//    float result = (float)seed / m;
//    return result;
//}
//
//int main() 
//{
//	int n=0;
//	//int trick=0;
//    int seed = 123;  // 设置随机数种子
//    scanf("%d%d",&n,&seed);
//    int a = 11036;  // a的值
//    int c = seed;  // c的值
//    int m = 21476;  // m的值，INT_MAX + 1
//    float arr[n][2];
//    for (int i= 0; i<=n-1; i++) 
//	{  
//        for(int j=0;j<=1;j++)
//        {
//       	arr[i][j]=mod(seed, a, c, m);
//        seed = (a * seed + c) % m;  // 更新种子
//		}
//    }
//    for(int i=0;i<=n-1;i++)
//    {
//    	arr[i][0]+=1.0;
//	}
//	int u=0;
//	for(int i=0;i<=n-1;i++)
//	{
//		if(arr[i][1]<1/arr[i][0])
//		{
//			u+=1;
//		}
//	}
//	float s=(float)u/n;
//	printf("%f",s);
//    return 0;
//}
//上面的是我做错的
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double mtkl(int seed, int N) {

    srand(seed); // 设置随机数种子
    int m = 0;
    for (int i = 0; i < N; i++) {
        double x = 1 + (double)rand() / RAND_MAX; // 生成1到2之间的随机数
        double fx = 1.0 / x; // 计算函数 f(x) = 1 / x
        double y = (double)rand() / RAND_MAX; // 生成0到1之间的随机数
        if (fx > y) {
            m++; // 如果落在曲线下方，点数加1
        }
    }
    double result = (double)m / N; // 计算定积分的近似值
    return result;
}

int main() {
    int seed, N;
    scanf("%d %d", &seed, &N); // 输入随机数种子和循环次数
    double result = mtkl(seed, N); // 计算ln2的近似值
    result = result * 1.0; // 将整数转换为浮点数
    printf("%lf", result); // 输出结果
    return 0;
}
//****请看注释，这是我第一次写这么详细的注释，这很重要！！！！****
//    / RAND_MAX是啥意思呀，限制随机数的范围吗?那为啥这样就可以限制在0到1?如果我要随机数限制在1到1000咋弄呢
//
//
//RAND_MAX 是 C 语言中标准库中定义的一个常量，它代表了 rand 函数所能生成的随机数的最大值。这个值是平台相关的，对于大多数平台来说，RAND_MAX 的值都是 32767。
//在 C 语言中，要生成从 0 到 1 之间的随机浮点数，我们通常可以使用类似 rand() / (double)RAND_MAX 的表达式，即通过 rand() 生成一个 0 到 RAND_MAX 之间的整数，然后通过除以 RAND_MAX 得到 0 到 1 之间的随机浮点数。
//如果你要生成 1 到 1000 之间的随机整数，可以使用下面的方法：
//int randomNumber = (rand() % 1000) + 1;
//
//上面的代码可以生成 1 到 1000 之间的随机整数。rand() % 1000 会生成 0 到 999 之间的随机数，将结果加1之后便可得到 1 到 1000 之间的随机整数。
//希望这个解释对你有帮助。如果你对随机数的生成还有其他问题，或者需要更多的解释，请随时告诉我。
//谢谢你，所以其实每个数出现的概率是不相等的对吗
//是的，您是对的。在使用 rand() % n 来生成随机数的时候，如果 n 不能整除 RAND_MAX + 1，那么生成的随机数会出现一些偏差，即每个数出现的概率并不完全相等。
//具体来说，如果 n 不能整除 RAND_MAX + 1，那么生成的随机数会略微倾向于最小的那些数，而对于较大的数则略微偏弱。这是因为 rand() 生成的是一个 0 到 RAND_MAX 之间的随机整数，如果我们用 rand() % n 来生成一个 0 到 n-1 之间的随机整数，而 RAND_MAX + 1 无法整除 n，那么对于某些数，它们将被选中的概率要大于其他数。
//如果你需要生成均匀分布的随机数，你可以考虑一些更复杂的算法或者库来实现，比如通过 random() 函数，或者使用一些现有的随机数生成库。
//希望这个解释对你有帮助。如果你对随机数分布还有其他问题，或者需要更多的解释，请随时告诉我。




