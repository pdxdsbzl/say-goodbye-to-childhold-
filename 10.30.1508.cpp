#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main() 
{
    int n, bag;//nΪ���������bagΪ��������
    printf("\n��������������ͱ���������\n");
    scanf("%d %d",&n,&bag);
    int w[100];//ÿ����������
	int v[100];//ÿ�������ֵ
    printf("����������ÿ������������ͼ�ֵ��\n");
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }
	int maxvalue[100][100] = {0};//��̬�滮��
    //�Ʊ�
	for (int i = 1; i <= n; i++) 
    {
		for (int wight = 1; wight <= bag; wight++)
        {
			if (wight < w[i])
				maxvalue[i][wight] = maxvalue[i-1][wight];
			else
				maxvalue[i][wight] = max(maxvalue[i-1][wight], maxvalue[i-1][wight-w[i]] + v[i]);
		}
	}
    //���
    printf("w i g h t: ");
    for(int wight=1; wight <= bag; wight++) printf("%-3d", wight);
    printf("\n");
    for(int i = 1; i <= n; i++)
    {
        printf("w%d,v%-3di=%d ", w[i],v[i], i);
        for(int wight = 1; wight <= bag; wight++)
        {
            printf("%-3d", maxvalue[i][wight]);
        }
        printf("\n");
    }
    printf("\n");
    //������ֵ
    printf("MAX=%d\n", maxvalue[n][bag]);
    //���ֵ����
    int judge[100] = {0};
    int x = n, y = bag;
    while(x != 0 && y != 0)
    {
        if(maxvalue[x][y] != maxvalue[x-1][y])
        {
            judge[x]++;
            y-=w[x];
            x--;
        }
        else x--;
    }
    //�����������������
    for(int i = 1; i <= n; i++)
    {
        if(judge[i]) printf("NO.%d wight%d value%d\n", i, w[i], v[i]);
    }
}
