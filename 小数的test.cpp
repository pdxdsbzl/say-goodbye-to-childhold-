#include <stdio.h>
#include <string.h>
#include <math.h>

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    return 0;
}

char intToChar(int n) {
    if (n >= 0 && n <= 9) {
        return n + '0';
    } else {
        return n - 10 + 'a';
    }
}

double convertToDecimal(int A, char* C) {
    int len = strlen(C);
    double decimal = 0.0;
    int point = strlen(C);
    for (int i = 0; i < len; i++) {
        if (C[i] == '.') {
            point = i;
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        if (i != point) {
            decimal += charToInt(C[i]) * pow(A, abs(point - i - 1));
        }
    }
    return decimal;
}

void convertToB(int B, int integerPart, double fractionPart, int precision) {
    char result[50];
    int i = 0;
    while (integerPart != 0) {
        result[i] = intToChar(integerPart % B);
        integerPart = integerPart / B;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }
    if (fractionPart > 0.0) {
        printf(".");
    }
    for (i = 0; i < precision; i++) {
        fractionPart *= B;
        int digit = floor(fractionPart);
        printf("%c", intToChar(digit));
        fractionPart -= digit;
    }
}

int main() {
    int A, B;
    char C[50];
   // printf("请输入A和B的值：");
    scanf("%d%d", &A, &B);
    //printf("请输入A进制数C：");
    scanf("%s", C);

    int integerPart = (int)convertToDecimal(A, C);
    double fractionPart = modf(convertToDecimal(A, C), &fractionPart);
    int precision = 8;
    //printf("转换为B进制数为：");
    convertToB(B, integerPart, fractionPart, precision);
    printf("\n");

    return 0;
}