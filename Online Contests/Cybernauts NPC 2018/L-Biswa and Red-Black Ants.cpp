#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007LL
ll red[100005];
ll bigmod(ll b,ll p,ll m)
{
    ll res = 1%m, x = b%m;
    while(p)
    {
        if(p&1)res = (res*x)%m;
        x = (x*x)%m;
        p >>= 1LL;
    }
    return res;
}

int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll N,K,B;
        scanf("%lld %lld",&N,&K);
        for(int i=1; i<=K; i++) scanf("%d",&red[i]);
        scanf("%d",&B);
        ll ans = (bigmod(K,K,MOD)*bigmod(N-K,N-K,MOD))%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
