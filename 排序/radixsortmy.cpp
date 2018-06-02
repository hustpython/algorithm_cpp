# include <iostream>
# include <stdio.h>

void sort(int data[],int n)
{
    int tempradix = 10;
    int d = 1;
    //统计data中最大的数的位数
    for(int i(0);i<n;i++)
    {
        while(data[i]>=tempradix)
        {
            tempradix *= 10;
            ++d;
        }
    }
    //对每个桶进行初始化
    int *temp = new int[n];
    int *count = new int[10];
    int radix = 1;
    for(int simradix = 1;simradix<=d;++simradix)
    {
        for(int i(0);i<10;i++)
        {
            count[i] = 0;
        }
        //按位的低高进行统计
        
        for(int i(0);i<n;++i)
        {
            int k = (data[i]/radix)%10;
            count[k] ++ ;
        }
        //保持一定的顺序
        for(int i(1);i<n;i++)
        {
            count[i] += count[i-1];
        }
        for(int i(n-1);i>=0;i--)
        {
            int k = (data[i]/radix) %10;
            temp[count[k]-1] = data[i];
            count[k]--;
        }
        for(int i(0);i<n;++i)
        {
            data[i] = temp[i];
        }
        radix *= 10;
    }
    delete []temp;
    delete []count;
}
int main()
{
    int tempdata[] = {1,3,5,7,2,4,8,11,100000000};
    int n = 9;
    sort(tempdata,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",tempdata[i]);
    }
    return 0;
}
