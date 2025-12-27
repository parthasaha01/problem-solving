#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000
int n,k;
ll dp[15][1005],cs[15][15][1005];
ll fun(int u,int p)
{
    if(p==k){
        if(u==n || cs[u][n][p]==0)return inf;
        return cs[u][n][p];
    }

    if(dp[u][p] != -1)return dp[u][p];

    ll ret = inf;

    for(int i=1; i<=n; i++)
    {
        if(i==u)continue;
        if(cs[u][i][p]==0)continue;

        ret = min(ret,cs[u][i][p] + fun(i,p+1));
    }

    return dp[u][p] = ret;
}
int main()
{
    int ks=0;

    while(scanf("%d%d",&n,&k))
    {
        if(n==0 && k==0)break;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)continue;

                int sz; scanf("%d",&sz);
                //d[i][j] = sz;

                for(int x=1; x<=sz; x++)
                {
                    ll v; scanf("%lld",&v);
                    cs[i][j][x] = v;
                }

                for(int y=sz+1,x=1; y<=k; y++,x++)
                {
                    cs[i][j][y] = cs[i][j][x];
                    if(x==sz) x=0;
                }
            }
        }

        memset(dp,-1,sizeof(dp));
        ll ans = fun(1,1);

        printf("Scenario #%d\n",++ks);
        if(ans>=inf)printf("No flight possible.\n\n");
        else printf("The best flight costs %lld.\n\n",ans);

    }

    return 0;
}
