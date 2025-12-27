/*Each case contains a line containing two integers a and b (1 ≤ a ≤ b < 231, b - a ≤ 100000).*/
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
int main(){
}
