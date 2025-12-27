#include<bits/stdc++.h>
using namespace std;
#define mx 800005
#define inf 1000000010
vector<int>ed[mx];
int wt[mx],d[mx],n,m;
bool vis[mx];
int bfs(int sx,int dx)
{
    if(sx==dx) return wt[sx];

    memset(vis,false,sizeof(vis));
    for(int i=1; i<=m; i++)d[i]=inf;

    queue<int>q;
    q.push(sx);
    d[sx]=0;
    vis[sx]=true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<ed[u].size(); i++){
            int v = ed[u][i];
            if(vis[v]==false){
                d[v] = d[u]+1;
                vis[v] = true;
                q.push(v);
            }
        }
    }

    if(vis[dx]==false){
        return -2;
    }
    else if(d[dx]>wt[dx]) return -1;
    else return wt[dx]-d[dx];
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&m);

        for(int i=1; i<=m; i++){
            scanf("%d",&wt[i]);
        }

        for(int i=1; i<=n; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        int sx,dx; scanf("%d%d",&sx,&dx);
        int ans = bfs(sx,dx);

        if(ans==-2)printf("Case %d: Path not found\n",ks);
        else if(ans==-1)printf("Case %d: Don't travel\n",ks);
        else printf("Case %d: %d\n",ks,ans);

        for(int i=0; i<=m; i++)ed[i].clear();
    }

    return 0;
}
