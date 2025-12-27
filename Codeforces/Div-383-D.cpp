#include<bits/stdc++.h>
using namespace std;
#define ll long long
int par[1005],id[1005],wt[1005],bt[1005], dp[1005][1005];
bool vis[1005];
vector<int>gr[1005],ed[1005];
int n,m,w,k;
struct dt{
    int sw,sb;
}st[1005];
void RESET(int n)
{
    for(int i=1; i<=n; i++) ed[i].clear();
    for(int i=1; i<=n; i++) gr[i].clear();
    memset(st,0,sizeof(st));
    memset(dp,-1,sizeof(dp));
    memset(vis,false,sizeof(vis));
}
void dfs(int p,int u)
{
    vis[u] = true;
    gr[p].push_back(u);
    st[p].sw += wt[u];
    st[p].sb += bt[u];
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(!vis[v]) dfs(p,v);
    }
}
int knapsack(int p,int wg)
{
    if(p>k) return 0;
    if(dp[p][wg] != -1) return dp[p][wg];

    int pr1=0, pr2=0;
    if(st[p].sw+wg<=w) pr1 = st[p].sb + knapsack(p+1,st[p].sw+wg);
    pr2 = knapsack(p+1,wg);
    int pr = max(pr1,pr2);

    int sr=0;
    for(int i=0; i<gr[p].size(); i++){
        int v = gr[p][i];
        int px=0, py=0;
        if(wg+wt[v]<=w) px = bt[v] + knapsack(p+1,wg+wt[v]);
        py = knapsack(p+1,wg);
        sr = max(sr,max(px,py));
    }
    return dp[p][wg] = max(pr,sr);
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&w)==3)
    {
        RESET(n);
        for(int i=1; i<=n; i++) scanf("%d",&wt[i]);
        for(int i=1; i<=n; i++) scanf("%d",&bt[i]);
        for(int i=1; i<=n; i++) par[i] = i;
        for(int i=1; i<=m; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        k=0;
        for(int u=1; u<=n; u++){
            if(!vis[u]){
                k++;
                dfs(k,u);
            }
        }

        int ans = knapsack(1,0);
        printf("%d\n",ans);
    }
    return 0;
}

