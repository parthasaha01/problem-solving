#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,k,mod;
ll a[1005];
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
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%lld%lld%lld",&n,&k,&mod);

        for(int i=0; i<n; i++){
            scanf("%lld",&a[i]);
        }

        ll sum=0;;
        for(int i=0; i<n; i++){
            sum+=a[i];
            sum%=mod;
        }

        ll bgmd;
        if(k==1){
            bgmd=1;
        }
        else{
            bgmd=bigmod(n,k-1);
        }

        ll ans=((bgmd%mod)*(k%mod))%mod;
        ans=((ans%mod)*(sum%mod))%mod;

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
