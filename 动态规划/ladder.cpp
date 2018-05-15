# include <iostream>
# include <map>
using namespace std;
// 题目描述:
// 有20层的梯子，上楼时可以一次走一步或一次走两步。
// 请问，一共有多少上楼方式。

//方法一：简单递归 O(2^n)
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
int ladder_mapsearch(int num,map<int,int> &cmap)
//方法二：备忘录算法
//使用递归会重复计算，可以通过map将计算过的节点保存
//在每次计算之前进行查询。
//时间复杂度和空间复杂度都是 O(n)
{
    if (num == 1)
    {
        return 1;
    }
    else if(num == 2)
    {
        return 2;
    }
    map<int,int>::iterator key = cmap.find(num);
    if(key != cmap.end())
    {
        return key->second;
    }
    else
    {
        int value = ladder_mapsearch(num - 1,cmap) + ladder_mapsearch(num - 2,cmap);
        cmap.insert(make_pair(num,value));
        return value;
    }
    
    
}
//方法三：动态规划
//从底向上，时间复杂度为O(n)，空间复杂度为O(1)
int ladder_downtoup(int num)
{
    int a = 1;
    int b = 2;
    int temp = 0;
    for(int i =3;i<=num;++i)
    {
        
        temp = a + b;
        a = b;
        b = temp;
    }
    return temp;
}
int main()
{
    map<int,int> cmap;
    //int res = ladder_mapsearch(20,cmap);
    int res = ladder_downtoup(20);
    cout << res << endl;
}