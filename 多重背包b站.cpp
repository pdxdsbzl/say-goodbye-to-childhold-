//���ر�������
# include<stdio.h>
# include<iostream>
using namespace std;
const int MAXN = 10010; //���������Ʒ����
const int MAXV = 10010; //������󱳰�����
int N; //��Ʒ����
int V; //��������
int w[MAXN];//����ÿ����Ʒ������w[i]
int c[MAXN];//����ÿ����Ʒ�ļ�ֵc[i]
int s[MAXN];//����ÿ����Ʒ������s[i]
int dp[MAXV]; //����dp����
//�ù���dp�������
void knapsack() {
    //�߽紦��
    for (int i = 0; i <= V; i++)
        dp[i] = 0;
    //״̬����
    for (int i = 1; i <= N; i++) {
        //����ö��v (V-0)
        for (int v = V; v >= w[i]; v--)
            dp[v] = max(dp[v - w[i]] + c[i], dp[v]);
    }
}
int main(){
    int tempw[MAXN], tempc[MAXN];//����ʵ����ÿ����Ʒ�������ͼ�ֵ
    int k = 0;//����չ����ı��
    cin >> N >> V;//������Ʒ�ĸ��������ı�������
    //��ȡtempw[i]
    for (int i = 1; i <= N; i++)
        cin >> tempw[i];
    //��ȡtempc[i]
    for (int i = 1; i <= N; i++)
        cin >> tempc[i];
    //���ö������Ż��ķ�����չ��
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
/*��������
4 10
3 4 2 5
2 3 2 3
2 2 1 4 */
/*������
8
*/

