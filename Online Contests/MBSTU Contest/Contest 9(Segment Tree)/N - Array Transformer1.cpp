#include<bits/stdc++.h>
using namespace std;
#define mx 300005
#define ll long long int
#define INF 999999999999999
ll a[mx],k;
struct dt
{
    ll maxx,minn;
}tree[mx*4];

void init(ll node,ll b,ll e)
{
    if(b==e){
        tree[node].maxx=a[b];
        tree[node].minn=a[b];
        return;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].maxx=max(tree[left].maxx,tree[right].maxx);
    tree[node].minn=min(tree[left].minn,tree[right].minn);
}
void update(ll node,ll b,ll e,ll x)
{
    if(b>x||e<x){
        return;
    }

    if(b==x&&e==x){
        tree[node].maxx=a[x];
        tree[node].minn=a[x];
        return;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    update(left,b,mid,x);
    update(right,mid+1,e,x);

    tree[node].maxx=max(tree[left].maxx,tree[right].maxx);
    tree[node].minn=min(tree[left].minn,tree[right].minn);
}
void query(ll node,ll b,ll e,ll x,ll y,ll v)
{
    if(b>y||e<x){
        return;
    }
    if(tree[node].minn>=v){
        return;
    }
    if(tree[node].maxx<v){
        if(b>=x&&e<=y){
            k+=e-b+1;
        }
        else if(x>=b&&y<=e){
            k+=y-x+1;
        }
        else if(b<x&&e<y){
            k+=e-x+1;
        }
        else if(b>x&&e>y){
            k+=y-b+1;
        }
        return;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    query(left,b,mid,x,y,v);
    query(right,mid+1,e,x,y,v);
}
int main()
{
    ll n,m,u;
    while(scanf("%lld%lld%lld",&n,&m,&u)==3)
    {
        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }

        init(1,1,n);

        for(int i=1; i<=m; i++)
        {
            ll l,r,v,p;
            scanf("%lld%lld%lld%lld",&l,&r,&v,&p);

            k=0;
            query(1,1,n,l,r,v);
            //printf("k=%lld\n",k);
            a[p]=(u*k)/(r-l+1);
            update(1,1,n,p);
        }

        for(int i=1; i<=n; i++){
            printf("%lld\n",a[i]);
        }

    }

    return 0;
}
