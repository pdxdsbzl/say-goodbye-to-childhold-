
//这是找的题解哦，他的find和replace挺好的
#include <bits/stdc++.h>
//#include<stdio.h>
//#include<string.h>
using namespace std;
string s;
int kb, kg;
int cs(string t)//在字串s中找子串t
{
    int k = 0, len = t.size(), fi = s.find(t);
    while (fi != -1)//只要有这个子串
    {
        k++;//计数
        s.replace(fi, len, "*"); //等长替换，不要用erase
        fi = s.find(t, fi + 1);//下个位置开始找
    }
    return k;
}
int main()
{
    cin >> s;
    kb = cs("boy") + cs("bo") + cs("oy") + cs("b") + cs("o") + cs("y");
    kg = cs("girl") + cs("gir") + cs("irl") + cs("gi") + cs("ir") + cs("rl") + cs("g") + cs("i") + cs("r") + cs("l");
    cout << kb <<endl << kg << endl;
    return 0;
}