#include<bits/stdc++.h>
using namespace std;
int maxx,minn,n,T[100005],L[100005],S[100005];
int P[100005][20],MX[100005][20],MN[100005][20];
vector<int>ed[100005],cs[100005];
void DFS(int u,int fr,int lv,int w)
{
    T[u] = fr;
    L[u] = lv;
    S[u] = w;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        int w = cs[u][i];
        if(v==fr)continue;
        DFS(v,u,lv+1,w);
    }
}
void lca_init()
{
    memset(P,-1,sizeof(P));
    memset(MX,-1,sizeof(MX));
    memset(MN,-1,sizeof(MN));

    for(int i=1; i<=n; i++){
        P[i][0] = T[i];
        MX[i][0] = S[i];
        MN[i][0] = S[i];
    }
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(P[i][j-1]!=-1){
               P[i][j] = P[P[i][j-1]][j-1];
               MX[i][j] = max(MX[i][j-1],MX[P[i][j-1]][j-1]);
               MN[i][j] = min(MN[i][j-1],MN[P[i][j-1]][j-1]);
            }
        }
    }
}
void lca_query(int u,int v)
{
    if(L[u]<L[v])swap(u,v);
    int log = (int)log2(n);
    maxx = 0;
    minn = 100000000;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && L[u]-(1<<i) >= L[v]){
            maxx = max(maxx,MX[u][i]);
            minn = min(minn,MN[u][i]);
            u = P[u][i];
        }
    }

    if(u==v)return;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && P[u][i] != P[v][i]){
            maxx = max(maxx,MX[u][i]);
            maxx = max(maxx,MX[v][i]);
            minn = min(minn,MN[u][i]);
            minn = min(minn,MN[v][i]);
            u = P[u][i];
            v = P[v][i];
        }
    }

    maxx = max(maxx,MX[u][0]);
    maxx = max(maxx,MX[v][0]);
    minn = min(minn,MN[u][0]);
    minn = min(minn,MN[v][0]);

}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);

        scanf("%d",&n);

        for(int i=1; i<=n-1; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ed[u].push_back(v);
            ed[v].push_back(u);
            cs[u].push_back(w);
            cs[v].push_back(w);
        }

        DFS(1,-1,0,0);
        lca_init();

        int q; scanf("%d",&q);

        for(int k=1; k<=q; k++)
        {
            int u,v; scanf("%d%d",&u,&v);
            lca_query(u,v);
            printf("%d %d\n",minn,maxx);
        }

        for(int i=0; i<=n; i++){
            ed[i].clear();
            cs[i].clear();
        }
    }

    return 0;
}

