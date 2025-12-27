#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 150000
ll val,pos;
struct dt
{
    ll id,v,s;
}tree[mx*4+5];
ll a[mx+5];
void init(ll nd,ll b,ll e)
{
    if(b==e){
        tree[nd].id=b;
        tree[nd].v=a[b];
        if(a[b])tree[nd].s=1;
        else tree[nd].s=0;
        return;
    }

    ll lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);

    tree[nd].s=tree[lf].s+tree[rg].s;
}
void update(ll nd,ll b,ll e,ll x,ll v,ll f)
{
    if(b==x&&e==x){
        tree[nd].s=f;
        tree[nd].id=x;
        tree[nd].v=v;
        return;
    }

    ll lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    if(x<=md) update(lf,b,md,x,v,f);
    else update(rg,md+1,e,x,v,f);

    tree[nd].s=tree[lf].s+tree[rg].s;
}
dt query(ll nd,ll b,ll e,ll x)
{
    if(b==e){
        return tree[nd];
    }
    ll lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    if(x<=tree[lf].s)
        return query(lf,b,md,x);
    else
        return query(rg,md+1,e,x-tree[lf].s);
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        printf("Case %d:\n",ks);

        memset(a,0,sizeof(a));

        ll p,q;
        scanf("%lld%lld",&p,&q);

        for(int i=1; i<=p; i++){
            scanf("%lld",&a[i]);
        }

        ll n=p+q;

        init(1,1,n);

        for(int i=1; i<=q; i++)
        {
            char ch;
            ll x;
            scanf("\n%c %lld",&ch,&x);

            if(ch=='a')
            {
                p++;
                update(1,1,n,p,x,1);
            }
            else
            {
                if(x>tree[1].s)
                    printf("none\n");
                else{
                    dt v=query(1,1,n,x);
                    printf("%lld\n",v.v);
                    update(1,1,n,v.id,0,0);
                }
            }
        }
    }

    return 0;
}
