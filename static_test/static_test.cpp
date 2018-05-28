# include <stdio.h>
# include <iostream>
using namespace std;

void play()
{
    int c = 0;
    static int x = c;
}
void changeplay()
{
    static  int x = 3;
}
int x = 4;
int main()
{
    static int x = 0;
    play();
    changeplay();
    printf("%d",x);
}