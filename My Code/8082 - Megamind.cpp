#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll E,P,K,R;
ll possible(ll rn)
{
    ll lo = 1;
    ll hi = K;
    ll ans = -1;
    while(lo<=hi)
    {
        ll md = (lo+hi)/2;
        ll loss = (rn*K*P)+(md*P);
        ll gain = rn*R;
        ll present = E+gain-loss;
        //ll present = E + (md*p) + (rn*((K*P)-R));

        if(present<=0)
        {
            ans = (rn*K)+md;
            hi = md-1;
        }
        else
        {
            lo = md+1;
        }
    }

    return ans;
}
ll Binary_Search()
{
    ll lo=0;
    ll hi=100000000LL;
    ll ans = -1;

    while(lo<=hi)
    {
        ll md = (lo+hi)/2;

//        ll rn;
//        if(md%K==0)rn = md/K;
//        else rn = (md/K)+1;
//        rn--;
//
//        ll loss = md*P;
//        ll gain = rn*R;
//        ll present = E+gain-loss;

        //printf("lo=%lld hi=%lld md=%lld rn=%lld loss=%lld gain=%lld present=%lld ans=%lld\n",lo,hi,md,rn,loss,gain,present,ans);
        ll val = possible(md);
        if(val!=-1)
        {
            ans = val;
            hi=md-1;
        }
        else
        {
            lo = md+1;
        }
    }
    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%lld %lld %lld %lld",&E,&P,&K,&R);

        ll ans = Binary_Search();

        printf("Case %d: %lld\n",ks,ans);
    }
    return 0;
}
