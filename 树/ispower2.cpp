# include <iostream>
using namespace std;

 
int log2(int value)  //非递归判断一个数是2的多少次方 
{ 
  int x=0; 
  while(value>1) 
  { 
    value>>=1; 
    x++; 
  } 
  return x; 
} 
int Func3(int data) 
{  //利用了data&(data-1)每次都能移除最右边的1，移除了多少个1，就是包含了几个1 
  int count = 0; 
  while (data) 
  { 
    data = data & (data-1); 
    count++; 
  } 
  return count; 
} 

int main(void) 
{ 
  int num; 
  cout<<  "请输入一个整数：" << endl; 
  cin >> num; 
  int numofone;
  numofone = Func3(num);
  cout << numofone << endl;
  if(num&(num-1))   //使用与运算判断一个数是否是2的幂次方 
    cout<<num<<"不是2的幂次方!"<<endl; 
  else 
    cout<<num<<"是2的"<<log2(num)<<"次方！"<<endl;

  return 0; 
} 