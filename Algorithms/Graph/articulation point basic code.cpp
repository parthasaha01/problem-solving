#include<bits/stdc++.h>
using namespace std;
int tim,root,dis[10005],low[10005],par[10005];
vector<int>ed[10005];
bool ap[10005],vis[10005];
void dfs(int u)
{
    vis[u]=true;
    dis[u]=++tim;
    low[u]=tim;
    int child=0;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];

        if(vis[v]==false)
        {
            par[v]=u;
            child++;

            dfs(v);

            low[u]=min(low[u],low[v]);

            if(u==root && child>1)ap[u]=true;
            if(u!=root && dis[u]<=low[v])ap[u]=true;
        }
        else if(v!=par[u]) // backedge
        {
            low[u]=min(low[u],dis[v]);
        }
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,m; scanf("%d%d",&n,&m);

        for(int i=1; i<=m; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        memset(ap,false,sizeof(ap));
        tim=0;
        root=1;
        dfs(1);

        for(int i=1; i<=n; i++){
            if(ap[i])printf("%d ",i);
        }
        printf("\n\n");

//        for(int i=1; i<=n; i++){
//            printf("node=%d dis=%d low=%d par=%d\n",i,dis[i],low[i],par[i]);
//        }

        for(int i=1; i<=n; i++)ed[i].clear();
    }
    return 0;
}
/*
8
8 9
1 2
1 3
2 3
3 4
4 5
5 6
5 7
6 7
6 8

20 27
1 2
2 3
3 4
4 5
5 6
6 8
6 7
8 7
7 5
5 16
3 16
4 9
3 9
9 10
10 11
11 13
13 15
13 14
14 11
11 12
12 9
12 17
17 18
18 19
19 20
18 20
1 3

*/
