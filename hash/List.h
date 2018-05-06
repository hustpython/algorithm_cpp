# include <iostream>
using namespace std;
typedef int keytype;

struct Node {
    keytype data;
    Node * next;
    Node()
    {
        next = NULL;
    }
};
struct Hash 
{
    Node * elem;
    int sizeindex;
};

bool searchHash(Hash t,keytype k,Node * &p,Node * & pre, 
                int * hashsize);
bool insertHash(Hash & t,keytype k, int * hashsize);
bool DeleteHash(Hash &t,keytype k, int * hashsize);
bool DeleteHash(Hash &t,keytype k,int * hashsize);
void print(Hash t, int * hashsize);

