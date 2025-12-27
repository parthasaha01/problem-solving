#include<bits/stdc++.h>
using namespace std;
#define mx 100
#define Inf 105
vector<int>edge[mx];
int cost[mx];
int vis[mx];
int parent[mx];
queue<int>Q;
void BFS(int src)
{
    int u,v,i,sz;
    cost[src]=0;
    vis[src]=1;
    Q.push(src);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        sz=edge[u].size();
        for(i=0; i<sz; i++){
            v=edge[u][i];
            if(!vis[v]){
                cost[v]=cost[u]+1;
                parent[v]=u;
                vis[v]=1;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int N,E,i,v,n1,n2,src,des,Mincost;

    while(cin >> N >> E)
    {
        memset(cost,Inf,sizeof(cost));
        memset(vis,0,sizeof(vis));

        for(i=0; i<E; i++){
            cin >> n1 >> n2;
            edge[n1].push_back(n2);
        }
        cout << endl;
        cin >> src;
        BFS(src);

        for(v=1; v<=N; v++){
            if(cost[v]==Inf)
            cout << "It is not possible to go " << src << " to " << v << "." << endl;
        else
            cout << src << " to " << v << " distance " << cost[v] << "." << endl;
        }

        //edge.erase();
        for(i=1;i<=N;i++){
            edge[i].erase(edge[i].begin(),edge[i].end());
        }
        while(!Q.empty())
            Q.pop();
        //cout << Q.size() << endl;
    }

    return 0;
}
