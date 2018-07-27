//指针函数：带指针的函数，本质是一个函数，
//函数返回类型是某一类型的指针。
//声明格式：类型标识符 *函数名(参数表)
//示例： int *func(x,y)

#include <iostream>
//int,返回的是数组某元素的地址
//'c' --> 99
int *get_letter(int num)
{
    static int arr[] = {'a','b','c','d','e'};
    return &arr[num-1];
}
int main()
{
    int num;
    std::cin >> num;
    //将*get_letter(num)返回的数组的某元素的
    //地址的值转化为char类型输出
    std::cout<<(char)*get_letter(num)<<std::endl;
    system("pause");
    return 0;
}
//输入 3
//输出 c