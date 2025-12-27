#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int n,T[mx],L[mx],P[mx][20];
vector<int>ed[mx];
void dfs(int u,int fr,int dp)   // fr=from, u = current node, dp = depth
{
    T[u] = fr;
    L[u] = dp;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==fr) continue;
        dfs(v,u,dp+1);
    }
}
void lca_init()
{
    memset(P,-1,sizeof(P));
    for(int i=1; i<=n; i++) P[i][0] = T[i];

    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(P[i][j-1]!=-1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int lca_query(int u,int v)
{
    if(L[u]<L[v])swap(u,v);

    int log = (int)log2(n);

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && L[u]-(1<<i)>=L[v]){
            u = P[u][i];
        }
    }

    if(u==v) return u;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && P[u][i]!=P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }

    return T[u];
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        printf("Case %d:\n",ks);
        scanf("%d",&n);

        for(int i=1; i<=n-1; i++){
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        dfs(0,-1,0);
        lca_init();

        int q; scanf("%d",&q);
        for(int i=1; i<=q; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            int lca = lca_query(u,v);
            printf("The LCA of %d and %d is: %d\n",u,v,lca);
        }

        for(int i=0; i<=n; i++) ed[i].clear();
    }
    return 0;
}
