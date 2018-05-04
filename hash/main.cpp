# include "linear.h"
int hashsize[] = 
{
11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337,
347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457,
461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593,
599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719,
727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857,
859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 
};

int main()
{
    Hash t;
    t.count = 0;
    t.sizeindex = 0;
    t.elem = new keytype[hashsize[t.sizeindex]];
    t.isfull = new bool[hashsize[t.sizeindex]];//bool数组[treu,true,false,,,,,,]
    cout << "请先输入10个数" << endl;
    for (int i = 0;i< hashsize[t.sizeindex];++i)
    {
        t.isfull[i] = false;
    }
    for (int i = 0;i<10;++i)
    {
        int temp;
        cin >> temp;
        insertHash(t,temp,hashsize);
    }
    print(t,hashsize);
    cout << "输入需要查找的数:" << endl;
    int key;
    cin >> key;
    int p;
    int c = 0;
    if(searchHash(t,key,p,c,hashsize))
    {
        cout << "查找成功" << endl;
        cout << "为第"<< p+1 << "个元素" << endl;

    }
    else 
    {
        cout << "查找失败" << endl;

    }
    cout << "输入需要删除的数:" << endl;
    cin >> key;
    if (deleteHash(t,key,hashsize))
    {
        cout << "删除成功，删除后的结果为:"<< endl;
        print(t,hashsize);
    }
    else 
    {
        cout << "删除失败" << endl;

    }
    return 0;
}