# include <iostream>
# include <stdio.h>

using namespace std;

int n, k, sum;

int main () {
	scanf ("%d%d", &n, &k);
	for (int i = k; i <= n; i += k)
		sum += i;
	printf ("%.1f ", double (sum) / (n / k)); // 精确到小数点后 1 位，直接 %.1f 即可
	sum = (1 + n) * n / 2 - sum;
	printf ("%.1f\n", double (sum) / (n - n / k));
	return 0;
}