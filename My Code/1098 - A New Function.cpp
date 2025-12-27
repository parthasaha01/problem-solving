#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll CSOD(ll n)
{
    if(n==0) return 0;

    ll sq=sqrt((double)n);
    ll ans=0;
    ll prev=n;
    ll e=n;
    ll cnt=0;
    for(ll i=2; i<=sq; i++)
    {
        ll cur=(n/i);
        ll p=prev-cur;
        cnt+=p;
        ans+=i*cur;

        ll a=e-p+1;
        ll s=(p*(2*a+(p-1)))/2;
        ans+=s*(i-1);

        e=a-1;
        prev=cur;
    }

    cnt=n-(sq+cnt);

    for(ll i=sq+1; cnt>0; i++,cnt--){
        ans+=i*(n/i);
    }

    ll p=n-1;
    ll a=2;
    ll s=(p*(2*a+(p-1)))/2;
    ans-=s;

    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n;
        scanf("%lld",&n);
        ll ans=CSOD(n);
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
