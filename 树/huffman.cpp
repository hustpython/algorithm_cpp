// 最优二叉树（哈夫曼树)
// (1)叶子节点的路径长度:从根节点到该叶子节点所经过
//    的边的条数。
// (2)树的带权路径长度:为树的所有的叶子节点的路径长度乘以
//    该叶子节点的权值 的 和。通常记为WPL。

// 然后，当我们给定的每个叶子节点的权值，我们去构造不同的二叉树，当该二叉树
// 的WPL值最小时，我们称该二叉树为最优二叉树或哈夫曼树。
# include <climits>

struct Tree_Node 
{
    char data;
    int weight;
    int parent;
    int left;
    int right;
};
void select_two_min(Tree_Node * tree,int k,int &s1,int &s2)
{
    int i = 0;
    int min = INT_MAX;
    int min2 = INT_MAX;
    for (i = 0;i <= k; ++i)
    {
        if (tree[i].parent == 0 && tree[i].weight < min)
        {
            min2 = min;
            min = tree[i].weight;
            s2 = s1;
            s1 = i;
        }
        else if (tree[i].parent == 0 && tree[i].weight < min2)
        {
            min2 = tree[i].weight;
            s2 = i;
        }

    }
}

void Build_Huffman_Tree(Tree_Node * & tree,int *weight , int n,char *data)
{
    if (n <= 1) return;
    int m=2 * n - 1;//若叶子节点为n，则总的节点树最大 2*n - 1
    tree = new Tree_Node[m];
    int i = 0;
    Tree_Node *p = tree;
    for (i = 0;i<n;++i)
    {
        tree[i].data = data[i];
        tree[i].left = tree[i].right = tree[i].parent = 0;
        tree[i].weight = weight[i];
    }
    for (;i<m;++i)
    {
        tree[i].left = tree[i].right = tree[i].parent = 0;
        tree[i].weight = 0;
    }
    for (i=n;i<m;i++)
    {
        int s1=0;
        int s2=0;
        select_two_min(tree,i - 1,s1,s2);
        tree[i].left = s1;
        tree[i].right = s2;
        tree[s1].parent = tree[s2].parent = i;
        tree[i].weight = tree[s1].weight + tree[s2].weight;
    }

}
void code (char * str,int n,int * weight, char ** & huffmancode)
{
    Tree_Node * tree;
    Build_Huffman_Tree(tree,weight,n,str);
    huffmancode = new char *[n+1];
    char *c = new char[n];
    c[n - 1] = '\0';
    int i;
    int start;
    int child;
    int f;
    for(i=0;i<n;++i)
    {
        start = n-1;
        for(child = i;f = tree[i].parent; f != 0;child = f;f=)

    }


}