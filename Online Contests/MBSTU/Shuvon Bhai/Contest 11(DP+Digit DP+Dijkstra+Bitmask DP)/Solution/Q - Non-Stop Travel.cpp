#include<bits/stdc++.h>
using namespace std;
#define mx 12
#define INF 32000
vector<int>V[mx];
int cost[mx][mx];
int d[mx],vis[mx],par[mx];
struct node
{
    int u,w;

    node(int a,int c){
        u=a;
        w=c;
    }
    bool operator <(const node& p)const{
        return p.w < w;
    }
};
int dijkstra(int src, int des)
{
    for(int i=0; i<12; i++)
        d[i]=INF;
    memset(vis,0,sizeof(vis));

    priority_queue<node>pq;
    d[src]=0;
    pq.push(node(src,d[src]));

    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();
        int u = top.u;

        /*if(u==des)
            return d[u];
        if(vis[u]==1)
            continue;
        vis[u]=1;*/

        int sz = V[u].size();

        for(int i=0; i<sz; i++)
        {
            int v = V[u][i];
            int w = cost[u][v];
            //cout << "p " << u << " " << v << " " << d[v] << endl;

            if(d[u]+w < d[v])
            {
                d[v]=d[u]+w;
                //cout << u << " " << v << " " << d[v] << endl;
                par[v]=u;
                pq.push(node(v,d[v]));
            }
        }
    }

    return d[des];
}
void parent(int u, int src)
{
    if(u==src)
    {
        printf(" %d",u);
        return;
    }
    //printf(" %d",u);
    parent(par[u],src);
    printf(" %d",u);
}
int main()
{
    int N,m,u,v,w,S,D,test=0,mncst;

    while(cin >> N && N)
    {
        for(int u=1; u<=N; u++){
            cin >> m;
            for(int i=0; i<m; i++){
                cin >> v >> w;
                V[u].push_back(v);
                cost[u][v]=w;
            }
        }
        cin >> S >> D;
        mncst = dijkstra(S,D);

        printf("Case %d: Path =",++test);
        parent(D,S);
        printf("; %d second delay\n",mncst);

        for(int i=0; i<mx; i++)
            V[i].clear();
    }

    return 0;
}
