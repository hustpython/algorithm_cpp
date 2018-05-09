# include "List.h"
bool searchHash(Hash t, keytype k, Node * &p,
                Node * & pre,int * hashsize)
{
    int index = k%hashsize[t.sizeindex];
    Node * head = t.elem[index].next;
    pre = NULL;
    while(head)
    {//遍历整个节点,直到找到需要查找的内容k
     p = head;
     if(head->data == k)
     {
         return true;
     }
     pre = head;
     head = head ->next;

    }
    return false;
}

bool insertHash(Hash &t,keytype k, int * hashsize)
{
    Node *p;
    Node * pre;
    if (searchHash(t,k,p,pre,hashsize))//通过searchHash函数使得
                                       //在没有查到的情况下，有两种情况。
                                       //1,没有与之相同的hash索引，此时pre=NULL。此时，需要计算hash值,建立链表
                                       //2，存在相同的索引，并且更新p到该索引链表的最后一个节点
                                       //此时不需要新建链表，只需要将插入值链接到该hash索引的链表的最后一个即可。
    {
        return false;
    }
    else{
        Node *s = new Node;
        s->data = k;
        if(pre == NULL)//如果没有冲突
        {
            int index = k%hashsize[t.sizeindex];//根据hash值，
                                             //将插入的值放在数组的hash
                                             //索引下的链表节点中
            t.elem[index].next = s;
            return true;
        }
        p -> next = s;//有冲突，将冲突的节点放在next
    }
    return true;
}

bool DeleteHash(Hash &t,keytype k, int * hashsize)
{
    Node *p;
    Node * pre;
    if(!searchHash(t,k,p,pre,hashsize))
    {
        return false;
    }
    //如果找到k，则p 指针 应该是pre->next
    else 
    {
        if(pre==NULL)//pre = NULL，要删除的元素是hash索引下的链表的第一个节点元素.
                     //要删除第一个元素节点，则将t.elem[index].next链接到 p->next。
        {
            int index = k%hashsize[t.sizeindex];
            t.elem[index].next = p->next;
            delete p;
            return true;
        }
        else
        {
            pre->next = p->next;//如果要删除的元素不是第一个元素节点,要删除p节点.
            delete p;
        }
    }
    return true;
}
void print(Hash t,int * hashsize)
{
    Node *p;
    for (int i=0;i< hashsize[t.sizeindex];++i)
    {
        cout << i << " ";
        p = t.elem[i].next;
        while(p)
        {
            cout << p->data << " ";
            p = p -> next;
        }
        cout << "^" << endl;
    }
}