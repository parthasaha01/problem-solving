#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
ll BIGMOD(ll b,ll p)
{
    ll res = 1%MOD, x = b%MOD;
    while(p)
    {
        if(p&1) res = (res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1LL;
    }
    return res;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n,a,b,l;
        scanf("%lld %lld %lld %lld",&n,&a,&b,&l);

        ll ba = b-a;
        ll lb = l-b;
        ll vv = ((ba%MOD) * (lb%MOD))%MOD;

        ll lb1 = lb-1;

        if(lb&1)lb1/=2;
        else lb/=2;

        ll sum = ((lb%MOD)*(lb1%MOD))%MOD;
        sum = (vv+sum)%MOD;

        ll ret = BIGMOD(n-1,l-3);
        ll way = ((sum%MOD) * (ret%MOD))%MOD;

        printf("Case %d: %lld\n",ks,way);
    }
    return 0;
}
