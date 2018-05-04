# include "linear.h"
bool searchHash(Hash t, keytype k, int & p,int &c, int * hashsize)
{
    p = k % hashsize[t.sizeindex];
    while (t.isfull[p] && t.elem[p] != k && c < hashsize[t.sizeindex] - 1)
    {
        ++c;
        p = (k+c) % hashsize[t.sizeindex];
    }
    if (t.elem[p] == k)
    {
        return true;
    }
    return false;
}
bool insertHash(Hash & t , keytype k, int *hashsize)
{
    int p;
    int c = 0;
    if (searchHash(t,k,p,c,hashsize))
    {
        return false;
    }
    else if (c == hashsize[t.sizeindex] - 1)
    {
        int temp;
        temp = hashsize[t.sizeindex];
        keytype * elem = new keytype[hashsize[t.sizeindex]];
        bool * isfull = new bool[hashsize[t.sizeindex]];
        for (int i = 0; i < hashsize[t.sizeindex]; ++i)
        {
            elem[i] = t.elem[i];
            isfull[i] = t.isfull[i];
        }
        delete t.elem;
        delete t.isfull;
        ++t.sizeindex;
        //重新分配空间
        t.elem = new keytype[hashsize[t.sizeindex]];
        t.isfull = new bool[hashsize[t.sizeindex]];
        int i;
        for (i = 0; i< temp; ++i)
        {
            t.elem[i] = elem[i];
            t.isfull[i] = isfull[i];
        }
        for(; i<hashsize[t.sizeindex];++i)
        {
            t.isfull[i] = false;
        }
    }
    else 
    {
        t.elem[p] = k;
        ++t.count;
        t.isfull[p] = true;
    }
    return true;
}
bool deleteHash(Hash &t,keytype k,int * hashsize)
{
    int p;
    int c = 0;
    if (!searchHash(t,k,p,c,hashsize))
    {
        return false;
    }
    else 
    {
        t.isfull[p] = false;
        --t.count;
    }
}
void print(Hash t, int * hashsize)
{
    cout << "当前的表的长度:" << hashsize[t.sizeindex] << endl;
    cout << "Hash表的元素的个数为:" << t.count << endl;
    cout << "打印整个表:" << endl;
    for (int i = 0; i< hashsize[t.sizeindex];++i)
    {
        if(t.isfull[i])
        {
            cout << t.elem[i] << " ";
        }
        else 
        {
            cout << "^" << " ";
        }
    }
    cout << endl;
}