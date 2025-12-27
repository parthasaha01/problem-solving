#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mx 100001
ll n,a[mx+5],pw[mx+5];
bool cmp(ll x,ll y){
    return x>y;
}
int main()
{
    while(scanf("%lld",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }

        sort(a+1,a+n+1,cmp);

        if(n==1){
            printf("0\n");
            continue;
        }
        if(n==2){
            printf("%d\n",a[1]-a[2]);
            continue;
        }

        pw[0]=1;
        for(int i=1; i<=mx; i++){
            pw[i]=pw[i-1]*2;
            pw[i]%=mod;
        }

        ll p = pw[n-2];
        ll ans = 0;
        for(ll i=n-1,k=1; i>=1; i--,k++)
        {
            ll v = (k*p);
            v %= mod;
            v *= a[i];
            v %= mod;

            ans += v;
            ans %= mod;
        }

        for(ll i=2,k=1; i<=n; i++,k++)
        {
            ll v = (k*p);
            v %= mod;
            v *= a[i];
            v %= mod;

            ans -= v;
            if(ans<0)ans=(ans+mod)%mod;
            if(ans>=mod)ans%=mod;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
