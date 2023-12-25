#include <stdio.h>

// 递归函数，判断数组是否可以被分成k个相等的部分
int can(int *arr, int n, int k, int sum1, int sum2, int *visited) {
    if (k == 1) {
        return 1; // 已经成功分成k个部分
    }

    if (sum1 == sum2) {
        return can(arr, n, k - 1, 0, sum2, visited);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            if (can(arr, n, k, sum1 + arr[i], sum2, visited)) {
                return 1;
            }
            visited[i] = 0;
        }
    }

    return 0; // 无法分成k个部分
}

int main() {
    int n, k;

    // 获取数组大小
    printf("请输入数组大小: ");
    scanf("%d", &n);

    int arr[n];

    // 输入数组元素
    printf("请输入数组元素:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 获取k值
    printf("请输入k值: ");
    scanf("%d", &k);

    // 计算数组总和
    int totalSum = 0;
    for (int i = 0; i < n; i++) 
	{
        totalSum += arr[i];
    }

    // 检查是否可以分成k个相等的部分
    if (totalSum % k == 0) {
        int sum2 = totalSum / k;
        int visited[n];
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }

        if (can(arr, n, k, 0, sum2, visited)) {
            printf("True");
        } else {
            printf("False\n");
        }
    } else {
        printf("False");
    }

    return 0;
}