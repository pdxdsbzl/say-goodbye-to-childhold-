#include <stdio.h>
#include <string.h>
int main()
{
    char a[25];char b[] = "es";char c[] = "s";
    gets(a);
    int i,len;
    len = strlen(a);
   // printf("%d",len);!!!!!˵�������ַ������Ⱦ�����������ַ�������������Ϊ��ʼ��������25������!!!!!!!!!!!!!!
    if(a[len-1] == 'o' || a[len-1] == 'x' ||a[len-1] == 's')
    strcat(a,b);//��es�������
    else if(a[len-1] == 'y')//��βΪy�������
    {
        a[len-1] = 'i';
        strcat(a,b);
    }
    else if ((a[len-1] == 'h') &&((a[len-2] == 's')||(a[len-2]=='c')))
    strcat(a,b);
    else
    strcat(a,c);
    puts(a);
    return 0;
}

