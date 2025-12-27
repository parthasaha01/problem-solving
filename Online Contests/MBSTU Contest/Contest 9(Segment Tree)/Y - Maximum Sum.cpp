#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
struct dt
{
    ll maxf,maxs;
}tree[mx*4];
ll a[mx],s[4];

void twoMaximum(dt p1, dt p2)
{
    s[0]=p1.maxf;
    s[1]=p1.maxs;
    s[2]=p2.maxf;
    s[3]=p2.maxs;
    sort(s,s+4);
    return;
}
void init(ll node,ll b, ll e)
{
    if(b==e){
        tree[node].maxf=a[b];
        tree[node].maxs=0;
        return;
    }

    ll left=2*node;
    ll right=2*node+1;
    ll mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    twoMaximum(tree[left],tree[right]);

    tree[node].maxf=s[3];
    tree[node].maxs=s[2];
}
void update(ll node,ll b,ll e,ll x,ll v)
{
    if(b>x||e<x)
        return;
    if(b==e&&b==x){
        tree[node].maxf=v;
        tree[node].maxs=0;
        return;
    }

    ll left=2*node;
    ll right=2*node+1;
    ll mid=(b+e)/2;

    update(left,b,mid,x,v);
    update(right,mid+1,e,x,v);

    twoMaximum(tree[left],tree[right]);

    tree[node].maxf=s[3];
    tree[node].maxs=s[2];
}
dt query(ll node,ll b,ll e,ll x, ll y)
{
    if(b>y||e<x){
        dt p;
        p.maxf=0;
        p.maxs=0;
        return p;
    }
    if(b>=x&&e<=y){
        return tree[node];
    }

    ll left=2*node;
    ll right=2*node+1;
    ll mid=(b+e)/2;

    dt p1=query(left,b,mid,x,y);
    dt p2=query(right,mid+1,e,x,y);

    twoMaximum(p1,p2);
    dt p;
    p.maxf=s[3];
    p.maxs=s[2];

    return p;
}
int main()
{
    ll n;
    while(scanf("%lld",&n)==1)
    {
        for(ll i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }

        init(1,1,n);

        ll q;
        scanf("%lld",&q);

        for(int i=1; i<=q; i++)
        {
            getchar();
            char type;
            scanf("%c",&type);

            if(type=='U')
            {
                ll x,v;
                scanf("%lld%lld",&x,&v);
                update(1,1,n,x,v);
            }
            else
            {
                ll x,y;
                scanf("%lld%lld",&x,&y);
                dt ans=query(1,1,n,x,y);
                printf("%lld\n",ans.maxf+ans.maxs);
            }
        }
    }

    return 0;
}
