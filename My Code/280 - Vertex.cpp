#include<bits/stdc++.h>
using namespace std;
vector<int>ed[105];
int vis[105];
int res[105];
void dfs(int u)
{
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];

        if(vis[v]==0)
        {
            vis[v]=1;
            dfs(v);
        }
    }

    return;
}
int main()
{
    int n,sr,v,u,t;

    while(scanf("%d",&n) && n)
    {
        while(scanf("%d",&u) && u)
        {
            while(scanf("%d",&v) && v){
                ed[u].push_back(v);
            }
        }

        scanf("%d",&t);

        for(int kase=1; kase<=t; kase++)
        {
            scanf("%d",&sr);
            memset(vis,0,sizeof(vis));
            dfs(sr);

            int cnt=0;
            for(int i=1; i<=n; i++){
                if(vis[i]==0){
                    res[cnt++]=i;
                }
            }

            printf("%d",cnt);
            for(int i=0; i<cnt; i++){
                printf(" %d",res[i]);
            }
            printf("\n");
        }

        for(int i=0; i<=n; i++){
            ed[i].clear();
        }

    }

    return 0;
}
