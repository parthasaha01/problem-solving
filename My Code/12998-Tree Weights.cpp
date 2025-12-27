#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define mx 100005
ll lev[mx+5],dis[mx+5],fin[mx+5],a[mx+5];
ll PW[mx+5],IN[mx+5],tree[8*mx+5],mm;
bool vis[mx+5];
vector<int>ed[mx+5];

void dfs(int u,int lv)
{
    vis[u] = true;
    lev[u] = lv;
    dis[u] = ++mm;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        if(!vis[v]) dfs(v,lv+1);
    }
    fin[u] = ++mm;
}
void update(int nd,int b,int e,int u,ll x)
{
    if(u<b||u>e)return;
    if(b==u&&e==u){tree[nd]=x;return;}
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    update(lf,b,md,u,x);
    update(rg,md+1,e,u,x);
    tree[nd] = (tree[lf]+tree[rg])%mod;
}
ll query(int nd,int b,int e,int u,int v)
{
    if(v<b||u>e)return 0;
    if(b>=u&&e<=v){return tree[nd];}
    int lf=2*nd, rg=2*nd+1, md=(b+e)/2;
    ll lp = query(lf,b,md,u,v);
    ll rp = query(rg,md+1,e,u,v);
    return (lp+rp)%mod;
}
ll BIGMOD(ll b,ll p)
{
    ll ans = 1;
    ll k = b;
    while(p){
        if(p&1){
            ans *= k;
            ans%=mod;
        }
        k*=k;
        k%=mod;
        p = p>>1LL;
    }
    return ans;
}
ll MODINVERSE(ll b)
{
    return BIGMOD(b,mod-2);
}
void PRECALCULATION()
{
    PW[0] = 1;
    IN[0] = MODINVERSE(PW[0]);
    for(int i=1; i<mx; i++)
    {
        PW[i] = (PW[i-1] + PW[i-1])%mod;
        IN[i] = MODINVERSE(PW[i]);
    }
}
int main()
{
    PRECALCULATION();

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);

        int n; scanf("%d",&n);

        for(int i=1; i<n; i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        memset(tree,0,sizeof(tree));
        memset(vis,false,sizeof(vis));
        memset(a,0,sizeof(a));
        mm = 0;

        dfs(1,0);

        int q; scanf("%d",&q);

        for(int i=1; i<=q; i++)
        {
            int tp; scanf("%d",&tp);

            if(tp==1)
            {
                int u; scanf("%d",&u);

                ll sum;
                if(fin[u]-dis[u]>1) // internal node
                {
                    sum = query(1,1,mm,dis[u],fin[u]);
                    ll lx = IN[lev[u]];
                    sum = (sum*lx)%mod;
                }
                else sum = a[u]%mod;    // leaf node

                printf("%lld\n",sum);
            }
            else
            {
                ll u,x; scanf("%lld%lld",&u,&x);

                a[u] = a[u] + x;
                a[u] = (a[u]+mod)%mod;

                ll lx;
                if(lev[u]>0) lx = PW[lev[u]-1];
                else lx = 1;

                ll sum = (a[u]*lx)%mod;
                update(1,1,mm,dis[u],sum);
            }
        }

        for(int i=0; i<=n; i++)ed[i].clear();
    }

    return 0;
}
/*
1

8
1 2
1 3
1 4
3 5
3 6
4 7
6 8
20

2 8 3
1 6
1 3
1 1
2 8 5
1 3

*/
