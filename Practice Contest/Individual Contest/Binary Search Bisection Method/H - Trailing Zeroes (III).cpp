#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll trailingZero(ll v)
{
    ll cnt = 0;
    for(ll i=5; i<=v; i*=5) cnt += (v/i);
    return cnt;
}
ll fun(ll q)
{
    ll lo=0;
    ll hi=1000000000000;
    ll ans = -1;

    while(lo<=hi)
    {
        ll md = (lo+hi)/2;
        md-=(md%5);

        ll cnt = trailingZero(md);

        if(cnt==q){ans=md; break;}
        else if(cnt<q)lo=md+5;
        else hi=md-5;
    }

    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll q; scanf("%lld",&q);
        ll ans = fun(q);
        if(ans==-1)printf("Case %d: impossible\n",ks);
        else printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
