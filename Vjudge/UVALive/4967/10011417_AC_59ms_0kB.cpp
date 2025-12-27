#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100005][5];
ll cost[100005][5];
ll n;
ll fun(ll i,ll j)
{
    if(i>n || j>3 || i<1 || j<1)return INT_MAX;
    if(i==n&&j==2){
        return cost[i][j];
    }
    if(i==n&&j==3){
        return INT_MAX;
    }

    if(dp[i][j]!=INT_MIN)return dp[i][j];

    ll ret = INT_MAX;

    if(j==1)
    {
        ret = min(ret,cost[i][j]+fun(i+1,j));
        ret = min(ret,cost[i][j]+fun(i+1,j+1));
        ret = min(ret,cost[i][j]+fun(i,j+1));
    }
    else if(j==2)
    {
        ret = min(ret,cost[i][j]+fun(i+1,j-1));
        ret = min(ret,cost[i][j]+fun(i+1,j));
        ret = min(ret,cost[i][j]+fun(i+1,j+1));
        ret = min(ret,cost[i][j]+fun(i,j+1));
    }
    else if(j==3)
    {
        ret = min(ret,cost[i][j]+fun(i+1,j-1));
        ret = min(ret,cost[i][j]+fun(i+1,j));
    }

    return dp[i][j] = ret;
}
int main()
{
    int ks=1;

    while(scanf("%lld",&n)==1 && n)
    {
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=3; j++)
            {
                scanf("%lld",&cost[i][j]);
                dp[i][j] = INT_MIN;
            }
        }

        ll ans = fun(1,2);

        printf("%d. %lld\n",ks++,ans);
    }

    return 0;
}




