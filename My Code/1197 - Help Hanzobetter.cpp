#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sz;
bool vis[46350],isprime[100005];
ll prime[4800];
void sieve()
{
    prime[sz++]=2;
    for(ll i=3; i<=46345; i+=2){
        if(!vis[i]){
            prime[sz++]=i;
            for(ll j=i*i; j<=46345; j+=2*i){
                vis[j]=true;
            }
        }
    }
}
int segmentSieve(ll a,ll b)
{
    memset(isprime,true,sizeof(isprime));
    ll sq=sqrt(b)+1;

    for(ll i=1; prime[i]<=sq && i<sz; i++)
    {
        ll start=(a/prime[i])*prime[i];
        if(start<a){
            start+=prime[i];
        }

        if(start==prime[i]){
            start+=prime[i];
        }

        if(start%2==0){
            start+=prime[i];
        }

        for(ll j=start; j<=b; j+=2*prime[i]){
            isprime[j-a]=false;
        }
    }

    ll cnt=0;
    for(ll i=a; i<=b; i+=2){
        if(isprime[i-a]){
            cnt++;
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
        ll  a,b;
        scanf("%lld%lld",&a,&b);

        if(a>b)
            swap(a,b);

        ll ans=0;

        if(b<2){
            ans=0;
        }
        else if(b==2){
            ans=1;
        }
        else{
            if(a<=2){
                ans=1;
                a=2;
            }

            if(a%2==0){
                a+=1;
            }

            ans+=segmentSieve(a,b);
        }

        printf("Case %d: %lld\n",ks,ans);

    }

    return 0;
}
/*
10
2147483647 2147383647

*/
/*
100000007 100000037 100000039 100000049 100000073 100000081 100000123
100000127 100000193 100000213 100000217 100000223 100000231 100000237
100000259 100000267 100000279 100000357 100000379 100000393 100000399
100000421 100000429 100000463  100000469 100000471 100000493
*/
