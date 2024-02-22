#include <stdio.h>

long long ar[1000100] = {0};

long long maxt(int a, int b) {
    return a > b ? a : b;
}

int main() {
    long long t;
    scanf("%lld", &t);

    for (long long i = 0; i < t; i++) {
        long long n;
        scanf("%lld", &n);

        for (long long j = 0; j < n; j++) {
            scanf("%lld", &ar[j]);
        }

        long long max_val = 0;
        long long sum = 0;

        // Find the maximum value in the array
        for (long long j = 0; j < n; j++) {
            max_val = maxt(max_val, ar[j]);
        }

        // Calculate the sum using the maximum value
        for (long long j = 0; j < n; j++) {
            sum += 4 * max_val;
        }

        printf("%lld\n", sum);
    }

    return 0;
}