#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 60, MAXE = 5005;
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
        int m; scanf("%d",&m);

        int source=0,sink=m+7;

        init(source,sink,m+8);

        for(int i=1; i<=m; i++){
            string s1,s2;
            cin>>s1>>s2;
            int u,v;

            if(s1=="XXL")u=m+1;
            else if(s1=="XL")u=m+2;
            else if(s1=="L")u=m+3;
            else if(s1=="M")u=m+4;
            else if(s1=="S")u=m+5;
            else if(s1=="XS")u=m+6;

            if(s2=="XXL")v=m+1;
            else if(s2=="XL")v=m+2;
            else if(s2=="L")v=m+3;
            else if(s2=="M")v=m+4;
            else if(s2=="S")v=m+5;
            else if(s2=="XS")v=m+6;

            add(i,u,1);
            add(u,i,0);

            add(i,v,1);
            add(v,i,0);
        }

        for(int i=1; i<=m; i++){
            add(source,i,1);
            add(i,source,0);
        }
        for(int i=1; i<=6; i++){
            add(m+i,sink,n);
            add(sink,m+i,0);
        }

        int MAXFLOW = dinitz();

        if(MAXFLOW>=m){
            printf("Case %d: YES\n",ks);
        }
        else{
            printf("Case %d: NO\n",ks);
        }
    }

    return 0;
}


