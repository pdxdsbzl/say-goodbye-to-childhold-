#include <stdio.h> #include <math.h> #include <string.h> int main() { int w[20]; int v[20]; int m[20]; memset(m, 0, sizeof(m)); int value = 0; int weight = 0; int c = 0; int n = 0; int max = 0; int tem = 0; scanf("%d", &c); scanf("%d", &n); for (int i = 0; i < n; i++) { scanf("%d", &w[i]); } for (int i = 0; i < n; i++) { scanf("%d", &v[i]); } for (int i = 0; i < (int)(pow(2, n)); i++) { //每个i为一种情况 for (int j = 0; j < n; j++) { if ((weight + ((i & (int)pow(2, j)) >> j) * w[j] ) > c) { //已有的重量加下一个物品的重量是否超重 break; } weight += ((i & (int)pow(2, j)) >> j) * w[j];//记得跳出循环后重置weight等 value += ((i & (int)pow(2, j)) >> j) * v[j]; } if (max < value) { max = value; tem = weight; for (int j = 0; j < n; j++) { m[j] = (i & (int)pow(2, j)) >> j; } } value = 0;//记得跳出循环后重置weight等！！！！ weight = 0; } for (int j = 0; j < n; j++) { if (m[j] == 1) printf("%d ", j + 1); } printf("%d %d\n", tem, max); return 0; }