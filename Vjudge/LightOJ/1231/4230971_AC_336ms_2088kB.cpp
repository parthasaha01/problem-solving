#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int n,k;
int coin[51],C[51];
long int dp[51][1001];
long int CoinChange1(int i,int amount)
{
    if(i>=n){
        if(amount==0) return 1;
        else return 0;
    }

    if(amount==0) return 1;
    //if(amount>k) return 0;

    if(dp[i][amount]!=-1)
        return dp[i][amount];

    long int ret=0;

    for(int taken=1; taken<=C[i]; taken++){
        if(amount-coin[i]*taken>=0)
            ret+=CoinChange1(i+1,amount-coin[i]*taken)%mod;
    }
    ret+=CoinChange1(i+1,amount)%mod;

    return dp[i][amount]=ret%mod;

}
int main()
{
    int T;
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&C[i]);
        long int res=CoinChange1(0,k);
        printf("Case %d: %ld\n",test,res);
    }

    return 0;
}
