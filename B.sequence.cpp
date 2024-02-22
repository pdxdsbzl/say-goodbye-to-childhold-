#include <stdio.h>
#include <string.h>

#define MAXN 200005

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char s[MAXN];
        scanf("%s", s);

        int distinctCount[26] = {0};
        int totalDistinct = 0;
        int maxSum = 0;

        for (int i = 0; i < n; i++) {
            if (distinctCount[s[i] - 'a'] == 0) {
                totalDistinct++;
            }
            distinctCount[s[i] - 'a']++;
            maxSum = max(maxSum, totalDistinct);
        }

        maxSum = max(maxSum, totalDistinct - 1 + min(distinctCount[s[0] - 'a'], distinctCount[s[n-1] - 'a']));

        printf("%d\n", maxSum);
    }

    return 0;
}