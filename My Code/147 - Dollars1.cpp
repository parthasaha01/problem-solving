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
    string ss;
    memset(dp,-1,sizeof(dp));

    while(cin>>ss)
    {
        if(ss=="0.00")break;

        double amount;
        stringstream qq(ss);
        qq>>amount;

        char input[20];
        int whole,decimal;
        sprintf(input, "%.2lf", amount);
        sscanf(input, "%d.%d", &whole, &decimal);

        int n = (whole*100)+decimal;

        ll way = fun(0,n);

        cout << setw(6) << fixed << setprecision(2) << amount << setw(17) << way << "\n";
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

