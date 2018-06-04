# include<iostream>
# include<stdio.h>
using namespace std;
//通过 | << 操作将数字记录到a中
//然后通过右移与1 操作，若结果为 1 则表示
//a中存在 val，否则不存在
int main()
{
    int a = 0;
    a |= (1<< 2);
    a |= (1<< 3);
    cout << (a>>13)&&1;
}