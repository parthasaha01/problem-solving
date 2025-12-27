#include<bits/stdc++.h>
using namespace std;
#define mx 22000
#define INF 999999999
vector<int>V[mx];
vector<int>cost[mx];
long d[mx];
int vis[mx];
struct node
{
    int u;
    long w;

    node(int a, long c)
    {
        u=a;
        w=c;
    }
    bool operator <(const node& p)const{
        return p.w < w;
    }
};
long dijkstra(int src, int des, int n)
{
    for(int i=0; i<n; i++)
    {
        d[i]=INF;
        vis[i]=0;
    }
    priority_queue<node>pq;
    d[src]=0;
    pq.push(node(src,d[src]));

    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();
        int u = top.u;

        if(u==des)
            return d[u];

        if(vis[u]==1)
            continue;

        vis[u]=1;
        int sz = (int)V[u].size();

        for(int i=0; i<sz; i++)
        {
            int v=V[u][i];
            int w=cost[u][i];
            if(d[u]+w < d[v])
            {
                d[v]=d[u]+w;
                pq.push(node(v,d[v]));
            }
        }
    }

    return d[des];
}
int main()
{
    long N,n,m,S,T,i,test,mncst;
    int u,v,w;

    scanf("%ld",&N);

    for(test=1; test<=N; test++)
    {
        scanf("%ld %ld %ld %ld",&n,&m,&S,&T);

        for(i=0; i<m; i++){
            scanf("%d %d %d",&u,&v,&w);
            V[u].push_back(v);
            V[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        mncst = dijkstra(S,T,n);
        if(mncst >= INF)
            printf("Case #%ld: unreachable\n",test);
        else
            printf("Case #%ld: %ld\n",test,mncst);

        for(int i=0; i<n; i++){
            V[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
