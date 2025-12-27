#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 10000000
bool vis[mx+2];
vector<ll>prime;
void sieve()
{
    prime.push_back(2);
    for(ll i=3; i<=mx; i+=2){
        if(!vis[i]){
            prime.push_back(i);
            for(ll j=i*i; j<=mx; j+=2*i){
                vis[j]=true;
            }
        }
    }
}
ll getResult(ll n)
{
    ll expo=0;
    ll ans=1;
    int sz=prime.size();
    for(ll i=0; prime[i]*prime[i]<=n&&i<sz; i++)
    {
        expo=0;
        while(n%prime[i]==0){
            expo++;
            n/=prime[i];
        }
        if(expo>0){
            ans*=(2*expo)+1;
        }
    }
    if(n>1){
        ans*=2+1;
    }

    ans=(ans/2)+1;

    return ans;
}
int main()
{
    sieve();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n;
        scanf("%lld",&n);

        ll ans=getResult(n);

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
