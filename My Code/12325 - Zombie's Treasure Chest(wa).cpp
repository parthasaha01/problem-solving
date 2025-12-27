#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,s1,v1,s2,v2;
//ll wrong()
//{
//    double dn,ds1,dv1,ds2,dv2;
//    dn  =  n;
//    ds1 = s1; dv1 = v1;
//    ds2 = s2; dv2 = v2;
//
//    double ret1=0.0,ret2=0.0;
//
//    ret1 = dv1/ds1;
//    ret2 = dv2/ds2;
//    ll ans = 0;
//    // cout << ret1 << " " << ret2 << endl;
//    if(ret1>ret2)
//    {
//        ll sum1=0,sum2=0;
//        ll w = n;
//        sum1 = (w/s1)*v1;
//        w -= (w/s1)*s1;
//        sum1 += (w/s2)*v2;
//
//        if((n/s1)>0)
//        {
//            w = n;
//            sum2 = ((w/s1)-1)*v1;
//            w -= ((w/s1)-1)*s1;
//            sum2 += (w/s2)*v2;
//        }
//
//        ans = max(sum1,sum2);
//    }
//    else
//    {
//        ll sum1=0,sum2=0;
//        ll w = n;
//        sum1 = (w/s2)*v2;
//        w -= (w/s2)*s2;
//        sum1 += (w/s1)*v1;
//
//        if((n/s2)>0)
//        {
//            w = n;
//            sum2 = ((w/s2)-1)*v2;
//            w -= ((w/s2)-1)*s2;
//            sum2 += (w/s1)*v1;
//        }
//        ans = max(sum1,sum2);
//    }
//}
//ll fun(ll cnt)
//{
//    ll sum = 0;
//    ll w = n;
//    sum += (cnt*v1);
//    w -= (cnt*s1);
//    sum += (w/s2)*v2;
//    return sum;
//}
//ll solve()
//{
//    ll lft = 0;
//    ll rgt = (n/s1);
//    ll ddd = 0;
//    for(ll i=lft; i<=rgt; i++){
//        ll val = fun(i);
//        printf("i=%lld val=%lld\n",i,val);
//    }
//    ll ans = 0;
//
//    while(lft<=rgt)
//    {
//        if(abs(rgt-lft)<=2){
//            for(int i=lft; i<=rgt; i++){
//                ll val = fun(i);
//                ans = max(ans,val);
//            }
//            break;
//        }
//
//        ll leftThird = lft + (rgt - lft)/3;
//        ll rightThird = rgt - (rgt - lft)/3;
//
//        ll fleft  = fun(leftThird);
//        ll fright = fun(rightThird);
//        ans = max(ans,max(fleft,fright));
//
//        printf("lft=%lld rgt=%lld\n",lft,rgt);
//        printf("leftThird=%lld rightThird=%lld\n",leftThird,rightThird);
//        printf("fleft=%lld fright=%lld ans=%lld\n",fleft,fright,ans);
//        getchar();
//
//        if(fleft<=fright)lft = leftThird;
//        else rgt = rightThird;
//    }
//    return ans;
//}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%lld %lld %lld %lld %lld",&n,&s1,&v1,&s2,&v2);

        //ll ans = wrong();
        ll ans = solve();

        printf("Case #%d: %lld\n",ks,ans);
    }
    return 0;
}

