#include<bits/stdc++.h>
using namespace std;
#define Inf 9999
vector<int>adj[100];
int cost[100][100];
int d[100];
bool vis[100];
int node,edge;
struct st
{
    int u,w;
    st(int a, int b)
    {
        u=a;
        w=b;
    }
    bool operator <(const st& p)const{
        return p.w < w;
    }
};
void Dijkstra(int src)
{
    memset(d,Inf,sizeof(d));
    memset(vis,false,sizeof(vis));
    priority_queue<st>pq;

    d[src]=0;
    pq.push(st(src,d[src]));

    while(!pq.empty())
    {
        st top = pq.top();
        pq.pop();
        int u = top.u;

        if(vis[u]==true)
            continue;

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];

            if(d[u]+cost[u][v] < d[v])
            {
                d[v]=d[u]+cost[u][v];
                pq.push(st(v,d[v]));
            }
        }
        vis[u]=true;
    }

}
int main()
{
    int u,v,w,src;
    printf("Enter the Number of Router: ");
    cin >> node;
    printf("Enter the Number of Path: ");
    cin >> edge;
    printf("Enter all the Path\n");

    for(int i=0; i<edge; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u][v]=w;
        cost[v][u]=w;
    }

    for(int i=1; i<=node; i++)
    {
        int src=i;
        Dijkstra(src);

        printf("\nRouter-%d:\n",src);
        for(int k=1; k<=node; k++){
            if(d[k]==Inf)
                cout << "It is not possible to go " << src << " to " << k << "." << endl;
            else{
                cout << src << " to " << k << " distance " << d[k] << "." << endl;N
            }
        }

    }

    return 0;
}
