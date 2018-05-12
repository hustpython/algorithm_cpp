//有n条绳子，他们的长度分别为L[i]，如果他们中割出k条长度相同的绳子的话
//那么这k条绳子,每条最长为多少
# include <iostream>
using namespace std;

const int INF = 100;
int N = 3;
int K = 12;
double L[3] = {6.52,2.43,4.53};
bool c(double x)
{
    int num = 0;
    for(int i=0;i<N;++i)
    {
        num += L[i] / x;
    }
    return num>=K;
}

double solve()
{
    double lb = 0;
    double ub = INF;
    double mid = 0;
    for (int i=0;i<100;++i)
    {
        mid = (lb + ub) / 2;
        if (c(mid))
        {
            lb = mid;//mid太小      
        }
        else
        {
            ub = mid;//mid 太大
        }
    }
    return mid;
}
int main()
{
    cout << solve() << endl;
}