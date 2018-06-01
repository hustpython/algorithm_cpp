# include <iostream>
# include <stdio.h>
#define LENGTH(array)( (int)(sizeof(array)/sizeof(array[0])) )

void radixsort(int (&data)[7],int n)
{
    int d = 1;//最大位数,是d位数
    int p = 10;
    for(int i(0);i<n;++i)
    {
        printf("%d",data[i]);
        while(data[i]>=p)
        {
            p *= 10;
            ++d;         
        }
    }
    int *tmp = new int[n];
    int *count = new int[10];
    int i,j,k;
    int radix = 1;
    for(i=0;i<=d;i++)//进行第d次排序
    {
        for(j=0;i<10;j++)
        {
            count[j] = 0;
        }
        for(j=0;j<n;j++)
        {
            k = (data[j]/radix) % 10;
            count[k]++;
        }
        for(j=1;j<10;j++)
        {
            count[j] = count[j-1]+count[j];
        }
        for(j = n-1;j>=0;j--)
        {
            k = (data[j]/radix)%10;
            tmp[count[k]-1] = data[j];
            count[j]--;
        }
        for(j=0;j<n;j++)
        {
            data[j]=tmp[j];
        }
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}
int main()
{
    printf("%d",1);
    int tempdata[] = {1,3,5,7,2,4,8};
    printf("%d",1);
    int n = LENGTH(tempdata);
    printf("%d",1);
    //radixsort(tempdata,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",tempdata[i]);
    }
    return 0;
}
