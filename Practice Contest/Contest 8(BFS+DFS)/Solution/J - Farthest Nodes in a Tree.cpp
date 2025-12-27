#include<bits/stdc++.h>
using namespace std;
#define mx 30005
bool vis[mx];
vector<int>ed[mx];
vector<int>cost[mx];
int n,maxx,node;
void reset()
{
    for(int i=0; i<=n; i++)
    {
        ed[i].clear();
        cost[i].clear();
        vis[i]=false;
    }
}
void dfs1(int u, int weight)
{
    vis[u]=true;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v=ed[u][i];

        if(vis[v]==false)
        {
            int w=cost[u][i];
            if(weight+w>=maxx){
                maxx=weight+w;
                node=v;
            }
            dfs1(v,weight+w);
        }
    }
    vis[u]=false;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%d",&n);

        reset();

        for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ed[u].push_back(v);
            ed[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        maxx=0;
        dfs1(0,0);

        maxx=0;
        dfs1(node,0);

        printf("Case %d: %d\n",kase,maxx);
    }

    return 0;
}
