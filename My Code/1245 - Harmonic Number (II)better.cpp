#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll calculate(ll n)
{
    ll sq=sqrt(n);
    ll sum=0;

    for(ll i=1; i<=sq; i++){
        sum+=(n/i);
    }

    sum=(2*sum)-(sq*sq);

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

