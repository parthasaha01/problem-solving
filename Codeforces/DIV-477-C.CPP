#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll n,m,cs,ce,v;
ll aa[mx+5],bb[mx+5];
ll elevators(ll sx,ll sy,ll dx,ll dy)
{
    if(ce==0)return 100000000000000000LL;
    ll  cost1,cost2;

    ll lf=0;
    ll lo=1;
    ll hi=ce;
    ll x = sy;
    while(lo<=hi)
    {
        ll md = (lo+hi)/2;
        if(bb[md]<=x){
            lf = bb[md];
            lo = md+1;
            if(bb[md]==x)break;
        }
        else{
            hi = md-1;
        }
    }
    if(lf==0){
        cost1=100000000000000000LL;
    }
    else{
        cost1 = abs(sy-lf);
        ll cnt = abs(sx-dx);
        ll uu = cnt/v;
        if(cnt%v!=0)uu++;
        cost1 += uu;
        cost1 += abs(dy-lf);
    }

    ll rg=ce+1;
    lo=1;
    hi=ce;
    x = sy;
    while(lo<=hi)
    {
        ll md = (lo+hi)/2;
        if(bb[md]>=x){
            rg = bb[md];
            hi = md-1;
            if(bb[md]==x)break;
        }
        else{
            lo = md+1;
        }
    }
    if(rg==ce+1){
        cost2=100000000000000000LL;
    }
    else{
        cost2 = abs(sy-rg);
        ll cnt = abs(sx-dx);
        ll uu = cnt/v;
        if(cnt%v!=0)uu++;
        cost2 += uu;
        cost2 += abs(dy-rg);
    }

   // printf("cost1=%lld cost2=%lld\n",cost1,cost2);

    ll cost = min(cost1,cost2);
    return cost;
}
ll stairs(ll sx,ll sy,ll dx,ll dy)
{
    if(cs==0)return 100000000000000000LL;

    ll  cost1,cost2;

    ll lf=0;
    ll lo=1;
    ll hi=cs;
    ll x = sy;
    while(lo<=hi)
    {
        ll md = (lo+hi)/2;
        if(aa[md]<=x){
            lf = aa[md];
            lo = md+1;
            if(aa[md]==x)break;
        }
        else{
            hi = md-1;
        }
    }
    if(lf==0){
        cost1=100000000000000000LL;
    }
    else{
        cost1 = abs(sy-lf);
        cost1 += abs(sx-dx);
        cost1 += abs(dy-lf);
    }

    ll rg=cs+1;
    lo=1;
    hi=cs;
    x = sy;
    while(lo<=hi)
    {
        ll md = (lo+hi)/2;
        if(aa[md]>=x){
            rg = aa[md];
            hi = md-1;
            if(aa[md]==x)break;
        }
        else{
            lo = md+1;
        }
    }
    if(rg==cs+1){
        cost2=100000000000000000LL;
    }
    else{
        cost2 = abs(sy-rg);
        cost2 += abs(sx-dx);
        cost2 += abs(dy-rg);
    }

    ll cost = min(cost1,cost2);
    return cost;

}
int main()
{
    scanf("%I64d %I64d %I64d %I64d %I64d",&n,&m,&cs,&ce,&v);

    for(int i=1; i<=cs; i++){
        ll x; scanf("%I64d",&x);
        //a[x]=1;
        aa[i]=x;
    }

    for(int i=1; i<=ce; i++){
        ll x; scanf("%I64d",&x);
        //b[x]=1;
        bb[i]=x;
    }

    ll q; scanf("%I64d",&q);

    while(q--)
    {
        ll sx,sy,dx,dy;
        scanf("%I64d %I64d %I64d %I64d",&sx,&sy,&dx,&dy);

        if(sx==dx){
            if(sy>dy){
                swap(sy,dy);
            }
        }
        else{
            if(sx>dx){
                swap(sx,dx);
                swap(sy,dy);
            }
        }
        if(sx==dx){
            ll ans = abs(sx-dx)+abs(sy-dy);
            printf("%I64d\n",ans);
            continue;
        }

        ll minn = 100000000000000000LL;

        ll cost1 = elevators(sx,sy,dx,dy);
        ll cost2 = stairs(sx,sy,dx,dy);

        ll ans = minn;
        ans = min(ans,cost1);
        ans = min(ans,cost2);

        printf("%I64d\n",ans);
    }

    return 0;
}
