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
ll bigmod(ll b,ll p)
{
    ll res=1;
    if(p==1){
        return b%mod;
    }

    if(p%2==0){
        res = (bigmod(b,p/2)%mod);
        res = ((res%mod)*(res%mod))%mod;
    }
    else{
        res = ((bigmod(b,p-1)%mod)*(b%mod)%mod);
    }
    return res%mod;

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

        ll hor=fac[r]*fac[n-r];
        hor%=mod;
        hor=bigmod(hor,mod-2);

        ll ans=((lob%mod)*(hor%mod))%mod;
        printf("Case %d: %lld\n",ks,ans);

    }

    return 0;
}
