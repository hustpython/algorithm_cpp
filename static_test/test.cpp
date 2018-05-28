
#include<iostream>  
using namespace std;  
  
class Point  
{  
public:  
    Point(int xx = 0, int yy = 0) { X = xx; Y = yy; countP ++; }  
    Point(Point &p);   
    ~Point() { countP --; }  
    int GetX() { return X; }  
    int GetY() { return Y; }  
    void GetC() { cout << "Object id = " << countP << endl; } //输出静态数据成员  
private:  
    int X, Y;  
    static int countP; //静态数据成员声明，用于记录点的个数  
};  
  
Point :: Point(Point &p)  
{  
    X = p.X;  
    Y = p.Y;  
    countP ++; //在构造函数中对countP累加，所有对象共同维护同一个countP  
}  
  
int Point :: countP = 0; //静态数据成员定义和初始化，使用类名限定  
  
int main()  
{  
    Point A(4, 5); // 定义对象A，其构造函数会使countP增1  
    A.GetC(); //输出对象个数  
    Point B(A); //定义对象B，其构造函数会使countP增1  
    B.GetC();  
    Point C(B);
    C.GetC();
  
    return 0;  
} 