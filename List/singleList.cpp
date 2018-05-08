# include <stdlib.h>
# include <stdio.h>
//singleList C language
//声明Node结构体
typedef struct node 
{
    int val;
    struct node * next;
}Node;
//创建Node
Node * CreateNode(int val)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("out of memory !\n");
        return NULL;
    }
    else 
    {
        newNode -> val = val;
        newNode ->next = NULL;//对于单个节点，next是空指针，还没指向下一个节点。
        return newNode;
    }
}
// 尾部插入
void Insertwithtail(Node *head,Node * & tail,int val)
{
    Node *newNode = CreateNode(val);
    tail->next = newNode;//将新的节点插入到尾部
    tail = tail->next;
    head ->val ++;
}
//尾部插入
void InsertdNotail(int num,Node *head)  
{  
    Node *newNode = CreateNode(num);
    Node *L = NULL;    
    L = head;  
    while (L->next != NULL)  
    {  
        L = L->next;//遍历找到尾节点   
    }    
    L->next = newNode;//挂在原来尾节点之后   
}  

//前部插入
void Inserthead(Node *head,int val)
{
    Node *p = CreateNode(val);
    p -> next = head -> next;
    head ->next = p;
    head->val ++;
}
//删除节点
void deleteByVal(Node * head,int val)
{
    if(head -> next == NULL)
    {
        printf("empty list\n");
    }
}
int main(){

    Node * head = CreateNode(0);
    //Node * tail = (Node*)malloc(sizeof(Node));
    Node * tail = NULL;
    tail = head;
    //insert new value into list, end with END_INPUT(999)
    int value;
    int END_INPUT = 10;
    // while (scanf("%d", &value) && value != END_INPUT)
    // {
    //     Insert(head, tail , value);
    //     tail=tail->next;
    //     //Insertnotail(value,head);
    // }
    for(int i = 1;i<= 10;++i)
    {
         Insertwithtail(head, tail , i);
         //tail=tail->next;//tail指向的next变了
         //Inserthead(head,i);
    }
    
    Node *p = head ->next ;
    
    while(p!= NULL)
    {
        printf("% d->",p->val);
        p =  p->next;
    }
    //free(head);
    //free(tail);
    return 0;
}