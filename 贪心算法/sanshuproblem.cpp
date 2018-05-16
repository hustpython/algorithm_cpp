#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//5934625578
//6
//2557
int main()
{
    int a, b, len, n;
    char m[123];//输入的字符串（由于长度很长，不用int或long long int)
    while(~scanf("%s %d", m, &b))//多组输入
    {
        while(b--)//共删掉b个数
        {
            a = 0;
            len = strlen(m);
            while(a<len&&m[a]<=m[a+1])//寻找第一个递减的数字
                a++;
            while(a<len)//找到后，将其后的字符向前移动一位（相当于删掉）
            {
                m[a] = m[a+1];
                a++;
            }
        }//利用此方法可以使得删掉数字后剩下的数最小
        len = strlen(m);//删完后的长度
        n = 0;
        while(m[n]=='0'&&n<len)//去掉可能存在‘000’这样的情况
            n++;
        if(n==len)//数字为零
            printf("0\n");
        else//输出剩余的数字
        {
            for(; n<len; n++)
                printf("%c", m[n]);
            printf("\n");
        }
    }
    return 0;
}