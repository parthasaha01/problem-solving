#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int n,k;
int coin[51],C[51];
int dp[51][1001];
int CoinChange1(int pos,int amount)
{
    if(pos==n){
        if(amount==0) return 1;
        else return 0;
    }

    if(amount==0) return 1;

    if(dp[pos][amount]!=-1) return dp[pos][amount];

    int ret=0;

    for(int taken=1; taken<=C[pos]; taken++){
        if(amount-coin[pos]*taken>=0)
            ret+=CoinChange1(pos+1,amount-coin[pos]*taken)%mod;
    }

    ret+=CoinChange1(pos+1,amount)%mod;

    return dp[pos][amount]=ret%mod;

}
int main()
{
    int T;
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&coin[i]);
        for(int i=0;i<n;i++) scanf("%d",&C[i]);
        int res=CoinChange1(0,k);
        printf("Case %d: %d\n",test,res);
    }

    return 0;
}

