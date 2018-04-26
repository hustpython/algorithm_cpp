# ifndef DIJKSTRATXT_H
# define DIJKSTRATXT_H
# include <iostream>
# include <stdlib.h>
using namespace std;
struct Dis 
{
    string path;
    int value;
    bool visit;
    Dis()
    {
        visit = false;
        value = 0;
        path = "";
    }
};
class Dijkstratxt
{
private: 
  int vexnum;//图的顶点个数
  int edge;  //图的边数
  int **arc; //邻接矩阵
public: 
  //构造函数
  Dijkstratxt(int vexnum,int edge);
  //析构函数
  ~Dijkstratxt();
  //判断我们每次输入的边的信息是否合法
  //顶点从1开始编号
  bool check_edge_value(int start,int end,int weight);
  //创建图
  void createGraph();
  //打印邻接矩阵
  void print();
  //Diskstra算法求最短路径
  void Dijkstra(int begin);
  //打印路径
  void print_path(int);
  
};
# endif