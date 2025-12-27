#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>ed[mx];
int dp[mx+5],lev[mx+5],vis[mx+5],cnt[mx+5];
void DFS(int u,int lv)
{
    vis[u]=1;
    lev[u] = lv;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==1)continue;
        DFS(v,lv+1);
    }
}
int main()
{
    int n; scanf("%d",&n);

    for(int i=2; i<=n; i++)
    {
        int u; scanf("%d",&u);
        ed[u].push_back(i);
        ed[i].push_back(u);
    }

    DFS(1,1);

    for(int i=1; i<=n; i++)
    {
        cnt[lev[i]]++;
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        if(cnt[i]%2 == 1)ans++;
    }

    printf("%d\n",ans);

    return 0;
}
