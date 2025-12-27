#include<bits/stdc++.h>
using namespace std;
#define mx 41
long long dp[mx];
long long sum[mx];
//int ret;
long long func(int n)
{
    int ret=0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(dp[n]!=-1)
        return dp[n];
    ret = func(n-1)+func(n-2);
    return dp[n]=ret;
    //return sum[n]=sum[n-1]+dp[n];
}
int main()
{
    int k;
    long long sum1;

    memset(dp,-1,sizeof(dp));
    dp[1]=1;
    dp[2]=2;
    sum1=func(mx);

    for(int i=0; i<41; i++)
    {
        cout << dp[i] << endl;
    }
    //cout << sum << endl;*/
    while(cin >> k)
    {
        //ret=0;
        //memset(dp,-1,sizeof(dp));
        //sum=func(k);
        cout << dp[k] << endl;
    }

    return 0;
}
