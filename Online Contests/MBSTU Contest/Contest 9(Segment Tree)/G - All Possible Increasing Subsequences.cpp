#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define mod 1000000007
#define ll long long int
ll a[mx],b[mx],p[mx],pa[mx],r[mx],tree[4*mx];
void update(ll node,ll b,ll e,ll x,ll v)
{
    if(b>x||e<x)
        return;

    if(b==x&&e==x){
        tree[node]+=v;
        tree[node]%=mod;
        return;
    }

    ll left=2*node;
    ll right=2*node+1;
    ll mid=(b+e)/2;

    update(left,b,mid,x,v);
    update(right,mid+1,e,x,v);

    tree[node]=(tree[left]+tree[right])%mod;
}
ll query(ll node,ll b,ll e,ll x, ll y)
{
    if(e<x||b>y){
        return 0LL;
    }
    if(b>=x&&e<=y){
        return tree[node];
    }

    ll left=2*node;
    ll right=2*node+1;
    ll mid=(b+e)/2;

    ll p1=query(left,b,mid,x,y);
    ll p2=query(right,mid+1,e,x,y);

    return (p1+p2)%mod;
}
int main()
{
    ll t;
    scanf("%lld",&t);

    for(ll kase=1; kase<=t; kase++)
    {
        ll n;
        scanf("%lld",&n);

        for(ll i=1; i<=n; i++){
            scanf("%lld",&a[i]);
            b[i]=a[i];
        }

        sort(b+1,b+n+1);

        for(int i=1; i<=n; i++){
            p[i]=lower_bound(b+1,b+1+n,a[i])-b;
        }

        memset(tree,0,sizeof(tree));

        for(ll i=1; i<=n; i++){
            ll x=p[i];
            if(x==1){
                update(1,1,n,x,1LL);
            }
            else{
                ll v=query(1,1,n,1,x-1)+1;
                v%=mod;
                update(1,1,n,x,v);
            }
        }
        ll ans=tree[1];
        printf("Case %lld: %lld\n",kase,ans);
    }

    return 0;
}
