#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mxn 509
#define inf 1e15
ll minn,maxx,a[mxn*mxn];

struct data{
    ll mn,mx;
}tree[4*mxn*mxn];

void build(ll node,ll b,ll e)
{
    if(b==e){
        tree[node].mn=a[b];
        tree[node].mx=a[b];
        return;
    }

    ll L=node*2;
    ll R=node*2+1;
    ll mid=(b+e)/2;

    build(L,b,mid);
    build(R,mid+1,e);

    tree[node].mx=max(tree[L].mx,tree[R].mx);
    tree[node].mn=min(tree[L].mn,tree[R].mn);
}

void update(ll node,ll b,ll e,ll x,ll v)
{
    //printf("%lld %lld %lld %lld %lld\n",node,b,e,x,v);
    //getchar();
    if(b==x && e==x){
        tree[node].mx=v;
        tree[node].mn=v;
        return;
    }

    ll L=node*2;
    ll R=node*2+1;
    ll mid=(b+e)/2;

    if(x<=mid) update(L,b,mid,x,v);
    else update(R,mid+1,e,x,v);

    tree[node].mx=max(tree[L].mx,tree[R].mx);
    tree[node].mn=min(tree[L].mn,tree[R].mn);
}

void query(ll node,ll b,ll e,ll x,ll y){
    if(b>y || e<x) return;
    if(b>=x && e<=y){
        maxx=max(maxx,tree[node].mx);
        minn=min(minn,tree[node].mn);
        return;
    }

    ll L=node*2;
    ll R=node*2+1;
    ll mid=(b+e)/2;

    query(L,b,mid,x,y);
    query(R,mid+1,e,x,y);
}

int main()
{
    ll n; scanf("%lld",&n);
    for(int i=1;i<=n*n;i++) scanf("%lld",&a[i]);

cout << "n=" << n*n << endl;
    build(1,1,n*n);
cout << "n=" << n*n << endl;

    int q;
 scanf("%lld",&q);
    getchar();
    cout << "na=" << n << endl;
    for(int k=1;k<=q;k++)
    {
        cout << "nb=" << n*n << endl;
        char ch;
        scanf("%c",&ch);
        cout << "nc=" << n*n << endl;
        if(ch=='q')
        {
            minn=inf; maxx=-inf;
            ll x,y,x1,y1;
            scanf("%lld %lld %lld %lld",&x,&y,&x1,&y1);
            getchar();
            cout << "n=" << n*n << endl;
            //cout << x << " " << y << " " << x1 << " " << y1 << endl;
            while(x<=x1)
            {
                ll st,ed;
                st=((x-1)*n)+y;
                ed=((x-1)*n)+y1;
                cout << "n=" << n*n << endl;
                query(1,1,n*n,st,ed);
                x++;
            }

            printf("%lld %lld\n",maxx,minn);
        }
        else{
            ll x,y,v;
            scanf("%lld %lld %lld",&x,&y,&v);
            getchar();
            cout << x << " " << y << " " << v << endl;
            x=((x-1)*n)+y;
            //cout << "partha" << endl;
            cout << n*n << endl;
            update(1,1,n*n,x,v);
            //cout << "konika" << endl;
        }
    }

    return 0;
}
