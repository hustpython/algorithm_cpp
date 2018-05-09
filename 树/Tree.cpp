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
void InorderTraverse_no_recursive(Tree_Node * T)
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

//后序遍历，递归实现
void PostorderTraverse(Tree_Node *T)
{
    if(T)
    {
        PostorderTraverse(T->left);
        PostorderTraverse(T->right);
        if(T->data != '#')
        {
            cout << T->data << " ";
        }
    }
}
//后序遍历，非递归实现
//思路：我们要保证根结
//点在左孩子和右孩子访
//问之后才能访问，因此
//对于任一结点P，先将其入栈。
//如果P不存在左孩子和右孩子，则可以直接访问它；
//或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，
//则同样可以直接访问该结点。若非上述两种情况，则将P的右孩子和左孩子依次入栈，
//这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，
//左孩子和右孩子都在根结点前面被访问。
void PostorderTraverse_no_recursive(Tree_Node * T)
{
    Tree_Node *pre;
    pre = NULL;
    stack <Tree_Node *>s;
    Tree_Node * cur;
    s.push(T);
    while(!s.empty())
    {
        cur = s.top();
        if((cur -> left == NULL && cur->right ==NULL) || (pre != NULL && (pre == cur->left || pre == cur->right)))
        {
            cout << cur -> data << " ";
            s.pop();
            pre = cur;
        }
        else 
        {
            if(cur -> right != NULL)
            {
                s.push(cur->right);
            }
            if(cur->left != NULL)
            {
                s.push(cur->left);
            }
        }
    }

}
int main()
{
    Tree_Node *T ;
    createTree(T);
    cout<<"先序遍历,递归实现:" << endl;
    PreorderTraverse(T);
    cout << endl;
    cout<<"先序遍历,非递归实现:" << endl;
    PreorderTraverse_no_recursive(T);
    cout << endl;
    cout<<"中序遍历,递归实现:" << endl;
    InorderTraverse(T);
    cout << endl;
    cout<<"中序遍历,非递归实现:" << endl;
    InorderTraverse_no_recursive(T);
    cout << endl;
    cout<<"后序遍历,递归实现:" << endl;
    PostorderTraverse(T);
    cout << endl;
    cout<<"后序遍历,非递归实现:" << endl;
    PostorderTraverse_no_recursive(T);
    cout << endl;
}