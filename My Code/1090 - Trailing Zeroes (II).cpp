#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll factorial(ll n, ll b)
{
    ll cnt=0;
    for(ll i=b; n/i>=1; i=i*b){
        cnt+=(n/i);
    }
    return cnt;
}
ll power(ll n,ll p)
{
    ll cnt=0;
    while(n%p==0){
        ++cnt;
        n=n/p;
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n,r,p,q;
        scanf("%lld%lld%lld%lld",&n,&r,&p,&q);

        ll x1,x2,x3,x4,x5,x6,x7,x8;
        x1=factorial(n,2);
        x2=factorial(n,5);
        x3=power(p,2)*q;
        x4=power(p,5)*q;
        x5=factorial(r,2);
        x6=factorial(r,5);
        x7=factorial(n-r,2);
        x8=factorial(n-r,5);

        ll ans=min(((x1+x3)-(x5+x7)),((x2+x4)-(x6+x8)));
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
