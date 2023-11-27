//C++代码
 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std9;
const int N = 20010;
int dp[N],q[N],dp1[N];
int n,m;
int v,w,s;
 
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
	{
        memcpy(dp1,dp,sizeof(dp));
        cin >> v >> w >> s;
        for (int j = 0; j < v; j ++)
		{
            int h = 0, t = -1;
            for (int k = j; k <= m; k += v)
			{
                if (h <= t && q[h] < k - v * s) h ++;
                if (h <= t) dp[k] = max(dp1[k], dp1[q[h]] + (k - q[h]) / v * w);
                while (h <= t && dp1[k] >= dp1[q[t]] + (k - q[t]) / v * w ) t--;
                q[++t] = k;
            }
        }
    }
    cout << dp[m];
    return 0;
}