#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long int
#define mod 1000003 // 1000003 is prime
ll fac[mx+5];
void factorial()
{
    fac[0]=1;
    for(ll i=1; i<mx; i++){
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
}
ll modInv(ll n)
{
    //Extended Euclidean Algorithm
    ll r2=n, r1=mod;
    ll x2=1, y2=0;
    ll x1=0, y1=1;

    while(r1!=0)
    {
        ll q = r2/r1;
        ll r = r2%r1;
        ll x = x2-(q*x1);
        ll y = y2-(q*y1);

        r2=r1, r1=r;
        x2=x1, y2=y1;
        x1=x, y1=y;
    }

    ll x=x2%mod;
    if (x<0) x+= mod;
    return x;
}
int main()
{
    factorial();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n,r;
        scanf("%lld%lld",&n,&r);

        ll lob=fac[n];
        ll hor=(fac[r]*fac[n-r])%mod;
        hor=modInv(hor);

        ll ans=((lob%mod)*(hor%mod))%mod;
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
