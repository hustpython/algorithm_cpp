# include "Dijkstra.h"
# include<limits.h>
# include<iostream>
# include<string.h>
#include <stdio.h>

using namespace std;

//构造函数,初始化邻接矩阵
Graph_DG::Graph_DG(int vexnum,int edge)
{
    //初始化顶点数和边数
    this -> vexnum = vexnum;
    this -> edge = edge;
    //为邻接矩阵开辟空间和赋初值
    //创建指针数组，可以动态定义多维数组
    // size =6;
    // column =5
    // int **p=new int*[size];
    //     for(int i=0;i<size;i++)
    // {
    //     p[i]=new int[Column];
    // }
    arc = new int*[this->vexnum];
    dis = new Dis[this->vexnum];
    for(int i = 0;i < this->vexnum;i++)
    {
        arc[i] = new int[this->vexnum];
        for(int k =0;k<this->vexnum;k++)
        {
            //邻接矩阵初始化为无穷大
            arc[i][k] = INT_MAX;
        }
    }
}
//析构函数
Graph_DG::~Graph_DG()
{
    delete[] dis;
    for(int i=0;i<this->vexnum;i++)
    {
        delete this->arc[i];
    }
    delete arc;
}
//判断我们每次输入的边的信息是否合法
//顶点从1开始编号
bool Graph_DG::check_edge_value(int start,int end,int weight)
{
    //不合法包括:输入的边的起点终点的编号小于1；编号大于顶点数目；权重小于0
    if(start<1 || end <1 || start>vexnum || end>vexnum || weight<0)
    {
        return false;
    }
    return true;
}
//对图邻接矩阵赋予输入的值
void Graph_DG::createGraph()
{
    cout<< "请输入每条边的起点和终点(顶点编号从1开始)以及其权重" << endl;
    int start;
    int end;
    int weight;
    int count = 0;
    while(count != this -> edge)
    {
        cin >> start >> end >> weight;
        //判断输入的边是否合法
        while(!this->check_edge_value(start,end,weight))
        {
            cout << "输入的边的信息不合法，请重新输入" << endl;
            cin >> start >> end >> weight;
        }
        //对邻接矩阵对应的点赋值
        arc[start - 1][end - 1] = weight;
        //无向图上添加这行代码:arc[1][2] = arc[2][1]
        //arc[end - 1][start - 1] = weight;
        ++ count;
    }
}
void Graph_DG::print()
{
    cout << "图的邻接矩阵为:" << endl;
    int count_row = 0;
    int count_col = 0;
    while(count_row != this->vexnum)
    {
        count_col = 0;
        while(count_col != this->vexnum)
        {
            if(arc[count_row][count_col] == INT_MAX)
            {
                cout << "∞" << " ";
            }
            else
            {
                cout << arc[count_row][count_col] << " ";
            }
            ++count_col;
        }
        cout << endl;
        ++count_row;
    }
}
void Graph_DG::Dijkstra(int begin)
{
    int i;
    for(i=0;i<this->vexnum;i++)
    {
        //设置当前的路径
        dis[i].path = "v" + to_string(begin) + "-->" + to_string(i+1);
        dis[i].value = arc[begin - 1][i];
    }
    //设置起点到起点的路径为0；
    dis[begin - 1].value = 0;
    dis[begin - 1].visit = true;

    int count = 1;

    while(count != this->vexnum)
    {
        //temp 用于保存当前dis数组中的那个下标
        //min 用于记录当前最小值
        int temp = 0;
        int min = INT_MAX;
        for(i = 0;i<this->vexnum;i++)
        {
            if(!dis[i].visit && dis[i].value<min)
            {
                min = dis[i].value;
                temp = i;
            }
        }
        //cout << temp + 1 << " " << min << endl;
        //把temp对应的顶点加入到已经找到的最短路径的集合当中
        dis[temp].visit = true;
        ++count;
        for (i=0;i<this->vexnum;i++)
        {
            //注意这里的条件arc[temp][i] != INT_MAX 必须加，不然会溢出
            //从而造成程序异常
            if(!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]))
            {
                dis[i].value = dis[temp].value + arc[temp][i];
                dis[i].path = dis[temp].path +"-->v" + to_string(i+1);
            }
        }
    }
}
void Graph_DG::print_path(int begin)
{
    string str;
    str = "v" + to_string(begin);
    cout << "以" <<str<<"为起点的图的最短路径为:" << endl;
    for (int i=0;i != this->vexnum;i++)
    {
        if(dis[i].value != INT_MAX)
        {
            cout << dis[i].path << "=" << dis[i].value << endl;
        }
        else 
        {
            cout << dis[i].path<< "是无最短路径的" << endl;
        }
    }
}
