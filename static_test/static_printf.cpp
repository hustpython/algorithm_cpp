# include<stdio.h>
# include <iostream>
using namespace std;

void printstatic()
{
    static int a = 123;
    a++;
    printf("%d\n",a);
}
void printauto()
{
    int a = 123;
    a++;
    printf("%d\n",a);
}
int main()
{
    printstatic();
    printstatic();
    printstatic();

    printauto();
    printauto();
    printauto();
}