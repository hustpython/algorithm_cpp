//有n条绳子，他们的长度分别为L[i]，如果他们中割出k条长度相同的绳子的话
//那么这k条绳子,每条最长为多少
# include <iostream>
using namespace std;

const int INF = 100;
int N = 4;
int K = 11;
double L[4] = {8.04,2.43,4.53,5.39};
bool c(double x)
{
    double num = 0;
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
    for (int i=0;i<30;++i)
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