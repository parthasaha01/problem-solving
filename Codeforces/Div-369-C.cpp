#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1000000000000000
ll c[105];
ll n,m,k;
ll p[105][105];
ll dp[105][105][105];
ll func(ll pos, ll color, ll ka)
{
    if(pos==n+1)
    {
        if(ka==k)
        {
            return 0;
        }
        else
        {
            return INF;
        }
    }

    if(dp[pos][color][ka]!=-1)
    {
        return dp[pos][color][ka];
    }

    ll ret=INF;

    if(c[pos]!=0)
    {
        if(c[pos]==color)
            return ret=func(pos+1,c[pos],ka);
        else
            return ret=func(pos+1,c[pos],ka+1);
    }
    else
    {
        for(ll i=1; i<=m; i++)
        {
            if(c[pos]==0)
            {
                if(i==color)
                {
                    ret=min(ret, p[pos][i]+func(pos+1,i,ka));
                }
                else
                {
                    ret=min(ret, p[pos][i]+func(pos+1,i,ka+1));
                }
            }

        }


    }
    return dp[pos][color][ka]=ret;
}
int main()
{
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)==3)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&c[i]);
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                ll x;
                scanf("%I64d",&x);
                p[i][j]=x;
            }
        }

        memset(dp,-1,sizeof(dp));
        ll ans=INF;
        ans=func(1,0,0);

        if(ans==INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%I64d\n",ans);
        }
    }

    return 0;
}

