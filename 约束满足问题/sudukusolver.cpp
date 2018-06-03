# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <string>
# include <stdio.h>
using namespace std;
vector<vector<int> > board;
bool sign = false;
void readcsv()
{
    ifstream inFile("sudukuinput.csv"); 
    string lineStr;
    while(getline(inFile,lineStr))
    {
        stringstream sudustr(lineStr);
        string suduint;
        vector<int> tempsuduint;
        while(getline(sudustr,suduint,','))
        {
            int tempint = int(suduint[0] - '0');
            if(tempint >= 1 && tempint <= 10)
            {
                tempsuduint.push_back(tempint);
            }
            else
            {
                tempsuduint.push_back(0);
            }
        }
        
        board.push_back(tempsuduint);
    }
}
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
bool check(int n,int key)
{
    for(int i=0;i<9;i++)
    {
        int j = n / 9;
        if(board[j][i] == key)
        {
            return false;
        }
    }
    for (int i=0;i<9;i++)
    {
        int j=n%9;
        if(board[i][j] == key)
        {
            return false;
        }
    }
    int x = n / 9 / 3 * 3;
    int y = n % 9 / 3 * 3; 
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
    if(n>80)
    {
        sign = true;
        return 0;
    }
    if(board[n/9][n%9] != '\0')
    {
        DFS(n+1);
    }
    else 
    {
        for(int i=1;i<=9;i++)
        {
            if(check(n,i) == true)
            {
                board[n/9][n%9] = i;
                DFS(n+1);
                if(sign == true)
                {
                    return 0;
                }
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