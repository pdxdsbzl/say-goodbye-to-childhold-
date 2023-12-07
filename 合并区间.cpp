//#include <stdio.h>
//int max(int a,int b)
//{
//	if(a>=b)
//	return a;
//	return b;
//}
//int main() 
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n][2];
//	int str[n][2] ;
//	int point = 0;
//	for (int i = 0; i <= n - 1; i++) 
//	{
//		scanf("%d%d", &arr[i][0], &arr[i][1]);
//		if (i >= 1) 
//		{
//			if (arr[i][0] <= arr[i - 1][1]) 
//			{
//				point++;
//				str[i - point][1] = max(arr[i][1],str[i-point][1]);
//			} 
//			else 
//			{
//				str[i - point][0] = arr[i][0];
//				str[i - point][1] = arr[i][1];
//			}
//		} 
//		else 
//		{
//			str[i][0] = arr[i][0];
//			str[i][1] = arr[i][1];
//		}
//	}
//	for (int i = 0; i <= n - point - 1 ; i++) 
//	{
//		printf("%d %d\n", str[i][0], str[i][1]);
//	}
//	return 0;
//}



#include <stdio.h>

typedef struct {
    int start;
    int end;
} Fib;

void mud(Fib fat[], int n) {
    if (n <= 0) {
        return;
    }

    Fib result[n];
    int size = 0;
    result[size++] = fat[0];

    for (int i = 1; i < n; i++) {
        if (fat[i].start > result[size - 1].end) {
            result[size++] = fat[i];
        } else if (fat[i].end > result[size - 1].end) {
            result[size - 1].end = fat[i].end;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Fib fat[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &fat[i].start, &fat[i].end);
    }

    mud(fat, n);

    return 0;
}