#include <stdio.h>
#include <stdlib.h>

// 比较函数
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 基于贪心算法来解决问题
int main() {
    int n;
    scanf("%d", &n);
    int *price = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    // 按照价格从小到大排序
    qsort(price, n, sizeof(int), compare);

    int maxProfit = 0;
    int maxPrice = 0;
    for (int i = 0; i < n; i++) {
        int profit = price[i] * (n-i);
        if (profit > maxProfit) {
            maxProfit = profit;
            maxPrice = price[i];
        }
    }

    printf("%d %d\n", maxProfit, maxPrice);

    free(price);
    return 0;
}
