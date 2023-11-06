#include <stdio.h>
#include <string.h>
int main()
{
    char a[25];char b[] = "es";char c[] = "s";
    gets(a);
    int i,len;
    len = strlen(a);
   // printf("%d",len);!!!!!说明这里字符串长度就是你输入的字符！！他不会因为初始化定义有25个！！!!!!!!!!!!!!!!
    if(a[len-1] == 'o' || a[len-1] == 'x' ||a[len-1] == 's')
    strcat(a,b);//加es的情况。
    else if(a[len-1] == 'y')//结尾为y的情况。
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

