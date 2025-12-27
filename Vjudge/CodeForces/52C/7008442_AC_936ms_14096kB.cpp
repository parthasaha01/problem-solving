#include<bits/stdc++.h>
using namespace std;
#define INF 99999999999999999
#define mx 200005
#define ll long long int
ll a[mx];
struct dt
{
    ll minn,prop;
}tree[mx*4];
void init(ll node,ll b,ll e)
{
    tree[node].prop=0;

    if(b==e){
        tree[node].minn=a[b];
        return;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].minn=min(tree[left].minn,tree[right].minn);
}
void update(ll node,ll b,ll e,ll x,ll y,ll v)
{
    if(b>y||e<x){
        return;
    }

    if(b>=x&&e<=y){
        tree[node].minn+=v;
        tree[node].prop+=v;
        return;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    update(left,b,mid,x,y,v);
    update(right,mid+1,e,x,y,v);

    tree[node].minn=min(tree[left].minn,tree[right].minn)+tree[node].prop;
}
ll query(ll node,ll b,ll e,ll x,ll y,ll carry)
{
    if(b>y||e<x){
        return INF;
    }

    if(b>=x&&e<=y){
        return tree[node].minn+carry;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    ll p1=query(left,b,mid,x,y,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,x,y,carry+tree[node].prop);

    return min(p1,p2);
}
int main()
{
    ll n;
    while(scanf("%I64d",&n)==1)
    {
        for(ll i=0; i<n; i++){
            scanf("%I64d",&a[i]);
        }

        init(1,0,n-1);

        ll q;
        scanf("%I64d\n",&q);

        for(ll i=0; i<q; i++)
        {
            char ch;
            ll x,y;
            scanf("%I64d%I64d%c",&x,&y,&ch);

            if(ch=='\n')
            {
                if(x<=y)
                {
                    ll ans=query(1,0,n-1,x,y,0LL);
                    printf("%I64d\n",ans);
                }
                else
                {
                    ll ans1=query(1,0,n-1,x,n-1,0LL);
                    ll ans2=query(1,0,n-1,0,y,0LL);
                    ll ans=min(ans1,ans2);
                    printf("%I64d\n",ans);
                }
            }
            else
            {
                ll v;
                scanf("%I64d",&v);
                if(x<=y)
                {
                    update(1,0,n-1,x,y,v);
                }
                else
                {
                    update(1,0,n-1,x,n-1,v);
                    update(1,0,n-1,0,y,v);
                }
            }
        }
    }

    return 0;
}
