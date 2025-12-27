#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define make make_pair
#define MAXN 100005
map< int, pair<int,int> >mp;
vector<int>ed[MAXN],cs[MAXN];
int n,N,a[MAXN],L[MAXN],st[MAXN],fn[MAXN],T[MAXN],P[MAXN][20];
ll tree[8*MAXN];
void DFS(int u,int lev,int pr,int w)
{
    st[u] = ++N;
    T[u] = pr;
    L[u] = lev;
    a[u] = w;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        int w = cs[u][i];
        if(v==pr)continue;
        DFS(v,lev+1,u,w);
    }
    fn[u] = ++N;
}
void LCA_init()
{
    memset(P,-1,sizeof(P));
    for(int i=1; i<=n; i++)P[i][0] = T[i];
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(P[i][j-1]!=-1){
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}
int LCA(int u,int v)
{
    if(L[u]<L[v])swap(u,v);
    int log = (int)log2(n);
    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && (L[u]-(1<<i))>=L[v]){
            u = P[u][i];
        }
    }

    if(u==v)return u;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && P[u][i]!=P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return T[u];
}
void update(int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){ tree[nd]=v; return; }
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);
    tree[nd] = tree[lf]+tree[rg];
}
ll query(int nd,int b,int e,int x,int y)
{
    if(b>y || e<x)return 0;
    if(b>=x&&e<=y)return tree[nd];
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    ll p1 = query(lf,b,md,x,y);
    ll p2 = query(rg,md+1,e,x,y);
    return p1+p2;
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<n; i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        ed[u].push_back(v);
        ed[v].push_back(u);
        cs[u].push_back(w);
        cs[v].push_back(w);
        if(u>v)swap(u,v);
        mp[i] = make(u,v);
    }

    N = 0;
    DFS(1,0,0,0);

    LCA_init();

    for(int i=1; i<=n; i++)
    {
        update(1,1,N,st[i],a[i]);
        update(1,1,N,fn[i],-a[i]);
    }

    int Q; scanf("%d",&Q);
    while(Q--)
    {
        int tp; scanf("%d",&tp);
        if(tp==1)
        {
            int r,x; scanf("%d%d",&r,&x);
            int u = mp[r].first;
            int v = mp[r].second;
            if(L[u]>L[v])swap(u,v);
            a[v] = x;
            update(1,1,N,st[v],x);
            update(1,1,N,fn[v],-x);
        }
        else
        {
            int u,v; scanf("%d%d",&u,&v);
            int lca = LCA(u,v);
            ll ret1 = query(1,1,N,st[lca]+1,st[u]);
            ll ret2 = query(1,1,N,st[lca]+1,st[v]);
            ll ans = ret1 + ret2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
10
2 6 9
6 10 4
10 7 2
10 3 1
3 1 8
10 9 9
1 4 1
6 5 6
4 8 4
10
1 5 10
2 7 6
1 4 4
2 9 5
1 5 7
1 5 1
2 4 3
1 5 8
2 4 3
2 8 8
*/
