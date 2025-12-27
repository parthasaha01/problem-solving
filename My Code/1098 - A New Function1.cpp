#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll CSOD(ll n)
{
    ll ans=0;
    ll sq=sqrt((double)n);

    for(ll i=2; i<=sq; i++)
    {
        ll j = n/i;
        ans += ((j*(j+1))/2) - ((i*(i-1))/2);
        ans += i*(j-i);
    }

    return ans;
}
int main()
{
    int ks=1;
    ll n;
    while(scanf("%lld",&n)&&n)
    {
        ll ans=CSOD(n);
        printf("Case %d: %lld\n",ks++,ans);
    }

    return 0;
}
