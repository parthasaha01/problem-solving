#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        //ll rhs = 5*n;
        //ll ans = 0;
//
//        ll cn=0;
//
//        for(ll i=0; i<=1000; i++)
//        {
//            ll rhs = 5*i*i;
//            printf("i=%d\n",i);
//            ll ans = 0;
//            for(ll a=-1001; a<=1001; a++)
//            {
//                for(ll b=-1001; b<=1001; b++)
//                {
//                    ll v = (36*a*a) + (18*b*b);
//                    ll pp = rhs-v;
//
//                    if(pp<0)continue;
//                    if((pp%6)!=0)continue;
//
//                    ll qq = pp/6;
//                    ll sq = sqrt(qq);
//
//                    if(qq!=(sq*sq))continue;
//
//                    ans++;
//                    if(qq!=0)
//                    {
//                        ans++;
//                    }
//                }
//            }
//
//            if(ans!=0)cn++;
//
//        }
//
//        printf("%lld\n",ans);
    }

    return 0;
}

