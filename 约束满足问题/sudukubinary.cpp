# include <iostream>
# include <vector>
# include <stdlib.h>
# include <cstring>
# include <fstream>
# include <sstream>
# include <algorithm>
using namespace std;
class Solution {  
private:  
    int row[9], col[9], sqr[3][3];  
    bool check(int x, int y, int val) {  
        return !((row[x]>>val)&1) && !((col[y]>>val)&1) && !((sqr[x/3][y/3]>>val)&1);  
    }  
    void mark(int x, int y, int val, vector<vector<char> > &board) {  
        row[x] |= (1<<val); //通过左移操作将第x行中的数字“记录”
        col[y] |= (1<<val); //通过左移操作将第y列中的数字“记录”
        sqr[x/3][y/3] |= (1<<val);//通过左移操作将第x/3,y/3(0,0;0,1,...)个九宫格中的数字“记录”
        board[x][y] = val + '1'; //将board中的char设置为val
    }  
    void unmark(int x, int y, int val, vector<vector<char> > &board) {  
        row[x] -= (1<<val);//移除row中的val记录
        col[y] -= (1<<val);  
        sqr[x/3][y/3] -= (1<<val);  
        board[x][y] = '.';  
    }  
    bool dfs(int pos, vector<vector<char> > &board) {  
        // x = pos / 9, y = pos % 9  
        if (pos == 81)  
            return true;  
        if (board[pos/9][pos%9] != '.') {  
            return dfs(pos + 1, board);  
        } else {  
            for (int i = 0; i < 9; i++)  
                if (check(pos/9, pos%9, i)) {  
                    mark(pos/9, pos%9, i, board);  
                    if (dfs(pos + 1, board))  
                        return true;  
                    unmark(pos/9, pos%9, i, board);  
                }  
        }  
        return false;  
    }  
public:  
    void solveSudoku(vector<vector<char> > &board) {  
        memset(row, 0, sizeof(row));  
        memset(col, 0, sizeof(col));  
        memset(sqr, 0, sizeof(sqr));  
        for (int i = 0; i < board.size(); i++)  
            for (int j = 0; j < board[i].size(); j++)  
                if (board[i][j] != '.') {  
                    mark(i, j, board[i][j] - '1', board);  
                }  
        dfs(0, board);  
    }  
}; 
void readcsv(vector<vector<char> > &board)
{
    ifstream inFile("sudukubininput.csv");//ifstream;
    string lineStr;//每一行
    while(getline(inFile,lineStr))
    {
        stringstream sudustr(lineStr);//将行字符串转换为字符串数据流
        string suduchar;
        vector<char> tempsuduchar;
        while(getline(sudustr,suduchar,','))
        {
                tempsuduchar.push_back(suduchar[0]);
        }
        
        board.push_back(tempsuduchar);
    }
}
void printboardchar(vector<char>suduint)
{
    for(char a:suduint)
    {
        printf("%c ",a);
    }
    printf("\n");
}
int main()
{
    vector< vector<char> > board;
    readcsv(board);
    //for_each(board.begin(),board.end(),printboardchar);
    Solution s;
    s.solveSudoku(board);
    for_each(board.begin(),board.end(),printboardchar);
}