// 有一个国家发现了5座金矿，每座金矿的黄金储量不同，需要参与挖掘的工人数也不同。
// 参与挖矿工人的总数是10人（第二集说的是1000人，这里改动一下）。每座金矿要么全挖，
// 要么不挖，不能派出一半人挖取一半金矿。要求用程序求解出，要想得到尽可能多的黄金，
// 应该选择挖取哪几座金矿？

// 动态规划的三个核心要素:
// - 最优子结构 
// - 边界条件
// - 状态转移方程式

//金矿n<=1，且人数w<金矿需要的人数
//F(n,w) = 0 (n<=1,w<p[0]);

// 金矿n==1,人数>=p[0]
// F(n,w) = g[0] (n==1,w>=p[0])

// 金矿数目 n>1, 人数w < p[n-1]，所以根据多态规划
// 的最优子结构:
// F(n,w) = F(n-1,w) (n>1,w<p[n-1])(人数不够挖第n个矿)

// 另外一种情况 w>=p[n-1]

// F(n,w) = max (F(n-1,w),F(n-1,w-p[n-1])+g[n-1])(n>1,w>=p[n-1])

# include <iostream>
# include <memory.h>
using namespace std;
//简单递归法
//时间复杂度 O(2^n)
//空间复杂度 O(n)
//还没写出来
// int triangle_summax(int i,int j)
// {
//     if(i == n)
//     {
//         return D[i][j];
//     }
//     int x = triangle_summax(i+1,j);
//     int y = triangle_summax(i+1,j+1);
//     return max(x,y) + D[i][j];
// }
int recusive_Gold(int n,int w,int g[],int p[])
{
    if(n == 0)
    {
        return g[0];
    }
    return max(recusive_Gold(n,w,g,p),recusive_Gold(n-p[n-1],w,g,p)+g[n-1]);
}
//动态规划法
//时间复杂度 O(n*w)
//空间复杂度 O(w)
int getMostGold(int n,int w,int g[],int p[])
{
   int preResults[w];
   int results[w];
   //填充边界格子的值
   for(int i=0;i<w;i++)
   {
        preResults[i] = 0;
   }
   for(int i=0;i<n;++i)
   {
       for(int j=0;j<w;++j)
       {
           if(j+1<p[i])
           {
               results[j] = preResults[j];
               //cout << results[j] << endl;
           }
           else 
           {
               results[j] = max(preResults[j],preResults[j-p[i]]+g[i]);
               //cout << i<<'o'<<preResults[j] <<"lsk"<<j<<"j"<<p[i]<<"jjhs"<<preResults[j-p[i]]<<"+"<< g[i] <<"dd"<<results[j]<< endl;
           }
       }
    //    for(int i=0;i<w;++i)
    //    {
    //        preResults[i] = results[i];
    //        //每次将这次的result保存为preresult,实现一位的滚动保存。
    //    }
       memcpy(preResults,results,w*sizeof(int));
   }
   return results[w-1];
}

int main()
{
    int n = 5;
    int w = 10;
    int g[5] = {400,500,200,350,300};
    int p[5] = {5,5,3,3,4};
    int res = getMostGold(n,w,g,p);
    cout << res << endl;
}