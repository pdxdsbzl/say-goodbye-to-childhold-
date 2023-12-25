#include <stdio.h>

// �ݹ麯�����ж������Ƿ���Ա��ֳ�k����ȵĲ���
int can(int *arr, int n, int k, int sum1, int sum2, int *visited) {
    if (k == 1) {
        return 1; // �Ѿ��ɹ��ֳ�k������
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

    return 0; // �޷��ֳ�k������
}

int main() {
    int n, k;

    // ��ȡ�����С
    printf("�����������С: ");
    scanf("%d", &n);

    int arr[n];

    // ��������Ԫ��
    printf("����������Ԫ��:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // ��ȡkֵ
    printf("������kֵ: ");
    scanf("%d", &k);

    // ���������ܺ�
    int totalSum = 0;
    for (int i = 0; i < n; i++) 
	{
        totalSum += arr[i];
    }

    // ����Ƿ���Էֳ�k����ȵĲ���
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