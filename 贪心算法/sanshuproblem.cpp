// 给定n位正整数a，去掉其中任意k个数字后，剩下的数字按原次序排列组成一个新的正整数。 
// 对于给定的n和k，设计一个算法，找出剩下数字组成的新数最少的删数方案。 
// 输入示例：178543 4 
// 输出：13

# include <iostream>
# include<stdio.h>
# include<string.h>
# include <algorithm>
using namespace std;

string a = "5934625578";
int n = 6;

int main()
{
    char a[100];
    int n=4,i,j;
    printf("输入数字:\n"); 
    scanf("%s",a);  
    printf("输入要删除的位数：\n"); 
    scanf("%d",&n);
    if(n==strlen(a)){ //如果删除的位数=输入的数字位数,则为0
        printf("0");
        return 0; 
    } 

    while(n>0) {//直到要删除的位数为0
        i=0; //每次开始将i初始化为0，表示重新开始检测下降点 

        while(i<strlen(a) && a[i]<a[i+1])
            //在位数范围内，到了递减区间，就跳出循环
            i++;  
        for(j=i;j<strlen(a);j++) //后面往前挤一位，实现删除i位。
            a[j]=a[j+1];
        n--; 
    }  
    printf("%s\n",a);
    return 0;
}