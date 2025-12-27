#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int n,m,vis[MAXN],par[MAXN],cap[MAXN][MAXN],flow[MAXN][MAXN];
vector<int>ed[MAXN];
bool BFS(int source,int sink)
{
    for(int i=0; i<=n; i++) vis[i]=0;
    for(int i=0; i<=n; i++) par[i]=i;

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
        scanf("%d%d",&n,&m);

        memset(cap,0,sizeof(cap));
        memset(flow,0,sizeof(flow));

        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ed[u].push_back(v);
            ed[v].push_back(u);
            cap[u][v] = w;
        }

        int source,sink;
        scanf("%d%d",&source,&sink);

        int MAXFLOW = FordFulkerson(source,sink);

        printf("Case %d: MAXIMUM FLOW = %d\n",ks,MAXFLOW);

        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}
/*
5
7 11
1 2 3
1 4 3
2 3 4
3 1 3
3 4 1
3 5 2
4 5 2
4 6 6
5 2 1
5 7 1
6 7 9
1 7
*/

