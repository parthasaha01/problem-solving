#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1000005
bool vis[mx];
vector<int>prime;
void sieve()
{
    prime.push_back(2);
    for(ll i=3; i<mx; i+=2){
        if(!vis[i]){
            prime.push_back(i);
            for(ll j=i*i; j<mx; j+=i+i){
                vis[j]=true;
            }
        }
    }
}
ll numberOfDivisor(ll n)
{
    ll ans=1;
    int sz=prime.size();
    for(int i=0; prime[i]<=sqrt(n)&&i<sz; i++)
    {

        int cnt=0;
        while(n%prime[i]==0){
            cnt++;
            n/=prime[i];
        }

        if(cnt) ans*=(cnt+1);
    }
    if(n>1)
        ans*=2;

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
        ll ans=numberOfDivisor(n);
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
