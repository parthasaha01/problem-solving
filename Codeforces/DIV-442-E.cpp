#include<bits/stdc++.h>
using namespace std;
#define mx 200000
int n,sz,vis[mx+5],dis[mx+5],fin[mx+5],cost[mx+5];
int a[mx+5];
struct dt{
    int sum,lazy;
}tree[4*mx+5];
vector<int>ed[mx+5];
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd].lazy = 0;
        tree[nd].sum = a[b]; return;
    }

    int lf,rg,md;
    lf = 2*nd; rg = lf+1; md = (b+e)/2;
    init(lf,b,md);
    init(rg,md+1,e);
    tree[nd].sum = tree[lf].sum+tree[rg].sum;
    tree[nd].lazy = 0;
}
void update(int nd,int b,int e,int x,int y)
{
    int lf,rg,md;
    lf = 2*nd; rg = lf+1; md = (b+e)/2;

    if(tree[nd].lazy!=0)
    {
        tree[nd].sum = (e-b+1)-tree[nd].sum;
        if(b!=e){
            tree[lf].lazy ^= 1;
            tree[rg].lazy ^= 1;
        }
        tree[nd].lazy = 0;
    }

    if(b>y||e<x)return;
    if(b>=x&&e<=y)
    {
        tree[nd].sum = (e-b+1)-tree[nd].sum;

        if(b!=e){
            tree[lf].lazy ^= 1;
            tree[rg].lazy ^= 1;
        }
        return;
    }

    update(lf,b,md,x,y);
    update(rg,md+1,e,x,y);
    tree[nd].sum = tree[lf].sum+tree[rg].sum;
}
int query(int nd,int b,int e,int x,int y)
{
    int lf,rg,md;
    lf = 2*nd; rg = lf+1; md = (b+e)/2;

    if(tree[nd].lazy!=0)
    {
        tree[nd].sum = (e-b+1)-tree[nd].sum;
        if(b!=e){
            tree[lf].lazy ^= 1;
            tree[rg].lazy ^= 1;
        }
        tree[nd].lazy = 0;
    }
    if(b>y||e<x)return 0;
    if(b>=x&&e<=y) return tree[nd].sum;

    int p1 = query(lf,b,md,x,y);
    int p2 = query(rg,md+1,e,x,y);
    return p1+p2;
}
void DFS(int u)
{
    dis[u]=++sz;
    vis[u]=1;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(vis[v]==0)DFS(v);
    }
    fin[u] = sz;
}
int main()
{
    scanf("%d",&n);
    for(int i=2; i<=n; i++){
        int u; scanf("%d",&u);
        ed[u].push_back(i);
        ed[i].push_back(u);
    }

    for(int i=1; i<=n; i++) scanf("%d",&cost[i]);

    DFS(1);

    for(int i=1; i<=n; i++) a[dis[i]]=cost[i];

    init(1,1,n);

    int qq,v; scanf("%d",&qq);
    char qr[10];

    while(qq--)
    {
        scanf("%s %d",&qr,&v);

        if(qr[0]=='p')
        {
            int x = dis[v];
            int y = fin[v];
            update(1,1,n,x,y);
        }
        else
        {
            int x = dis[v];
            int y = fin[v];
            int ans = query(1,1,n,x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*

10
1 2 3 3 5 5 7 7 8
0 0 0 0 1 1 1 1 0 0
10
pow 3
get 1
pow 9
get 1
get 1
get 8
pow 8
pow 4
get 10
pow 2
*/
