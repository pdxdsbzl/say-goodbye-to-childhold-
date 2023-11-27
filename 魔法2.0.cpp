#include <stdio.h>
#include <stdlib.h>

int minMagic(int n, char* str, int l, int r) {
    int freq[26] = {0}; // 用来记录每个小写字母出现的次数
    int maxFreq = 0;
    
    for (int i = l - 1; i < r; i++) {
        freq[str[i] - 'a']++;
        if (freq[str[i] - 'a'] > maxFreq) {
            maxFreq = freq[str[i] - 'a'];
        }
    }
    
    return r - l + 1 - maxFreq;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char* str = (char*)malloc((n+1) * sizeof(char)); // 为字符串分配内存
    scanf("%s", str);

    int *l_arr = (int*)malloc(m * sizeof(int)); // 为l和r数组分配内存
    int *r_arr = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l_arr[i], &r_arr[i]);
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", minMagic(n, str, l_arr[i], r_arr[i]));
    }

    // 释放分配的内存
    free(str);
    free(l_arr);
    free(r_arr);
    return 0;
}
