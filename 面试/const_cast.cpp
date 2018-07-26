//const_cast用法
// const_cast的目的并不是为了让你去修改一个本身被定义为const的值，
// 因为这样做的后果是无法预期的。const_cast的目的是修改一些指针/引用的权限，
// 如果我们原本无法通过这些指针/引用修改某块内存的值，现在你可以了。
#include<iostream>
using namespace std;

void test1()
{
    const int a = 12;
    const int *ap = &a;
    //(*ap) ++ ;报错
    //*ap = 12
    //*ap = 12
    //int* tmp = ap;报错,不能将const int 转换为 int
    int* tmp = const_cast<int*>(ap);
    *tmp = 21;
    (*tmp)++;
    cout << *ap<<","<<a<<endl;
    //*ap = 22,a = 12
}
void test2()
{
    const int ap = 12;
    //*ap = 12
    //int* tmp = ap;报错,不能将const int 转换为 int
    int* tmp = const_cast<int*>(&ap);
    *tmp = 21;
    cout <<ap<<","<<*tmp;
    //*ap = 12,*tmp = 21
}

int main(int argc, char const *argv[]) 
{
    test1();
    test2();
}
