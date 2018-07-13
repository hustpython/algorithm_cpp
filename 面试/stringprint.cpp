#include <stdio.h>
using namespace std;

int main()
{
    char *lines[5] = {(char *)"abc",(char *)"defh",(char *)"igklm",(char *)"opqret",(char *)"uvwxyz"};
    char *str1 = *(lines+2);
    char *str2 = (*lines+2);
    printf("%s\n%s\n",str1,str2);
}