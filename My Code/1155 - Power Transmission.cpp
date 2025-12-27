#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
int n,a[MAXN],vis[MAXN],par[MAXN],cap[MAXN][MAXN],flow[MAXN][MAXN];
vector<int>ed[MAXN];
bool BFS(int source,int sink)
{
    for(int i=0; i<MAXN; i++) vis[i]=0;
    for(int i=0; i<MAXN; i++) par[i]=i;

    queue<int>qq;
    qq.push(source);
    vis[source] = 1;

    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();

        for(int i=0; i<ed[u].size(); i++)
        {
            int v = ed[u][i];
            if(vis[v]==0 && cap[u][v]-flow[u][v]>0)
            {
                vis[v] = 1;
                par[v] = u;
                if(v==sink) return true;
                qq.push(v);
            }
        }
    }
    return false;
}
int EdmondKarp(int source,int sink)
{
    int MAXFLOW = 0;
    while(BFS(source,sink))
    {
        int FLOW = 1000000007;
        int now = sink;
        while(now != source)
        {
            int prev = par[now];
            FLOW = min(FLOW,cap[prev][now]-flow[prev][now]);
            now = prev;
        }

        MAXFLOW += FLOW;

        now = sink;
        while(now != source)
        {
            int prev = par[now];
            flow[prev][now] += FLOW;
            flow[now][prev] -= FLOW;
            now = prev;
        }

    }

    return MAXFLOW;
}
int FordFulkerson(int source,int sink)
{
    int MAXFLOW = EdmondKarp(source,sink);
    return MAXFLOW;
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);

        int m;
        scanf("%d",&m);

        memset(cap,0,sizeof(cap));
        memset(flow,0,sizeof(flow));

        for(int i=1; i<=n; i++){
            ed[i].push_back(n+i);
            cap[i][n+i] = a[i];
        }

        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);

            ed[u+n].push_back(v);
            ed[v].push_back(u+n);

            cap[u+n][v] = w;
        }

        int source=0,sink=201;
        int B,D; scanf("%d%d",&B,&D);

        for(int i=1; i<=B; i++){
            int u; scanf("%d",&u);

            ed[source].push_back(u);

            cap[source][u] = 1000000000;
        }
        for(int i=1; i<=D; i++){
            int u; scanf("%d",&u);

            ed[u+n].push_back(sink);

            cap[u+n][sink] = 1000000000;
        }

        int MAXFLOW = FordFulkerson(source,sink);

        printf("Case %d: %d\n",ks,MAXFLOW);

        for(int i=0; i<MAXN; i++)ed[i].clear();
    }

    return 0;
}
