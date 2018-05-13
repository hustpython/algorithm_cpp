# define EH int 0;
# define LH int 1;
# define RH int 1;

typedef struct _BitNode
{
    int data;
    int bf;
    struct _BitNode *lchild,*rchild;
}BitNode,*BiTree;


