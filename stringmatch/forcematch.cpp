# include <iostream>
#include <stdio.h>   
using  namespace std;
//pos是从1开始的一个下标
int index_force(char * s, char * t,int pos)
{

    int i=pos-1;
    //判断pos是否合法
    if(!s[i])
    cout<<"起始位置不合法"<<endl;
    int j=0;
    while(s[i]!='\0' && t[j]!='\0')//主串或者模式串遍历完成
    {
        if(s[i]==t[j])//如果主串和模式串对应位置的值相等，则比较后面的字符
        {
            ++i;
            ++j;
        }
        else    //如果不相等，则模式串需要回朔到第一个字符，而主串则从下一个字符开始
        {
            i=i-j+1;
            j=0;
        }
    }
    if(t[j]=='\0')//如果循环是由于模式串遍历完了而结束的，说明找到了对应子串的位置
    {
        return i-j+1;
    }
    else        //否则，主串不包含模式串
    {
        return 0;
    }
}

int main(void)
{
    char *s;
    s= (char*)" helsssssssssspllo";
    char *t;
    t= (char*)"ll";
    int pos = 1;
    int res ;
    res = index_force(s, t, pos);
    cout << res << endl;
}