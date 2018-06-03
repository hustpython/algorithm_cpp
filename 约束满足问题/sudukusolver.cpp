# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <string>
# include <stdio.h>
using namespace std;
vector<vector<int> > board;
//构造完成标志
bool sign = false;
void readcsv()
{
    ifstream inFile("sudukuinput.csv");//ifstream;
    string lineStr;//每一行
    while(getline(inFile,lineStr))
    {
        stringstream sudustr(lineStr);//将行字符串转换为字符串数据流
        string suduint;
        vector<int> tempsuduint;
        while(getline(sudustr,suduint,','))
        {
            int tempint = int(suduint[0] - '0');//将char转化为int
            if(tempint >= 1 && tempint <= 10)//1-9之间的数据
            {
                tempsuduint.push_back(tempint);
            }
            else //空格数据用0代替
            {
                tempsuduint.push_back(0);
            }
        }
        
        board.push_back(tempsuduint);
    }
}
// 将补全的数独矩阵写入excel文件中
void writecsv()
{
    ofstream outFile("outsuduku.csv");
    for(vector<int> row :board)
    {
        for(int cell :row)
        {
            outFile<<cell<<",";
        }
        outFile<<endl;
    }
    outFile.close();
}
//打印每一行
void printboardint(vector<int>suduint)
{
    for(int a:suduint)
    {
        // if(a=='\0')
        // {
        //     printf("ss");
        // }
        printf("%d ",a);
    }
    printf("\n");
}
//判断key填入第n个格子时是否满足条件
bool check(int n,int key)
{
    //判断n所在的行是否合法
    for(int i=0;i<9;i++)
    {
        int j = n / 9;
        if(board[j][i] == key)
        //如果n所在的行当中已经有为key的数存在，则不合法
        {
            return false;
        }
    }
    //判断n所在的列是否合法
    for (int i=0;i<9;i++)
    {
        int j=n%9;
        //如果n所在的列当中已经有为key的数存在，则不合法
        if(board[i][j] == key)
        {
            return false;
        }
    }
    int x = n / 9 / 3 * 3;//每一个小九宫格的左上角的n的横坐标，注意15/9/3*3 = 0,每步取整
    int y = n % 9 / 3 * 3;//每一个小九宫格的左上角的n的纵坐标
    //判断每一个小九宫格中是否已经存在相同的元素
    for(int i = x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(board[i][j] == key)
            {
                return false;
            }
        }
    }
    return true;
}
int DFS(int n)
{
    //所有的都符合，退出递归
    if(n>80)
    {
        sign = true;
        return 0;
    }
    //当前位已经有合法数字，跳过
    if(board[n/9][n%9] != 0)
    {
        //搜索下一位
        DFS(n+1);
    }
    else 
    {
        //对当前位进行枚举
        for(int i=1;i<=9;i++)
        {
            //满足条件时填入数字
            if(check(n,i) == true)
            {
                board[n/9][n%9] = i;
                //继续搜索下一位
                DFS(n+1);
                //当所有格子都被合法数字填满,退出
                if(sign == true)
                {
                    return 0;
                }
                //构造不成功，还原当前位,重新枚举,填写下一位合法数字
                board[n/9][n%9] = 0;
            }
        }
    }
    return 0;
}
int main()
{
    readcsv();
    //for_each(board.begin(),board.end(),printboardint);
    DFS(0);
    for_each(board.begin(),board.end(),printboardint);
    writecsv();
}