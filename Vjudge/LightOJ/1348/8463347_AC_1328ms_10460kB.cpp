#include<bits/stdc++.h>
using namespace std;
#define mx 30009
int L[mx+5],T[mx+5],st[mx+5],fn[mx+5],P[mx+5][16];
int ar[mx+5],tree[8*mx],mm,n,nn;
int HH[mx+5],LL[2*mx],EE[2*mx],rmq[8*mx];
vector<int>ed[mx+5];

void dfs(int u,int lev,int fr)
{
    st[u] = ++mm;
    T[u]  = fr;
    L[u]  = lev;

    HH[u]  = ++nn;
    LL[nn] = lev;
    EE[nn] = u;

    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==fr)continue;
        dfs(v,lev+1,u);
    }
    fn[u] = ++mm;
    ++nn;
    LL[nn] = lev-1;
    EE[nn] = fr;
}
void RMQ_init(int nd,int b,int e)
{
    if(b==e){ rmq[nd]=b; return;}
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    RMQ_init(lf,b,md);
    RMQ_init(rg,md+1,e);
    if(LL[rmq[lf]]<=LL[rmq[rg]])rmq[nd]=rmq[lf];
    else rmq[nd]=rmq[rg];
}
int RMQ_query(int nd,int b,int e,int x,int y)
{
    if(y<b||x>e)return 0;
    if(b>=x&&e<=y)return rmq[nd];
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    int p1 = RMQ_query(lf,b,md,x,y);
    int p2 = RMQ_query(rg,md+1,e,x,y);

    if(LL[p1]<=LL[p2])return p1;
    else return p2;
}
int lca_query(int u,int v)
{
    LL[0] = 1000000000;
    int x = HH[u];
    int y = HH[v];
    if(x>y)swap(x,y);
    int id = RMQ_query(1,1,nn,x,y);
    return EE[id];
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

        mm=0;nn=0;
        dfs(1,0,0);

        RMQ_init(1,1,nn);
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

