#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e15
ll dp[100005][5];
ll vs[100005][5];
ll cost[100005][5];
ll n,cs;
ll fun(ll i,ll j)
{
    if(i==n)
    {
        if(j==1)return cost[n][1]+cost[n][2];
        if(j==2)return cost[n][2];
        if(j==3)return INF;
    }

    if(vs[i][j]==cs)return dp[i][j];

    ll ret = INF;

    if(j==1)
    {
        ret = min(ret,fun(i,j+1));
        ret = min(ret,fun(i+1,j));
        ret = min(ret,fun(i+1,j+1));
        //ret = min(ret,cost[i][j]+fun(i,j+1));
    }
    else if(j==2)
    {
        ret = min(ret,fun(i,j+1));
        ret = min(ret,fun(i+1,j));
        ret = min(ret,fun(i+1,j-1));
        ret = min(ret,fun(i+1,j+1));
        //ret = min(ret,cost[i][j]+fun(i,j+1));

    }
    else if(j==3)
    {
        ret = min(ret,fun(i+1,j));
        ret = min(ret,fun(i+1,j-1));
    }
    vs[i][j]=cs;
    return dp[i][j] = ret+cost[i][j];
}
int main()
{
    ll ks=0;

    while(scanf("%lld",&n)==1 && n)
    {
        ks++;

        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=3; j++)
            {
                scanf("%lld",&cost[i][j]);
            }
        }
        cs++;
        ll ans = fun(1,2);

        printf("%lld. %lld\n",ks,ans);
    }

    return 0;
}




