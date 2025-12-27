#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 50005
#define MOD 1000000007LL
ll n,a[mx+5],tree[4*mx];
ll Modulas(ll num)
{
    if(num>0)return num%MOD;
    if(num==0)return 0;
    num = (-1)*num;
    ll m = num%MOD;
    if(m==0)return 0;
    return MOD-m;
}
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd]=Modulas(a[b]);
        return;
    }

    int lf = nd*2; int rg = lf+1; int md=(b+e)/2;
    init(lf,b,md);
    init(rg,md+1,e);
    tree[nd] = tree[lf]*tree[rg];
    tree[nd] = Modulas(tree[nd]);
}
void update(int nd,int b,int e,int x,int y)
{
    if(b==x && e==x){
        tree[nd]=Modulas(y);
        return;
    }

    int lf = nd*2; int rg = lf+1; int md=(b+e)/2;

    if(x<=md)update(lf,b,md,x,y);
    else update(rg,md+1,e,x,y);

    tree[nd] = tree[lf]*tree[rg];
    tree[nd] = Modulas(tree[nd]);
}
ll query(int nd,int b,int e,int x,int y)
{
    if(b>y || e<x){
        return 1LL;
    }

    if(b>=x && e<=y){
        return Modulas(tree[nd]);
    }

    int lf = nd*2; int rg = lf+1; int md=(b+e)/2;

    ll p1 = query(lf,b,md,x,y);
    ll p2 = query(rg,md+1,e,x,y);

    p1 = Modulas(p1);
    p2 = Modulas(p2);
    ll p = p1*p2;
    p = Modulas(p);
    return p;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }

        init(1,1,n);

        int q; scanf("%d",&q);

        while(q--)
        {
            int c,x,y;
            scanf("%d%d%d",&c,&x,&y);

            if(c==0)
            {
                if(x>y)swap(x,y);

                ll ans = query(1,1,n,x,y);
                ans = Modulas(ans);
                printf("%lld\n",ans);
            }
            else
            {
                update(1,1,n,x,y);
            }
        }
    }

    return 0;
}
