# include<iostream>
# include<stdio.h>
using namespace std;

int main()
{
    int a = 0;
    a |= (1<< 2);
    a |= (1<< 3);
    cout << (a>>13)&&1;
}