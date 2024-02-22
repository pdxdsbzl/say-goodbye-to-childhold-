#include <stdio.h>

#define MAX_N 10
#define MAX_M 10

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int scores[MAX_N];
        for (int i = 0; i < n; i++) {
            scanf("%d", &scores[i]);
        }

        int matches[MAX_M][2];
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &matches[i][0], &matches[i][1]);
            // Decrement the match indices to 0-based
            matches[i][0]--;
            matches[i][1]--;
        }

        int zhaChickenScore = scores[0];
        int rank = 1;

        for (int i = 0; i < n; i++) {
            if (scores[i] > zhaChickenScore) {
                rank++;
            } else if (scores[i] == zhaChickenScore) {
                for (int j = 0; j < m; j++) {
                    if ((matches[j][0] == i && matches[j][1] == 0) || (matches[j][1] == i && matches[j][0] == 0)) {
                        rank++;
                        break;
                    }
                }
            }
        }

        printf("%d\n", rank);
    }

    return 0;
}