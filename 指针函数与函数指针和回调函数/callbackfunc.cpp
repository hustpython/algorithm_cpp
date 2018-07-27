// 回调函数是通过函数指针调用的函数：
// 把函数的指针（地址）作为参数传递给另
// 一个函数，当这个指针被用来调用其所指向
// 的函数时，就称为回调函数。回调函数不是
// 由该函数的实现方直接调用，而是在特定的
// 事件或条件发生时由另外的一方调用的，
// 用于对该事件或条件进行响应。

#include <iostream>

typedef void(*Fun_p)(int);
Fun_p p = NULL;

void registerFun(Fun_p pCallback)
{
    p = pCallback;
}
//达成某一个条件后,通过名片(函数指针p)，传回结果
void trigger(int result)
{
    (*p)(result);//将result传入当前函数指针(*p)所
                 //指向的函数(callback函数)
}
//回调函数
void callback(int a)
{
    std::cout << "callback result = "<<a<<std::endl;
}
int main(int argc,char **argv)
{
    registerFun(callback);
    int result = 1;
    trigger(result);
    system("pause");
    return 0;
}
//输出：callback result = 1

//typedef int (* Fun_p)(void);定义了一个新类型 Fun

//Fun_p p = NULL;//用Fun_p定义一个变量p，p的类型是void (*Fun_p)(int)这样一个函数指针类型。