//多重背包问题
# include<stdio.h>
# include<iostream>
using namespace std;
const int MAXN = 10010; //定义最大物品数量
const int MAXV = 10010; //定义最大背包容量
int N; //物品数量
int V; //背包容量
int w[MAXN];//储存每件物品的重量w[i]
int c[MAXN];//储存每件物品的价值c[i]
int s[MAXN];//储存每件物品的数量s[i]
int dp[MAXV]; //滚动dp数组
//用滚动dp数组求解
void knapsack() {
    //边界处理
    for (int i = 0; i <= V; i++)
        dp[i] = 0;
    //状态更新
    for (int i = 1; i <= N; i++) {
        //倒序枚举v (V-0)
        for (int v = V; v >= w[i]; v--)
            dp[v] = max(dp[v - w[i]] + c[i], dp[v]);
    }
}
int main(){
    int tempw[MAXN], tempc[MAXN];//储存实际上每个物品的重量和价值
    int k = 0;//储存展开后的标号
    cin >> N >> V;//输入物品的个数和最大的背包容量
    //读取tempw[i]
    for (int i = 1; i <= N; i++)
        cin >> tempw[i];
    //读取tempc[i]
    for (int i = 1; i <= N; i++)
        cin >> tempc[i];
    //利用二进制优化的方法拓展行
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j <<= 1) {
            k++;
            w[k] = tempw[i] * j;
            c[k] = tempc[i] * j;
            s[i] -= j;
        }
        if (s[i] != 0) {
            k++;
            w[k] = tempw[i] * s[i];
            c[k] = tempc[i] * s[i];
        }
    }
    N = k;
    knapsack();
    cout << dp[V] << endl;
}
/*输入数据
4 10
3 4 2 5
2 3 2 3
2 2 1 4 */
/*输出结果
8
*/

