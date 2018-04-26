# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <string>
# include <limits.h>
# include <vector>
# include <fstream>

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
vector<string> read_file(const char * const filename)
{  
   string temp;
   vector<string>data;
   ifstream infile;
   infile.open(filename,ios::in);
   if(!infile.is_open())
   {
       cout<<"open fail"<< endl;
   }
   while(getline(infile,temp))
   {
      data.push_back(temp);
   }
   return data;
}
vector<string> cstr2words(const string line_str){
    
	vector<string> words;
	string tem;
	
    for(int i=0;i<line_str.length();i++)
    {
        if(line_str[i] != ' '&& line_str[i]!='\t')
        {
           tem.push_back(line_str[i]);
        }
        else if(tem!=""){
			words.push_back(tem);
			tem="";
		} 
    }
	if(tem!="")
		words.push_back(tem);
	return words;
}
void initarc(vector<vector<int> >&arc)
{
for(int i=0;i<arc.size();++i)
{
    arc[i].resize(arc.size());
    for(int j=0;j<arc[i].size();++j)
    {
       arc[i][j] = INT_MAX;
    }
} 
}
void arcPrint(vector<vector<int> >arc)
{
    cout << "图的邻接矩阵为:" << endl;
    int count_row = 0;
    int count_col = 0;
    for(int count_row=0;count_row<arc.size();++count_row)
    {
        for(int count_col=0;count_col<arc[count_row].size();++count_col)
        {
            if(arc[count_row][count_col] == INT_MAX)
            {
                cout << "∞" << " ";
            }
            else
            {
                cout << arc[count_row][count_col] << " ";
            }
        }
        cout << endl;
    }
            
}
void Dijkstra(vector<vector<int> >arc,vector<Dis> &dis)
{
int begin = 1;
int i;
int vexnum = arc.size();
for(i=0;i<vexnum;i++)
{
    //设置当前的路径
    dis[i].path = "v" + to_string(i) + "-->" + to_string(i+1);
    dis[i].value = arc[begin - 1][i];
}
    //设置起点到起点的路径为0；
    dis[begin - 1].value = 0;
    dis[begin - 1].visit = true;

    int count = 1;

    while(count != vexnum)
    {
        //temp 用于保存当前dis数组中的那个下标
        //min 用于记录当前最小值
        int temp = 0;
        int min = INT_MAX;
        for(i = 0;i<vexnum;i++)
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
        for (i=0;i< vexnum;i++)
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
void print_path(vector<Dis> dis)
{
    int begin = 1;
    int vexnum = dis.size();
    ofstream outfile;
    outfile.open("outres.txt", ios::trunc);
    string str;
    str = "v" + to_string(begin);
    cout << "以" <<str<<"为起点的图的最短路径为:" << endl;
    outfile << "以" <<str<<"为起点的图的最短路径为:" << endl;
    for (int i=0;i != vexnum;i++)
    {
        if(dis[i].value != INT_MAX)
        {
            cout << dis[i].path << "=" << dis[i].value << endl;
            outfile << dis[i].path << "=" << dis[i].value << endl;
        }
        else 
        {
            cout << dis[i].path<< "是无最短路径的" << endl;
            outfile << dis[i].path<< "是无最短路径的" << endl;
        }
    }
}
int main(int argc, char *argv[])
{
    char *data_file = argv[1];
    int data_line_num;
    vector<string>datas;
    int vexnum;
    //vector<Dis>dis;
    datas = read_file(data_file);
    vector<string> vexstr;
    vexstr = cstr2words(datas[0]);
    vexnum = atoi(vexstr[0].c_str());
    vector<vector<int> > arc(vexnum);
    initarc(arc);
    for(int i=1;i<datas.size();++i)
    {
        vector<string> s;
        //cout << datas[i] << endl;
        s = cstr2words(datas[i]);
        int start = atoi(s[0].c_str());
        int end = atoi(s[1].c_str());
        int weight = atoi(s[2].c_str());
        arc[start - 1][end - 1] = weight;
    }
    arcPrint(arc);
    vector<Dis> dis(vexnum);
    Dijkstra(arc,dis);
    print_path(dis);
}

