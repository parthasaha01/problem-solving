#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long int
struct dt
{
    ll sum,prop;
}tree[mx*4];
ll getGCD(ll a,ll b)
{
    if(a%b==0)
        return b;
    return getGCD(b,a%b);
}
void update(ll node,ll b,ll e,ll x,ll y,ll v,ll lazy)
{
    if(lazy!=-1){
        tree[node].sum=(e-b+1)*lazy;
        tree[node].prop=lazy;
    }

    if(b>y||e<x){
        return;
    }

    if(b>=x&&e<=y){
        tree[node].sum=(e-b+1)*v;
        tree[node].prop=v;
        return;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    update(left,b,mid,x,y,v,tree[node].prop);
    update(right,mid+1,e,x,y,v,tree[node].prop);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=-1;
}
ll query(ll node,ll b,ll e,ll x,ll y,ll lazy)
{
    if(lazy!=-1){
        tree[node].sum=(e-b+1)*lazy;
        tree[node].prop=lazy;
    }

    if(b>y||e<x){
        return 0LL;
    }

    if(b>=x&&e<=y){
        return tree[node].sum;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    ll p1=query(left,b,mid,x,y,tree[node].prop);
    ll p2=query(right,mid+1,e,x,y,tree[node].prop);
    tree[node].prop=-1;

    return p1+p2;
}
void reset(ll n)
{
    ll sz=4*n;
    for(ll i=0; i<=sz; i++){
        tree[i].sum=0;
        tree[i].prop=-1;
    }
}
int main()
{
    ll t;
    scanf("%lld",&t);

    for(ll kase=1; kase<=t; kase++)
    {
        printf("Case %lld:\n",kase);

        ll n,q;
        scanf("%lld%lld\n",&n,&q);

        reset(n);

        for(ll i=1; i<=q; i++)
        {
            ll type;
            scanf("%lld",&type);

            if(type==1)
            {
                ll x,y,v;
                scanf("%lld%lld%lld",&x,&y,&v);
                x++,y++;

                update(1,1,n,x,y,v,-1);
            }
            else
            {
                ll x,y;
                scanf("%lld%lld",&x,&y);
                x++,y++;

                ll sum=query(1,1,n,x,y,-1);
                ll cnt=y-x+1;

                if(sum%cnt==0){
                    printf("%lld\n",sum/cnt);
                }
                else{
                    ll gcd=getGCD(sum,cnt);
                    printf("%lld/%lld\n",sum/gcd,cnt/gcd);
                }
            }
        }
    }

    return 0;
}
