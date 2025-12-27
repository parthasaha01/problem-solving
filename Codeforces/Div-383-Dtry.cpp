#include<bits/stdc++.h>
using namespace std;
#define ll long long
int par[1005],id[1005],wt[1005],bt[1005], dp[1005][1005];
bool vis[1005];
vector<int>gr[1005];
int n,m,w,k;
struct dt{
    int sw,sb;
}st[1005];
int Find(int x)
{
    if(par[x]==x) return x;
    return par[x] = Find(par[x]);
}
void Union(int a,int b)
{
    par[Find(b)] = Find(a);
}
int dfs(int p,int wg)
{
    if(p>k) return 0;
    if(dp[p][wg] != -1) return dp[p][wg];

    int pr1=0, pr2=0;
    if(st[p].sw+wg<=w) pr1 = st[p].sb + dfs(p+1,st[p].sw+wg);
    pr2 = dfs(p+1,wg);
    int pr = max(pr1,pr2);

    int sr=0;
    for(int i=0; i<gr[p].size(); i++){
        int v = gr[p][i];
        int px=0, py=0;
        if(wg+wt[v]<=w) px = bt[v] + dfs(p+1,wg+wt[v]);
        py = dfs(p+1,wg);
        sr = max(sr,max(px,py));
    }
    return dp[p][wg] = max(pr,sr);
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&w)==3)
    {
        for(int i=1; i<=n; i++) scanf("%d",&wt[i]);
        for(int i=1; i<=n; i++) scanf("%d",&bt[i]);
        for(int i=1; i<=n; i++) par[i] = i;
        for(int i=1; i<=m; i++){
            int u,v; scanf("%d%d",&u,&v);
            Union(u,v);
        }

        for(int i=1; i<=n; i++) gr[i].clear();
        memset(vis,false,sizeof(vis));
        k=0;

        for(int i=1; i<=n; i++){
            int p = par[i];
            if(vis[p]==false){
                k++;
                id[p] = k;
                gr[id[p]].push_back(i);
                vis[p] = true;
            }
            else{
                gr[id[p]].push_back(i);
            }
        }

        for(int i=1; i<=k; i++){
            int sw=0, sb=0;
            for(int j=0; j<gr[i].size(); j++){
                int v = gr[i][j];
                sw += wt[v];
                sb += bt[v];
            }
            st[i].sw = sw;
            st[i].sb = sb;
        }
        memset(dp,-1,sizeof(dp));
        int ans = dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
