#include<bits/stdc++.h>
using namespace std;
#define mx 200005
#define ll long long int
ll a[mx];
struct dt
{
    ll sum,prop;
} tree[mx*4];
void update(ll node,ll b,ll e,ll x,ll y,ll v)
{
    if(b>y||e<x)return;
    if(b>=x&&e<=y)
    {
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
    if(b>y||e<x) return 0LL;
    if(b>=x&&e<=y) return tree[node].sum+(e-b+1)*carry;
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,x,y,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,x,y,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    ll n;
    scanf("%I64d",&n);

    for(ll i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
    }

    ll ans = 0;

    for(ll i=1; i<=n; i++)
    {
        ans += query(1,1,n,i,i,0);
        update(1,1,n,1,min(a[i],n),1);
    }

    printf("%I64d\n",ans);
    return 0;

}
