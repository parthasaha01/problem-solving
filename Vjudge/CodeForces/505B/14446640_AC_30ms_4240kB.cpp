#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101],vis[101],gg[101][101];
vector<int>ed[101];
int BFS(int s,int d,int c)
{
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            if(dp[u][v][c]==0)continue;
            if(vis[v]==1)continue;
            if(v==d)return 1;
            vis[v]=1;
            q.push(v);
        }
    }
    return 0;
}
int main()
{
    int n,m; scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++){
        int u,v,c; scanf("%d%d%d",&u,&v,&c);
        if(gg[u][v]==0){
            ed[u].push_back(v);
            ed[v].push_back(u);
            gg[u][v]=gg[v][u]=1;
        }
        dp[u][v][c]=dp[v][u][c]=1;
    }

    int q; scanf("%d",&q);
    while(q--)
    {
        int u,v; scanf("%d%d",&u,&v);
        int ret = 0;
        for(int c=1; c<=m; c++){
            if(BFS(u,v,c))ret++;
        }
        printf("%d\n",ret);
    }
    return 0;
}
