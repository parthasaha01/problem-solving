#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Find(ll x)
{
    if(x==1)return 1LL;
    ll v = 1;
    while(v<=x){
        v=(v<<1LL);
    }
    v >>= 1LL;
    return v;
}
ll solve(ll X, ll L, ll N)
{
    ll cnt = 0;
    if(X>L)cnt+=(X-L);
    if(X%2==0)return cnt;

    ll pp = Find(X);
    //printf("pp=%lld\n",pp);
    ll cur = pp+(X/2LL);
   // printf("cur=%lld\n",cur);
    //printf("cnt=%lld\n",cnt);
    //if(cur>N)return cnt;
    ll vv = pp;
    while(cur<=N)
    {
        if(cur>=L)cnt++;
        //printf("cnt=%lld vv=%lld cur=%lld\n",cnt,vv,cur);
        cur += vv;
        vv=(vv<<1LL);
    }

    return cnt;
}
int main()
{
    ll tt; scanf("%lld",&tt);

    for(ll ks=1; ks<=tt; ks++)
    {
        ll X,L,N; scanf("%lld%lld%lld",&X,&L,&N);
        ll cnt = solve(X,L,N);
        ll tot = N-L+1;
        ll gcd = __gcd(cnt,tot);
        ll lob = cnt/gcd;
        ll hor = tot/gcd;
        printf("Case %lld: %lld/%lld\n",ks,lob,hor);
    }
    return 0;
}
