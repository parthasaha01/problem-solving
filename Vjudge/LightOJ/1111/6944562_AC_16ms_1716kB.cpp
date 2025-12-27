#include<bits/stdc++.h>
using namespace std;
vector<int>ed[1006];
int k,n,m,cnt,ka[105],city[1005];
bool vis[1005];
void dfs(int u)
{
    vis[u]=true;
    city[u]++;

    for(int i=0; i<ed[u].size(); i++){
        int v=ed[u][i];
        if(vis[v]==false){
            dfs(v);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d%d%d",&k,&n,&m);

        for(int i=0; i<k; i++){
            scanf("%d",&ka[i]);
        }

        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            ed[u].push_back(v);
        }

        for(int i=0; i<k; i++){
            memset(vis,false,sizeof(vis));
            dfs(ka[i]);
        }

        int res=0;
        for(int i=1; i<=n; i++){
            if(city[i]==k){
                res++;
            }
        }
        printf("Case %d: %d\n",kase,res);

        for(int i=0; i<=n; i++){
            ed[i].clear();
            city[i]=0;
        }
    }

    return 0;
}