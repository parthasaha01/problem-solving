#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e15
ll minn,maxx,a[505*505];

struct data{
    ll mn,mx;
} tree[4*505*505];

void build(ll nd,ll b,ll e)
{
    if(b==e){
        tree[nd].mn=a[b];
        tree[nd].mx=a[b];
        return;
    }

    ll md=(b+e)>>1, L=nd<<1, R=L+1;

    build(L,b,md);
    build(R,md+1,e);

    tree[nd].mx=max(tree[L].mx,tree[R].mx);
    tree[nd].mn=min(tree[L].mn,tree[R].mn);
}

void update(ll nd,ll b,ll e,ll x,ll v)
{
    if(b==x && e==x){
        tree[nd].mx=v;
        tree[nd].mn=v;
        return;
    }

    ll md=(b+e)>>1, L=nd<<1, R=L+1;

    if(x<=md) update(L,b,md,x,v);
    else update(R,md+1,e,x,v);

    tree[nd].mx=max(tree[L].mx,tree[R].mx);
    tree[nd].mn=min(tree[L].mn,tree[R].mn);
}

void query(ll nd,ll b,ll e,ll x,ll y)
{
    if(b>y || e<x) return;
    if(b>=x && e<=y){
        maxx=max(maxx,tree[nd].mx);
        minn=min(minn,tree[nd].mn);
        return;
    }

    ll md=(b+e)>>1, L=nd<<1, R=L+1;

    query(L,b,md,x,y);
    query(R,md+1,e,x,y);
}

int main()
{
    ll n; scanf("%lld",&n);
    for(int i=1;i<=n*n;i++) scanf("%lld",&a[i]);

    build(1,1,n*n);

    ll q; scanf("%lld",&q); getchar();

    for(int i=1; i<=q; i++)
    {
        char ch; scanf("%c",&ch);
        if(ch=='q')
        {
            ll x,y,x1,y1;
            scanf("%lld %lld %lld %lld",&x,&y,&x1,&y1);
            getchar();

            minn=inf; maxx=-inf;
            while(x<=x1)
            {
                ll st=((x-1)*n)+y;
                ll ed=((x-1)*n)+y1;
                query(1,1,n*n,st,ed);
                x++;
            }
            printf("%lld %lld\n",maxx,minn);
        }
        else
        {
            ll x,y,v;
            scanf("%lld %lld %lld",&x,&y,&v); getchar();
            x=((x-1)*n)+y;
            update(1,1,n*n,x,v);
        }
    }
    return 0;
}
