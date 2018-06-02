# include <stdio.h>

void sort(int number[],int N)
{
    int temp,j;
    for(int i=1;i<N;i++)//从小到大循环进行排序
    {
        temp=number[i];
        for(j=i;j>0;j--)
        {
            if(number[j-1]>temp)
            {
                number[j]=number[j-1];
                number[j-1] = temp;
            }
            else
            {
                break;
            }
        }
        //number[j]=temp;
    }
}
int main()
{
    int tempdata[] = {1,0,5,7,2,4,8,11,22,-1,100000000};
    int n = 11;
    sort(tempdata,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",tempdata[i]);
    }
    return 0;
}