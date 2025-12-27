#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007LL
ll bigmod(ll b,ll p)
{
    if(p==1)return b%mod;
    ll res=1LL;
    if(p%2==0){
        res=bigmod(b,p/2)%mod;
        res=((res%mod)*(res%mod))%mod;
    }
    else{
        res=((bigmod(b,p-1)%mod)*(b%mod))%mod;
    }

    return res%mod;
}
ll bionomialCoeff(ll n,ll k)
{
    ll res=1;

    if(k>n-k) k=n-k;

    for(ll i=0; i<k; i++)
    {
        res=((res%mod)*((n-i)%mod))%mod;
        res=((res%mod)*(bigmod(i+1,mod-2)%mod))%mod;
    }

    return res;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        ll n;
        scanf("%lld",&n);

        ll lob=bionomialCoeff(2*n,n);
        ll hor=bigmod(n+1,mod-2)%mod;
        ll ans=((lob%mod)*(hor%mod))%mod;
        printf("%lld\n",ans);
    }

    return 0;
}

