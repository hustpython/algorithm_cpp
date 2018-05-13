# include <iostream>
# include <climits>
# include <vector>
using namespace std;

typedef struct _BitNode 
{
    int data;
    struct _BitNode *lchild,*rchild;
}BitNode, *BiTree;

bool SearchBST(BiTree T,int key,BiTree pre,BiTree &n)
{
    if(!T)
    {
        n = pre; //两种情况,一种是最初传入是树本来就是空树
                 //非空树，但是没有找到要查找的节点
                 //此时,n返回的是需要插入的key的根节点
        return false;
    }
    else if(key == T->data)
    {
        n = T;
        return true;
    }

    if (key < T->data)
    {
        SearchBST(T->lchild,key,T,n);
    }
    else
    {
        SearchBST(T->rchild,key,T,n);
    }
    
    return 0;

}

bool InsertBST(BiTree &T,int k)
{
    BitNode *p;
    if (SearchBST(T,k,NULL,p))
    {
        return false;
    }
    else 
    {
        BitNode * temp = new BitNode;
        temp ->data = k;
        temp ->lchild = temp -> rchild = NULL;
        if(!p)
        {
            T = temp;
        }
        else 
        {
            cout << p->data << endl;
            if(k < p->data)
            {
                p -> lchild = temp;
            }
            else 
            {
                p -> rchild = temp;
            }
        }
    return 0;
    }

}

bool DeleteElement(BiTree &T,int key)
{
    if (!T)
    {
        return 0;
    }
    if (T->data == key)
    {
        BitNode *s,*p;
        if (T->rchild == NULL)
        {
            s = T;
            T = T -> lchild;
            delete s;
        }
        else if (T->lchild == NULL)
        {
            s = T;
            T = T->rchild;
            delete s;
        }
        else 
        {
            p = T;
            s = T -> rchild;
            while(s->lchild)
            {
                p = s;
                s = s->lchild;
            }
            T ->data = s -> data;//先赋值，后删除
            if(p!=T)
            {
                p->lchild = NULL;//后继的的左节点设置为NULL
            }
            else//需要删除的节点的右节点没有子树
            {
                p -> rchild = NULL;
            }
            delete s;

        }
    }
    else if(key<T->data)
    {
        DeleteElement(T->lchild,key);
    }
    else 
    {
        DeleteElement(T->rchild,key);
    }
    return 1;
}

vector<int> InorderTraversal(BiTree T, vector<int> & s)
{
    if(T)
    {
        InorderTraversal(T->lchild,s);
        //cout << T->data << endl;
        s.push_back(T->data);
        InorderTraversal(T->rchild,s);
    }
    return s;
}
void PreTraversal(BiTree T)
{
    if(T)
    {
        cout << T->data << endl;
        PreTraversal(T->lchild);
        PreTraversal(T->rchild);
    }
}
//          60
//       50      86
//    40   51  74   100
//  37             90
//35   
int main()
{
    BiTree tree = NULL;
    int a[] = {60,86,50,40,37,74,51,100,35,90};
    for (int i=0;i<10;++i)
    {
        InsertBST(tree,a[i]);
    }
    //PreTraversal(tree);
    //DeleteElement(tree,50);
    //PreTraversal(tree);
    vector<int> temp;
    int min = INT_MIN;
    bool flag = true;
    InorderTraversal(tree,temp);
    for(int i = 0;i !=temp.size();++i)
    {
        //cout <<temp[i]<< endl;
        if(temp[i] > min)
        {
           min = temp[i];
        }
        else 
        {
            flag = false;
        }
    }
    if(flag)
    {
        cout << "是搜索树 !" << endl;
    }
    else 
    {
        cout << "不是BST !" << endl;
    }
    PreTraversal(tree);
}