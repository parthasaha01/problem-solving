#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
struct dt
{
    ll sum,prop;
}tree[mx*4];
void update(ll node,ll b,ll e,ll x,ll y,ll v)
{
    if(b>y||e<x){
        return;
    }

    if(b>=x&&e<=y){
        tree[node].sum+=(e-b+1)*v;
        tree[node].prop+=v;
        return;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    update(left,b,mid,x,y,v);
    update(right,mid+1,e,x,y,v);

    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
ll query(ll node,ll b,ll e,ll x,ll y,ll carry)
{
    if(b>y||e<x){
        return 0LL;
    }

    if(b>=x&&e<=y){
        return tree[node].sum+(e-b+1)*carry;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    ll p1=query(left,b,mid,x,y,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,x,y,carry+tree[node].prop);

    return p1+p2;
}
void reset(ll n)
{
    ll sz=4*n;
    for(ll i=0; i<=sz; i++){
        tree[i].sum=0;
        tree[i].prop=0;
    }
}
int main()
{
    ll t;
    scanf("%lld",&t);

    for(ll kase=1; kase<=t; kase++)
    {
        ll n,q;
        scanf("%lld%lld\n",&n,&q);

        reset(n);

        for(ll i=0; i<q; i++)
        {
            ll type;
            scanf("%lld",&type);

            if(type==0)
            {
                ll x,y,v;
                scanf("%lld%lld%lld",&x,&y,&v);

                update(1,1,n,x,y,v);

            }
            else
            {
                ll x,y;
                scanf("%lld%lld",&x,&y);

                ll ans=query(1,1,n,x,y,0LL);
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}

