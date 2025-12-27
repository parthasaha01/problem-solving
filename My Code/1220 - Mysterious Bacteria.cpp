#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool vis[65550];
ll prime[6550],sz;
void sieve()
{
    prime[sz++]=2;
    for(ll i=3; i<=65540; i+=2){
        if(!vis[i]){
            prime[sz++]=i;
            for(ll j=i*i; j<=65540; j+=2*i){
                vis[j]=true;
            }
        }
    }
}
ll factorization(ll x)
{
    ll cnt=9999999;
    ll n=abs(x);

    for(ll i=0; prime[i]<=sqrt(n); i++)
    {
        if(n%prime[i]==0){
            ll k=0;
            while(n%prime[i]==0){
                k++;
                n/=prime[i];
            }
            cnt=min(cnt,k);
        }
    }

    if(n>1){
        cnt=1;
    }

    if(x<0){
        while(cnt%2==0){
            cnt/=2;
        }
    }
    return cnt;
}
int main()
{
    sieve();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll x;
        scanf("%lld",&x);

        ll ans=factorization(x);

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
