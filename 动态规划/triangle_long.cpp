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

int triangle_summax(int i,int j)
{
    if(i == n)
    {
        return D[i][j];
    }
    int x = triangle_summax(i+1,j);
    int y = triangle_summax(i+1,j+1);
    cout << x<<'l'<<y<<'j'<<max(x,y)<<'s'<<D[i][j]<<endl;
    return max(x,y) + D[i][j];
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
        }
    }
    input.close();
    cout << triangle_summax(1,1)<<endl;
}