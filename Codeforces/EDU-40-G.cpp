#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 500005
ll n,r,k;
ll a[mx],b[mx],c[mx],s[mx];
int possible(ll v)
{
    ll value = 0;
    b[n+1]=0;
    for(int i=1; i<=n; i++)b[i]=a[i];
    for(int i=1; i<=r+1; i++)value+=a[i];
    ll cnt = 0,cur=r+1, lf=1,rg=r+1;
    if(cur>n)cur=n;
    for(int i=1; i<=n; i++)
    {

        if(value<v){
            b[rg] += (v-value);
            cnt += (v-value);
            value = v;
        }

        //printf("i=%d value=%lld cnt=%lld b[%lld]=%lld\n",i,value,cnt,cur,b[cur]);

        if(cnt>k)return 0;
        rg++;
        lf = i-r;
        if(lf>0)value -= b[lf];
        if(rg<=n)value += b[rg];
        if(rg>n)rg=n;
    }
    return 1;
}
int main()
{
    scanf("%lld %lld %lld",&n,&r,&k);

    for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
    //for(int i=1; i<=n; i++)s[i]=s[i-1]+a[i];
   // for(int i=1; i<=n; i++)b[i] = a[i] + (s[i-1]-s[max(0LL,i-r-1)]) + (s[min(n,i+r)]-s[i]);

    ll lo = 0;
    ll hi = 2000000000000000000;
    ll ans = 0;

    while(lo<=hi)
    {
        ll md = (lo+hi)/2;
        if(possible(md)){
            ans = md;
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
