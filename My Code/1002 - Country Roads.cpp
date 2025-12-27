#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int n,m,d[505],cost[505][505];
vector<int>ed[505];
struct edge
{
    int u,v,w;
    edge(int x, int y, int c){
        u=x;v=y;w=c;
    }
    bool operator < (const edge& p) const{
        return p.w < w;
    }
};
void primsMST(int s)
{
    memset(d,-1,sizeof(d));
    priority_queue<edge>pq;

    for(int i=0; i<ed[s].size(); i++){
        pq.push(edge(s,ed[s][i],cost[s][ed[s][i]]));
    }
    d[s]=0;

    while(!pq.empty())
    {
        edge nd(-1,-1,-1);
        nd = pq.top();
        pq.pop();

        int u=nd.u, v=nd.v, w=nd.w;

        if(d[v]!=-1) continue;

        d[v] = max(d[u],w);

        for(int i=0; i<ed[v].size(); i++){
            if(d[ed[v][i]]==-1){
                pq.push(edge(v,ed[v][i],cost[v][ed[v][i]]));
            }
        }
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&m);

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                cost[i][j]=inf;
            }
        }

        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(cost[u][v]==inf)
            {
                ed[u].push_back(v);
                ed[v].push_back(u);
            }

            cost[u][v]=cost[v][u]=min(cost[u][v],w);
        }

        int s; scanf("%d",&s);

        primsMST(s);

        printf("Case %d:\n",ks);
        for(int i=0; i<n; i++){
            if(d[i]!=-1)printf("%d\n",d[i]);
            else printf("Impossible\n");
        }

        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}
