//函数指针是指向函数的指针变量
//本质是一个指针变量
//int (*f_p)(int x);//声明一个函数指针
//f_p = func;//将func函数首地址赋值给指针f_P
#include <iostream>

void (*f_p)();
void FileFunc(){std::cout<<"FileFunc"<<std::endl;}
void EditFunc(){std::cout<<"EditFunc"<<std::endl;}

int main()
{
    f_p = FileFunc;
    (*f_p)();//第一种调用方式
    f_p = EditFunc;
    f_p();
    system("pause");
    return 0;
}