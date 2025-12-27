#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
ll sum[400005][61];
void update(int nd,int b,int e,int x,ll v)
{
    if(b==x && e==x)
    {
        for(ll i=0; i<=60; i++)
        {
            if((v&(1LL<<i)) == 0)sum[nd][i]=0;
            else sum[nd][i] = 1;
        }
        return;
    }

    int lf = 2*nd, rg=2*nd+1, md = (b+e)/2;
    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);

    for(int i=0; i<=60; i++){
        sum[nd][i] = sum[lf][i]+sum[rg][i];
    }
}
int query(int nd,int b,int e,int x,int y,int k)
{
    if(b>y || e<x)return 0;
    if(b>=x && e<=y)return sum[nd][k];
    int lf = 2*nd, rg=2*nd+1, md = (b+e)/2;
    int p1 = query(lf,b,md,x,y,k);
    int p2 = query(rg,md+1,e,x,y,k);
    return p1+p2;
}
int main()
{
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%lld",&a[i]);
        update(1,1,n,i,a[i]);
    }
    int q; scanf("%d",&q);
    while(q--)
    {
        int t; scanf("%d",&t);
        if(t==1)
        {
            int x; ll v;
            scanf("%d %lld",&x,&v);
            a[x]=v;
            update(1,1,n,x,v);
        }
        else
        {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            if(x>y)swap(x,y);
            int ans = query(1,1,n,x,y,k);
            printf("%d\n",ans);
        }
    }
    return 0;
}
