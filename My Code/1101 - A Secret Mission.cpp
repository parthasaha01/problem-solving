#include<bits/stdc++.h>
using namespace std;
int n,m,pa[50005],T[50005],L[50005],S[50005];
int P[50005][20],W[50005][20];
vector<int>ed[50005],cs[50005];
struct Edge{
    int u,v,w;
}gr[100005];
bool cmp(Edge A, Edge B){
    return A.w<B.w;
}
int Find(int x){
    if(pa[x]==x)return x;
    return pa[x] = Find(pa[x]);
}
void MST()
{
    sort(gr+1,gr+m+1,cmp);
    for(int i=1; i<=n; i++)pa[i]=i;

    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        u = gr[i].u;
        v = gr[i].v;
        w = gr[i].w;

        if(Find(u)!=Find(v))
        {
            pa[pa[u]] = pa[v];
            ed[u].push_back(v);
            ed[v].push_back(u);
            cs[u].push_back(w);
            cs[v].push_back(w);
        }
    }
}
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
    memset(W,0,sizeof(W));

    for(int i=1; i<=n; i++){
        P[i][0] = T[i];
        W[i][0] = S[i];
    }
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(P[i][j-1]!=-1){
               P[i][j] = P[P[i][j-1]][j-1];
               W[i][j] = max(W[i][j-1],W[P[i][j-1]][j-1]);
            }
        }
    }
}
int lca_query(int u,int v)
{
    if(L[u]<L[v])swap(u,v);
    int log = (int)log2(n);
    int ans = 0;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && L[u]-(1<<i) >= L[v]){
            ans = max(ans,W[u][i]);
            u = P[u][i];
        }
    }

    if(u==v)return ans;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && P[u][i] != P[v][i]){
            ans = max(ans,W[u][i]);
            ans = max(ans,W[v][i]);
            u = P[u][i];
            v = P[v][i];
        }
    }

    ans = max(ans,W[u][0]);
    ans = max(ans,W[v][0]);
    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);

        scanf("%d%d",&n,&m);

        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            gr[i].u = u;
            gr[i].v = v;
            gr[i].w = w;
        }

        MST();
        DFS(1,-1,0,0);
        lca_init();

        int q; scanf("%d",&q);

        for(int k=1; k<=q; k++)
        {
            int u,v; scanf("%d%d",&u,&v);
            int ans = lca_query(u,v);
            printf("%d\n",ans);
        }

        for(int i=0; i<=n; i++){
            ed[i].clear();
            cs[i].clear();
        }
    }

    return 0;
}
