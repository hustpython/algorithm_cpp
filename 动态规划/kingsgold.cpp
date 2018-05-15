#include<iostream>  
#include<vector>  
#include<algorithm>  
using namespace std;  
/* 
动态规划问题：maxgold[W] 
1、首先设计一个表格maxgold[W+1] 
2、初始化：当只有第1个金矿时，工人数量i从1开始增加到W时，maxgold[i]表示所能得到的最大金砖。 
3、当只有第1个和第2个金矿时，工人数量i也同样从1开始增加到W时， 
    maxgold[i]（已经根据状态转移方程进行修改了）表示所能得到的最大金砖。 
4、依次类推，当只有第1个、第2个、第3个、第4个、第5个金矿时，工人数量i也同样从1开始增加到W时， 
    maxgold[i]（已经根据状态转移方程进行修改了）表示所能得到的最大金砖。 
5、时间复杂度：O( N * W ) 
   空间复杂度：O( W ) 
*/  
int GetMaxGold(int N, int W, const vector<int> &G, const vector<int> &P)  
{  
    vector<int> premaxgold(W+1,0);            //设计一个结果表的前表  
    vector<int> maxgold(W+1,0);               //设计一个结果表  
    for(int i=1; i<=W; ++i)                  //按列 初始化结果表：当只有第一座金矿时，i代表i个工人  
    {  
        if(i<P[0])  
            premaxgold[i]=0;  
        else  
            premaxgold[i]=G[0];  
    }  
    //依次填充表格  
    for(int i=0; i<N; ++i)               //i表示有前i个金矿时  
    {  
        for(int j=1; j<=W; ++j)  
        {  
            if(j<P[i])  
                maxgold[j]=premaxgold[j];  
            else  
                maxgold[j]=max(premaxgold[j], premaxgold[j-P[i]]+G[i]);  
        }  
        premaxgold=maxgold;  
    }  
    return maxgold[W];  
}  
  
int main(void)  
{  
    int N=5;                            //5个金矿  
    int W=10;                           //10个人:900  
    //int W=13;                         //13个人:1250  
    //int W=1;                          //1个人:0  
    //int W=3;                          //3个人:350  
    //int W=7;                          //7个人:650  
    int g[]={400,500,200,300,350};  
    vector<int> G(g,g+5);       //每座金矿的含金量  
    int p[]={5,5,3,4,3};  
    vector<int> P(p,p+5);       //每座金矿需要的人数  
    int maxGold=GetMaxGold(N,W,G,P);  
    cout<<maxGold<<endl;  
    return 0;  
}  

