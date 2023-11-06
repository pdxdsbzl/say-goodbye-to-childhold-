#include <stdio.h>
#include <string.h>

int main() {

	int m[20]={0};
	int sum1 = 0;
	int sum2= 0;
	int c = 0;
	int n = 0;
	int tem2 = 0;
	int tem1 = 0;
	scanf("%d", &c);
	scanf("%d", &n);
	int w[n];
	int v[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < (1<<n); i++)
	 {
		for (int j = 0; j < n; j++) 
		{
			int x=((i & (1<<j)) >> j);
			if ((sum1 + x * w[j] ) > c) {//here!!!!!!!!!!!!!!is the problem!!!!
			
				break;
			}
		sum1 += x * w[j];
		sum2 += x * v[j];
		}
		if (tem2 < sum2) {
			tem2 = sum2;
			tem1 = sum1;
			for (int j = 0; j < n; j++) {

				m[j] = (i & (1<<j) )>> j;
			}
		}
		sum2 = 0;
		sum1 = 0;
	}
	for (int j = 0; j < n; j++) {
		if (m[j] == 1)
			printf("%d ", j + 1);
	}
	printf("%d %d\n", tem1, tem2);
	return 0;
}
