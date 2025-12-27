#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[505][505];
ll fun(int cur,int rem)
{
    if(rem==0)return 1;
    if(rem<0)return 0;

    if(dp[cur][rem]!=-1)return dp[cur][rem];

    ll ret=0;
    for(int i=cur-1; i>0; i--)
    {
        ret+=fun(i,rem-i);
    }

    return dp[cur][rem]=ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    while(scanf("%d",&n)==1)
    {
        ll ans = fun(n,n);
        printf("%lld\n",ans);
    }
    return 0;
}
