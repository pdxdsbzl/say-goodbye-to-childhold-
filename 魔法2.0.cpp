#include <stdio.h>
#include <stdlib.h>

int minMagic(int n, char* str, int l, int r) {
    int freq[26] = {0}; // ������¼ÿ��Сд��ĸ���ֵĴ���
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

    char* str = (char*)malloc((n+1) * sizeof(char)); // Ϊ�ַ��������ڴ�
    scanf("%s", str);

    int *l_arr = (int*)malloc(m * sizeof(int)); // Ϊl��r��������ڴ�
    int *r_arr = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l_arr[i], &r_arr[i]);
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", minMagic(n, str, l_arr[i], r_arr[i]));
    }

    // �ͷŷ�����ڴ�
    free(str);
    free(l_arr);
    free(r_arr);
    return 0;
}
