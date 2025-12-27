#include<bits/stdc++.h>
using namespace std;
int dp[6005][2],par[6005],a[6005];
vector<int>ed[6005];
void DFS(int u)
{
    dp[u][0]=0;
    dp[u][1]=a[u];

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        DFS(v);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    int u,v;
    while(scanf("%d %d",&u,&v))
    {
        if(u==0 && v==0)break;
        ed[v].push_back(u);
        par[u]=v;
    }

    int ans = 0;

    for(int i=1; i<=n; i++)
    {
        if(par[i]==0)
        {
            DFS(i);
            ans += max(dp[i][0],dp[i][1]);
        }
    }

    printf("%d\n",ans);

    return 0;
}

