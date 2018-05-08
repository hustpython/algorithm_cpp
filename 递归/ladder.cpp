# include <iostream>
using namespace std;
// 题目描述:
// 有20层的梯子，上楼时可以一次走一步或一次走两步。
// 请问，一共有多少上楼方式。

int ladderres(int num)
{

    if (num == 1)
    {
        return 1;
    }
    else if(num == 2)
    {
        return 2;
    }
    else 
    {
        return (ladderres(num-1)+ladderres(num-2));
    }
}
int main()
{
    int res = ladderres(20);
    cout << res << endl;
}