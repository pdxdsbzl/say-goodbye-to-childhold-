#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // 计算不进行交换操作时的最大子段和
    int maxSum = arr[0], currentSum = arr[0];
    for (int i = 1; i < N; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    // 考虑每次交换操作带来的增益
    for (int i = 0; i < N && K > 0; i++) {
        if (arr[i] < 0) {
            maxSum += (-arr[i]);
            K--;
        }
    }

    printf("%d\n", maxSum);

    return 0;
}