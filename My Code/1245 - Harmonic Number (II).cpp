#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll calculate(ll n)
{
    ll sq=sqrt(n);
    ll sum=0;
    ll prev=n;
    ll cnt=0;

    for(ll i=1; i<=sq; i++)
    {
        ll cur=(n/i);
        ll x=prev-cur;
        cnt+=x;
        sum+=cur;
        sum+=x*(i-1);
        prev=cur;
    }

    ll x=n-(sq+cnt);

    if(x>0)
    {
        for(ll i=sq+1,k=1; k<=x; i++,k++){
            sum+=(n/i);
        }
    }

    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n;
        scanf("%lld",&n);

        ll ans=calculate(n);
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
