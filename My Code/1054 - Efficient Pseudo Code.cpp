#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007  // mod 1000000007 is prime
vector<ll>prime;
bool vis[46355];
void sieve()
{
    prime.push_back(2);
    for(ll i=3; i<=46350; i+=2){
        if(!vis[i]){
            prime.push_back(i);
            for(ll j=i*i; j<=46350; j+=i+i){
                vis[j]=true;
            }
        }
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
ll factorization(ll n, ll m)
{
    ll ans=1;
    ll sz=prime.size();
    for(ll i=0; prime[i]<=sqrt(n)&&i<sz; i++)
    {
        if(n%prime[i]==0)
        {
            ll cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            cnt*=m;
            ll lob=bigmod(prime[i],cnt+1)-1;

            ll hor=prime[i]-1;
            hor=bigmod(hor,mod-2);  //Modular multiplicative inverse

            ll bmod=((lob%mod)*(hor%mod))%mod;

            ans*=bmod;
            ans%=mod;
        }
    }

    if(n!=1)
    {
        ll lob=bigmod(n,m+1)-1;

        ll hor=n-1;
        hor=bigmod(hor,mod-2);

        ll bmod=((lob%mod)*(hor%mod))%mod;

        ans*=bmod;
        ans%=mod;
    }

    return ans%mod;
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n,m,ans;
        scanf("%lld%lld",&n,&m);

        if(n==mod)
            ans=1;
        else
            ans=factorization(n,m);

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
