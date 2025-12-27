#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll calculate(ll n)
{
    ll sq=sqrt(n);
    ll sum=0;
    ll prev=n;
    ll cnt=n;

    for(ll i=1; i<=sq; i++)
    {
        ll cur=(n/i);
        ll x=prev-cur;
        sum+=cur;
        cnt--;
        sum+=x*(i-1);
        cnt-=x;
        prev=cur;
    }

    if(cnt){
        sum+=cnt*(n/(sq+1));
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

