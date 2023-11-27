#include <stdio.h>
#include <string.h>

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    char str1[n][m];
    char str2[m];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", str1[i]);
    }
    
    scanf("%s", str2);
    
    int u = 0;
    
    for (int i = 0; i < n; i++) {
        int v = 0;
        
        for (int j = 0; j < m; j++) {
            if (str1[i][j] != str2[j]) {
                v++;
            }
        }
        
        if (v <= k) {
            u++;
        }
    }
    
    printf("%d\n", u);
    
    return 0;
}
