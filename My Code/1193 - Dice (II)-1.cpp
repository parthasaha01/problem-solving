#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007LL
ll dp[2][15005],sp[2][15005];
int main()
{
    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n,k,s;
        scanf("%lld%lld%lld",&n,&k,&s);

        memset(dp,0,sizeof(dp));
        memset(sp,0,sizeof(sp));

        dp[0][0]=1;
        for(ll sum=0; sum<=s; sum++)sp[0][sum]=1;

        for(ll pos=1; pos<=n; pos++)
        {
            for(ll sum=0; sum<pos; sum++)dp[1][sum]=0;

            for(ll sum=pos; sum<=s; sum++)
            {
                dp[1][sum] = dp[0][sum-1]+dp[1][sum-1];
                if(dp[1][sum]>=mod)dp[1][sum]-=mod;

                if(sum-2>=0)dp[1][sum] += sp[0][sum-2];
                if(dp[1][sum]>=mod)dp[1][sum]-=mod;

                if(sum-k-1>=0)
                {
                    dp[1][sum] -= sp[0][sum-k-1];
                    dp[1][sum] %= mod;
                    if(dp[1][sum]<0)dp[1][sum] += mod;

                    dp[1][sum] -= k*dp[0][sum-k-1];
                    dp[1][sum] %= mod;
                    if(dp[1][sum]<0)dp[1][sum] += mod;
                }

            }

            dp[0][0] = dp[1][0];
            sp[0][0] = dp[1][0];

            for(ll sum=1; sum<=s; sum++)
            {
                dp[0][sum]=dp[1][sum];
                sp[0][sum]=sp[0][sum-1]+dp[0][sum];

                if(dp[0][sum]>=mod)dp[0][sum]-=mod;
                if(sp[0][sum]>=mod)sp[0][sum]-=mod;
            }
        }

        printf("Case %d: %lld\n",ks, dp[1][s]);
    }
    return 0;
}

