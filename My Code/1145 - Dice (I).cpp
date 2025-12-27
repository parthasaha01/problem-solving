#include<bits/stdc++.h>
using namespace std;
int dp[2][15005];
#define mod 100000007
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,k,s;
        scanf("%d%d%d",&n,&k,&s);

        memset(dp,0,sizeof(dp));

        dp[0][0]=1;
        for(int pos=1; pos<=n; pos++){
            for(int sum=1; sum<=s; sum++){
                dp[1][sum] = dp[1][sum-1]+dp[0][sum-1];
                if(sum-k-1>=0) dp[1][sum] -= dp[0][sum-k-1];
                if(dp[1][sum]<0)dp[1][sum] += mod;
                if(dp[1][sum]>=mod)dp[1][sum]-=mod;
            }

            for(int sum=0; sum<=s; sum++){
                dp[0][sum]=dp[1][sum];
            }
        }

        printf("Case %d: %d\n",ks, dp[1][s]);
    }
    return 0;
}
