#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[]={10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
ll dp[11][30005];
ll fun(int p, int n)
{
    if(n==0)return 1;
    if(p>10 || n<0)return 0;

    if(dp[p][n]!=-1)return dp[p][n];

    ll ret=0;

    if(n-a[p]>=0)ret += fun(p,n-a[p]);

    ret += fun(p+1,n);

    return dp[p][n] = ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));

    double amount;
    while(scanf("%lf",&amount))
    {
        if(amount==0.0)break;

        int n = (amount*100);

        if((n%5) != 0)n++;

        ll way = fun(0,n);

        printf("%6.2lf%17lld\n",amount,way);
    }
    return 0;
}
/*
(int)(0.29 * 100) == 28
(int)(0.57 * 100) == 56
(int)(0.58 * 100) == 57
(int)(1.13 * 100) == 112
(int)(1.14 * 100) == 113
(int)(1.15 * 100) == 114
*/

