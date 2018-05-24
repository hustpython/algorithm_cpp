// problem description:
// You are supposed write a program to solve this puzzle:

//   s e n d
// + m o r e
// ---------
// m o n e y
// Each letter correspond to a different digit between 0 and 9.
// Before you continue reading this post, try to think about how 
// you would approach this problem.
# include<vector>
# include<stdio.h>
# include<iostream>
//#pragma G++ diagnostic error "-std=c++11" 
using namespace std;

using myIntVec = char; 
typedef vector<int> a; 
void testUsing2()  
{  
    myIntVec mvec[10]  { '1', '2', '3', '4', '5' };  
    a c  {1,2,3};
    c.push_back(4);  
    for(auto it=c.begin();it!=c.end();++it)
    {
        printf("%d\n",*it);
    }
    for (char num : c)  
        printf("--- num:%d\n", num); 
    for (char cha : mvec)  
        printf("--- char:%c\n", cha);  
  
    std::cout << is_same < vector<int>, myIntVec>::value << std::endl; // 1  
} 
int main()
{
    testUsing2();
}