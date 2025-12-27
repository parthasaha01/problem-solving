#include<bits/stdc++.h>
using namespace std;
#define mx 10000
#define Inf 10005
vector<int>edge[mx];
int cost[mx];
queue<int>Q;
int BFS(int src, int des)
{
    int u,v,i,sz;
    cost[src]=0;
    Q.push(src);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        if(u==des)
            return cost[u];
        sz=edge[u].size();
        for(i=0; i<sz; i++){
            v=edge[u][i];
            if(cost[v]>cost[u]+1){
                Q.push(v);
                cost[v]=cost[u]+1;
            }
        }

    }

    return Inf;
}
int main()
{
    int N,E,i,n1,n2,src,des,Mincost;

    while(cin >> N >> E)
    {
        memset(cost,Inf,sizeof(cost));
        for(i=0; i<E; i++){
            cin >> n1 >> n2;
            edge[n1].push_back(n2);
        }
        cout << endl;
        cin >> src >> des;
        Mincost=BFS(src,des);
        if(Mincost==Inf)
            cout << "It is not possible to go " << src << " node to " << des << " node" << endl;
        else
            cout << "Minimum Cost: " << Mincost << endl;

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
