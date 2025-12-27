#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int n,m,vis[MAXN],par[MAXN],cap[MAXN][MAXN];
vector<int>ed[MAXN];
int EdmondKarp(int S,int T)
{
    for(int i=0; i<=n; i++)vis[i]=0;
    for(int i=0; i<=n; i++)par[i]=i;

    queue<int>qq;
    qq.push(S);
    vis[S] = 1;
    int flag = 0;
    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();

        if(u==T){
            flag = 1;
            break;
        }

        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            if(vis[v]==1)continue;
            if(cap[u][v]<=0)continue;
            vis[v] = 1;
            par[v] = u;
            qq.push(v);
        }
    }

    if(flag==0)return 0;

    int MINIMUM = 1000000007;
    int v = T;
    while(v!=S)
    {
        int u = par[v];
        MINIMUM = min(MINIMUM,cap[u][v]);
        v = u;
    }

    v = T;
    while(v!=S)
    {
        int u = par[v];
        cap[u][v] -= MINIMUM;
        cap[v][u] += MINIMUM;
        v = u;
    }

    return MINIMUM;

}
int FordFulkerson(int S,int T)
{
    int MAXFLOW = 0;

    while(1)
    {
        int FLOW = EdmondKarp(S,T);
        if(FLOW==0)break;
        MAXFLOW += FLOW;
    }
    return MAXFLOW;
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        ed[u].push_back(v);
        ed[v].push_back(u);
        cap[u][v] = w;
        cap[v][u] = 0;
    }

    int S,T; scanf("%d%d",&S,&T);

    int MAXFLOW = FordFulkerson(S,T);

    printf("MAXIMUM FLOW = %d\n",MAXFLOW);

    return 0;
}
/*
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
