// 问题描述：

//            7

//        3       8

//    8       1        0

// 2      7       4          4

//在上面的数字三角形中寻找一条从顶部到底边的路径，
//使得路径上所经过的数字之和最大。路径上的每一步
//都只能往左下或右下走。只需要求出这个最大和即可，
//不必给出具体路径。

//三角形的行数大于1小于等于100，数字为0~99.

// 输入格式：

// 4 ///三角形的行数。下面是三角形

// 7

// 3 8

// 8 1 0

// 2 7 4 4

# include <iostream>
# include <fstream>
using namespace std;

# define Max 101
int n;
int D[Max][Max];
//简单递归
//从塔顶到基座的递归,边界是遍历到底座的元素
//res = max(x,y) + D[i][j]
//边界条件是递归到三角形最后一层
//max(sum(2.1),sum(2.2))+D[1.1]
//sum(2.1) = max(sum(3.1),sum(3.2))+D[2.1]
//sum(3.1) = max(sum(4.1),sum(4.2))+D[3.1]
//sum(3.2) = max(sum(4.2),sum(4.3))+D[3.2]
//sum(4.1) = D[4.1] = 2;sum(4.2) = D[4.2] = 7;sum(4.3) = D[4.3] = 4
//sum(3.1) = 7+D[3.1] = 7 + 8 =15;
//sum(3.2) = 7 + 1 = 8;
//sum(2.1) = 15 + 3 = 18;
//////////////////////////////////////////
//同理可以求得sum(2.2) = 8+8 = 16
//sum(1.1) = 18 + D[1.1] = 18 + 7 = 25;

int triangle_summax(int i,int j)
{
    if(i == n)
    {
        return D[i][j];
    }
    int x = triangle_summax(i+1,j);
    int y = triangle_summax(i+1,j+1);
    return max(x,y) + D[i][j];
}
//备忘录法
int memory[Max][Max];
int memory_triangle(int i,int j)
{
    if(memory[i][j] != -1)
    {
        return memory[i][j];
    }
    if(i == n)
    {
        memory[i][j] = D[i][j];
    }
    else
    {
        int x = triangle_summax(i+1,j);
        int y = triangle_summax(i+1,j+1);
        memory[i][j] = max(x,y) + D[i][j];
    }
    return memory[i][j];

    

}
//动态规划,递归到递推
//从底座到塔尖
int dymax[Max][Max];
int ditui_triangle()
{
    
    for(int k=1;k<=n;++k)
    {
        dymax[n][k] = D[n][k];
    }
    for(int i = n-1;i>=1;--i)
    {
        for(int j = 1;j<=i;++j)
        {
            dymax[i][j] = max(dymax[i+1][j],dymax[i+1][j+1]) + D[i][j];
        }
    }
    return dymax[1][1];
    
}

int *dymax_one;
int ditui_triangle_oned()
{
    
    dymax_one = D[n];
    for(int i = n-1;i>=1;--i)
    {
        for(int j = 1;j<=i;++j)
        {
            dymax_one[j] = max(dymax_one[j],dymax_one[j+1]) + D[i][j];
        }
    }
    return dymax_one[1];  
}
int main()
{
    ifstream input("triangle_input.txt");
    input >> n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            input>>D[i][j];
            memory[i][j] = -1;
        }
    }
    
    input.close();
    //cout << triangle_summax(1,1)<<endl;
    //cout << memory_triangle(1,1)<<endl;
    //cout << ditui_triangle() <<endl;
    cout << ditui_triangle_oned() <<endl;
}