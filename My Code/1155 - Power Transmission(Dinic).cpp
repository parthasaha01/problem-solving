#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 205, MAXE = 40005;
int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN],a[MAXN];
int flow[MAXE], cap[MAXE], Next[MAXE], to[MAXE];
inline void init(int _src, int _snk, int _n)
{
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    memset(fin, -1, sizeof(fin));
}
inline void add(int u, int v, int c)
{
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, Next[nEdge] = fin[u], fin[u] = nEdge++;
    //to[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, Next[nEdge] = fin[v], fin[v] = nEdge++;
}
bool bfs()
{
    int st, en, i, u, v;
    memset(dist, -1, sizeof(dist));
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en)
    {
        u = Q[st++];
        for(i=fin[u]; i>=0; i=Next[i])
        {
            v = to[i];
            if(flow[i] < cap[i] && dist[v]==-1)
            {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}
int dfs(int u, int fl)
{
    if(u==snk) return fl;
    for(int &e=pro[u], v, df; e>=0; e=Next[e])
    {
        v = to[e];
        if(flow[e] < cap[e] && dist[v]==dist[u]+1)
        {
            df = dfs(v, min(cap[e]-flow[e], fl));
            if(df>0)
            {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}
int dinitz()
{
    int ret = 0;
    int df;
    while(bfs())
    {
        for(int i=0; i<=nNode; i++) pro[i] = fin[i];
        while(true)
        {
            df = dfs(src, INF);

            if(df) ret += df;
            else break;
        }
    }
    return ret;
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        int m; scanf("%d",&m);

        int source=0,sink=n+n+1;

        init(source,sink,n+n+2);

        for(int i=1; i<=n; i++){
            add(i,n+i,a[i]);
            add(n+i,i,0);
        }

        for(int i=1; i<=m; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u+n,v,w);
            add(v,u+n,0);
        }

        int B,D; scanf("%d%d",&B,&D);

        for(int i=1; i<=B; i++){
            int u; scanf("%d",&u);
            add(source,u,INF);
            add(u,source,0);
        }
        for(int i=1; i<=D; i++){
            int u; scanf("%d",&u);
            add(u+n,sink,INF);
            add(sink,u+n,0);
        }

        int MAXFLOW = dinitz();

        printf("Case %d: %d\n",ks,MAXFLOW);
    }

    return 0;
}

