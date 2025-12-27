#include<bits/stdc++.h>
using namespace std;
int indeg[10005];
vector<int>ed[10005];
int nd,cnt;
bool vis[10005];
void dfs(int u)
{
    nd++;
    cnt+=indeg[u];
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];

        if(vis[v]==false)
        {
            dfs(v);
        }
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,m; scanf("%d%d",&n,&m);

        memset(indeg,0,sizeof(indeg));

        for(int i=1; i<=m; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
            indeg[u]++;
            indeg[v]++;
        }

        memset(vis,false,sizeof(vis));
        int mx=0,mn=10000000;
        for(int i=0; i<=n; i++)
        {
            if(vis[i]==false)
            {
                nd=0;
                cnt=0;

                dfs(i);

                cnt = cnt/2;

                if(cnt>=mx)
                {
                    if(cnt>mx)
                    {
                        mn = nd;
                        mx = cnt;
                    }
                    else
                    {
                        if(nd<mn){
                            mn=nd;
                        }
                    }
                }
            }
        }

        printf("Case %d: %d %d\n",ks,mx,mn);

        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}
