#include <stdio.h>
int main() {
int n;
scanf("%d", &n);
int prices[n];
for (int i = 0; i < n; i++) {
    scanf("%d", &prices[i]);
}

// ʹ�ü�������ʱ�临�Ӷ�ΪO(n)
int count[101] = {0};
for (int i = 0; i < n; i++) {
    count[prices[i]]++;
}

// Ѱ������������Ӧ�ļ۸�
int max_profit = 0;
int price = 0;
for (int p = 100; p > 0; p--) {
    int total = 0;
    for (int j = p; j < 101; j++) {
        total += count[j];
    }
    if (total * p > max_profit) {
        max_profit = total * p;
        price = p;
    }
    else if (total * p ==max_profit&&price>p) {
        max_profit = total * p;
        price = p;
    }
}

printf("%d %d", max_profit, price);

return 0;

}