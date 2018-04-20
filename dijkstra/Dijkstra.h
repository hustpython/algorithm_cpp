# ifndef DIJKSTRA_H
# define DIJKSTRA_H
# include<iostream>
# include<string>
using namespace std;
/*
采用邻接矩阵储存图
*/
//记录起点到每个顶点最短路径的信息
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

class Graph_DG 
{
private: 
  int vexnum;//图的顶点个数
  int edge;  //图的边数
  int **arc; //邻接矩阵
  Dis * dis; //记录各个顶点的最短路径的信息
public: 
  //构造函数
  Graph_DG(int vexnum,int edge);
  //析构函数
  ~Graph_DG();
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