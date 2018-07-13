#include <iostream>
using namespace std;
//计算两个矩形重叠面积
typedef struct
{
    float x;
    float y;
    float w;
    float h;
}rect;

int main()
{
    rect r1 = {1,1,3,3};
    rect r2 = {2,2,4,4};
    float r1xmin = r1.x;
    float r1xmax = r1.x + r1.w;
    float r1ymin = r1.y;
    float r1ymax = r1.y + r1.h;

    float r2xmin = r2.x;
    float r2xmax = r2.x + r2.w;
    float r2ymin = r2.y;
    float r2ymax = r2.y + r2.h;

    float xmin = max(r1xmin,r2xmin);
    float xmax = min(r1xmax,r2xmax);
    float ymin = max(r1ymin,r2ymin);
    float ymax = min(r1ymax,r2ymax);
    float width = xmax - xmin;
    float height = ymax - ymin;
    if (width <= 0 || height <=0 )
    {
        return 0;
    }
    cout<< height * width << endl;


    return 0;
}