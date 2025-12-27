#include<bits/stdc++.h>
using namespace std;
#define mx 30009
int L[mx+5],T[mx+5],st[mx+5],fn[mx+5],P[mx+5][16];
int ar[mx+5],tree[8*mx],mm,n;
vector<int>ed[mx+5];

void dfs(int u,int lev,int fr)
{
    st[u] = ++mm;
    T[u]  = fr;
    L[u]  = lev;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==fr)continue;
        dfs(v,lev+1,u);
    }
    fn[u] = ++mm;
}
void lca_init()
{
    memset(P,-1,sizeof(P));
    for(int i=1; i<=n; i++)P[i][0] = T[i];

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
        if(P[u][i]!=-1 && L[u]-(1<<i)>=L[v])
            u = P[u][i];
    }

    if(u==v)return u;

    for(int i=log; i>=0; i--){
        if(P[u][i]!=-1 && P[u][i] != P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }

    return T[u];
}
void update(int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){ tree[nd]=v; return;}
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);
    tree[nd] = tree[lf]+tree[rg];
}
int query(int nd,int b,int e,int x,int y)
{
    if(y<b||x>e)return 0;
    if(b>=x&&e<=y)return tree[nd];
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    int p1 = query(lf,b,md,x,y);
    int p2 = query(rg,md+1,e,x,y);
    return p1+p2;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);
        scanf("%d",&n);

        for(int i=1; i<=n; i++)scanf("%d",&ar[i]);

        for(int i=1; i<n; i++){
            int u,v; scanf("%d%d",&u,&v);
            u++,v++;
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        mm=0;
        dfs(1,0,0);

        lca_init();
        memset(tree,0,sizeof(tree));

        for(int i=1; i<=n; i++)
        {
            update(1,1,mm,st[i],ar[i]);
            update(1,1,mm,fn[i],-ar[i]);
        }

        int q; scanf("%d",&q);

        for(int k=1; k<=q; k++)
        {
            int tp; scanf("%d",&tp);

            if(tp==0)
            {
                int x,y; scanf("%d%d",&x,&y);
                x++,y++;
                int lca  = lca_query(x,y);
                int ans1 = query(1,1,mm,st[lca],st[x]);
                int ans2 = query(1,1,mm,st[lca],st[y]);
                int ans  = ans1+ans2-ar[lca];
                printf("%d\n",ans);
            }
            else
            {
                int x,v; scanf("%d%d",&x,&v);
                x++;
                ar[x] = v;
                update(1,1,mm,st[x],v);
                update(1,1,mm,fn[x],-v);
            }
        }

        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}
