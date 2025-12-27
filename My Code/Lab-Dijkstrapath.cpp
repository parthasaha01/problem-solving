#include<bits/stdc++.h>
using namespace std;
#define Inf 9999999
vector<int>adj[100],vv;
int cost[100][100];
int d[100];
bool vis[100];
int par[100];
int node,edge;
struct st
{
    int u,w;
    st(int a, int b)
    {
        u=a;
        w=b;
    }
    bool operator <(const st& p)const
    {
        return p.w < w;
    }
};
void Dijkstra(int src)
{
    for(int i=0; i<100; i++)
    {
        d[i]=Inf;
        vis[i]=false;
        par[i]=-1;
    }

    priority_queue<st>pq;

    d[src]=0;
    par[src]=src;
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
                par[v]=u;
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
    printf("Enter all the Path and Distance:\n");

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

        printf("\n\nRouter-%d:\n",src);
        for(int k=1; k<=node; k++)
        {
            if(d[k]==Inf){
                cout << "It is not possible to go " << src << " to " << k << "." << endl;
            }
            else
            {
                cout << src << " to " << k << " distance " << d[k] << "." << endl;

                vv.clear();
                int x=k;
                vv.push_back(x);
                while(par[x]!=x)
                {
                    vv.push_back(par[x]);
                    x=par[x];
                }

                for(int m=vv.size()-1; m>=0; m--)
                {
                    if(m==0)
                    {
                        printf("%d\n\n",vv[m]);
                    }
                    else
                    {
                        printf("%d-->",vv[m]);
                    }
                }
            }
        }

    }

    return 0;
}

/*
5
6
1 2 5
1 3 4
2 3 10
2 4 6
3 5 1
4 5 2

*/
