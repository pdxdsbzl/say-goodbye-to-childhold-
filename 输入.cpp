#include <stdio.h>
#include <string.h>
int main()
{
    int N, i;
    scanf("%d\n", &N);
    char str[N][90];
    for(i = 0; i < N; i++)
    {
    	gets(str[i]);
	}
    for(int k=0;k<N;k++)
    {
    	puts(str[k]);
	}
    return 0;
}