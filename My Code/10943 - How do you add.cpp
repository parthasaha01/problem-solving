#include<bits/stdc++.h>
using namespace std;
#define mod 1000000
int n,k,dp[105][105];
int fun(int pos,int sum)
{
    if(pos==k){
        if(sum==n)return 1;
        else return 0;
    }
    if(sum>n)return 0;

    if(dp[pos][sum]!=-1)return dp[pos][sum]%mod;

    int ret = 0;
    for(int i=0; i<=n; i++){
        ret = ((ret%mod)+fun(pos+1,sum+i)%mod)%mod;
    }
    return dp[pos][sum]=ret%mod;
}
int main()
{
    while(scanf("%d%d",&n,&k))
    {
        if(n==0&&k==0)break;

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0);

        printf("%d\n",ans);
    }
    return 0;
}
