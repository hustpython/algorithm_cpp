//题目描述,计算[1,n]中有多少个"1"；
//举例:[1,5]只有一个1:1；
//[1,11]中有1,10,11，三个数中一共有4个1；

#include<iostream>  
using namespace std;  
  
int Sum1s(int n)  
{  
    int count = 0; //记录1的个数  
    int factor = 1; //标记，逐位计算1的个数  
  
    int LowerNum = 0;  
    int CurrNum = 0;  
    int HigherNum = 0;  
  
    while ( n/factor != 0)        //每次计算LowerNum CurrNum HigherNum的值  
    {   
        LowerNum = n - (n/factor) * factor;  
        CurrNum = (n/factor) % 10;  
        HigherNum = n / (factor*10);  
        cout << LowerNum <<","<< CurrNum <<","<< HigherNum<<"," << endl;
        switch (CurrNum)  
        {  
        case 0:  
            count += HigherNum * factor;  
            break;  
        case 1:  
            count += HigherNum * factor + LowerNum +1;  
            break;  
        default:  
            count += (HigherNum +1)*factor;  
            break;  
        }  
        factor *= 10;  
    }  
    
    return count;  
}  
  
int  main()  
{  
    cout<<Sum1s(123)<<endl;  
} 
