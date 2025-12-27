#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>pr;
int vis[100005];
void sieve()
{
    vis[1] = 1;

    for(ll i=2; i<=100000; i++)
    {
        if(vis[i]==0)
        {
            pr.push_back(i);

            for(ll j=i+i; j<=100000; j+=i)
            {
                vis[j]=1;
            }
        }
    }
}
int isprime(ll n,ll p)
{
    for(ll i=0; i<pr.size() && pr[i]<=p; i++)
    {
        if(n%pr[i]==0)return 0;
    }
    return 1;
}
int main()
{
    sieve();
    ll p,y;
    scanf("%lld %lld",&p,&y);
    ll ans = -1;
    for(ll n=y; n>p ; n--)
    {
        if(isprime(n,p)==1){
            ans = n;
            //cout << n << " ";
            break;
        }
    }

    //
    //cout << endl;

    if(p==y)ans=-1;

    printf("%lld\n",ans);

    return 0;
}
