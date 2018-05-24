# include<stdio.h>
int main()
{
    int a[] = {1,0,0,1,1};
    for(int i=0;i<6;i++)
    {
        for(int j=i;j<6;j++)
        {
            if(a[j]!=0)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    for(int k=0;k<5;k++)
    {
        printf("%d",a[k]);
    }

}