# include "Dijkstra.h"

bool check(int Vexnum,int edge)
{
    if(Vexnum<=0 || edge <=0 || ((Vexnum*(Vexnum-1))/2)<edge)
    {
        return false;
    }
    return true;
}
int main()
{
    /*
    输入：
    6 8
    1 3 10
    1 5 30
    1 6 100
    2 3 5
    3 4 50
    4 6 10
    5 6 60
    5 4 20
    */
    int vexnum; int edge;

    cout <<"请输入图的顶点个数和边的条数:" << endl;
    cin >> vexnum >> edge;
    while(!check(vexnum,edge))
    {
        cout<<"输入的数值不合法,请重新输入"<< endl;
        cin >> vexnum >> edge;
    }
    Graph_DG graph(vexnum,edge);
    graph.createGraph();
    graph.print();
    graph.Dijkstra(1);
    graph.print_path(1);
    return 0;
}