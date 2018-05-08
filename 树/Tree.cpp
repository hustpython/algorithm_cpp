# include <iostream>
# include <stack>
using namespace std;

//节点结构
struct Tree_Node 
{
    char data;
    Tree_Node * left;
    Tree_Node * right;
};

//构建二叉树
//abd#e##fg###c## 
void createTree(Tree_Node * &t)
{
    char str;
    cin >> str;
    if(str == '#')
    {
        t = NULL;
    }
    else 
    {
        t = new Tree_Node;
        t -> data = str;
        createTree(t->left);
        createTree(t->right);
    }
}
//先序遍历，递归实现
void PreorderTraverse(Tree_Node * T)
{
    if(T)
    {
        if(T->data != '#')
        {
            cout << T->data << " ";
        }
        PreorderTraverse(T->left);
        PreorderTraverse(T->right);
    }
}
//现需遍历，循环实现
void PreorderTraverse_no_recursive(Tree_Node * T)
{
    stack<Tree_Node*>s;
    Tree_Node *p = T;
    while(p || !s.empty())
    {
        if(p != NULL)
        {
            s.push(p);
            if(p->data != '#')
            {
                cout << p->data << " ";
                p = p->left;
            }
        }
        else 
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }

}

//中序遍历,递归实现
void InorderTraverse(Tree_Node * T)
{
    if(T)
    {
        InorderTraverse(T->left);
        if(T->data != '#')
        {
            cout << T-> data << " ";
        }
        InorderTraverse(T->right);
    }
}

//中序遍历，非递归实现
void InorderTraverse_no_recusive(Tree_Node * T)
{
    stack<Tree_Node *> s;
    Tree_Node *p = T;
    while(p || ! s.empty())
    {
        if(p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        else 
        {
            p = s.top();
            s.pop();
            if(p->data!='#')
            {
                cout << p->data << " ";
            }
            p = p->right;
        }
    }
}
int main()
{
    Tree_Node *T ;
    createTree(T);
    //PreorderTraverse(T);
    PreorderTraverse_no_recursive(T);
    InorderTraverse(T);
    InorderTraverse_no_recusive(T);
}