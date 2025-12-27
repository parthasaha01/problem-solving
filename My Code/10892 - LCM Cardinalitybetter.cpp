#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 44800
bool vis[mx+2];
int prime[4660],sz;
void sieve()
{
    prime[sz++]=2;
    for(ll i=3; i<=mx; i+=2){
        if(!vis[i]){
            prime[sz++]=i;
            for(ll j=i*i; j<=mx; j+=2*i){
                vis[j]=true;
            }
        }
    }
}
ll getResult(int n)
{
    int expo=0;
    int ans=1;

    for(int i=0; prime[i]*prime[i]<=n&&i<sz; i++)
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

    int n;
    while(scanf("%d",&n)&&n)
    {
        int ans=getResult(n);
        printf("%d %d\n",n,ans);
    }

    return 0;
}
