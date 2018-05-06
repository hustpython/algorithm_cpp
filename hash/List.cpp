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
    if (searchHash(t,k,p,pre,hashsize))
    {
        return false;
    }
    else{
        Node *s = new Node;
        s->data = k;
        if(pre == NULL)
        {
            int index = k%hashsize[t.sizeindex];
            t.elem[index].next = s;
            return true;
        }
        p -> next = s;
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
    else 
    {
        if(pre==NULL)
        {
            int index = k%hashsize[t.sizeindex];
            t.elem[index].next = p->next;
            return true;
        }
        else
        {
            pre->next = p->next;
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