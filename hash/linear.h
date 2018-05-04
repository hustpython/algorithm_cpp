# ifndef LINEAR_H
# define LINEAR_H
# include<iostream>
using namespace std;
typedef int keytype;
struct Hash 
{
    keytype * elem;
    bool * isfull;
    int count;
    int sizeindex;
};
bool searchHash(Hash t, keytype k,int & p, int &c,int * hashsize);
bool insertHash(Hash &t, keytype k, int *hashsize);
bool deleteHash(Hash &t, keytype k, int *hashsize);
void print(Hash t, int * hashsize);
# endif