#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
int cost[2][1005];
int vis[1005][1005];
vector<int>ed[1005];
queue<int>Q;
int BFS(int src,int id)
{
    cost[id][src]=0;
    Q.push(src);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<ed[u].size(); i++){
            int v=ed[u][i];
            if(cost[id][v]>cost[id][u]+1){
                Q.push(v);
                cost[id][v]=cost[id][u]+1;
            }
        }

    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);

    for(int i=0; i<=1; i++){
        for(int j=1; j<=n; j++){
            cost[i][j] = 1000005;
        }
    }

    for(int i=1; i<=m; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        ed[u].push_back(v);
        ed[v].push_back(u);
        vis[u][v] = vis[v][u] = 1;
    }

    BFS(s,0);
    BFS(t,1);

//    for(int k=1; k<=n; k++)
//    {
//        for(int i=1; i<=n; i++)
//        {
//            for(int j=1; j<=n; j++)
//            {
//                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
//            }
//        }
//    }

    int ans = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)continue;
            if(vis[i][j]==1 || vis[j][i]==1)continue;
            if(cost[0][t] > (cost[0][i]+cost[1][j]+1))continue;
            if(cost[0][t] > (cost[0][j]+cost[1][i]+1))continue;

            ans++;
        }
    }

    printf("%d\n",ans/2);

    return 0;
}

