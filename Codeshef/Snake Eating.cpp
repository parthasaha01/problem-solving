#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
ll a[mx+5],sum[mx+5];
int bSearch(ll v,int n)
{
    int lo=1; int hi=n; int p=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(a[md]>=v){
            hi  = md-1;
        }
        else{
            p  = md;
            lo = md+1;
        }
    }
    return p;
}
int fun(int p, ll v)
{
    int lo=1;
    int hi=p;
    int ans=0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        ll tot  = sum[p]-sum[md-1];
        ll cnt  = p-md+1;
        ll need = (v*cnt)-tot;

        if(need<=md-1){
            ans=max(ans,p-md+1);
            hi=md-1;
        }
        else{
            lo=md+1;
        }
    }
    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,q; scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)
            scanf("%lld",&a[i]);

        sort(a+1,a+n+1);

        sum[0]=0;
        for(int i=1; i<=n; i++)
            sum[i]=sum[i-1]+a[i];

        while(q--)
        {
            ll v; scanf("%lld",&v);

            int p = bSearch(v,n);
            int ans = n-p;
            ans += fun(p,v);

            printf("%d\n",ans);
        }
    }
    return 0;
}
