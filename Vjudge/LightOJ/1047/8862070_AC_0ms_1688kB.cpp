#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int n,dp[25][5],wt[25][5];
int fun(int pos,int pr) // pr means previous color
{
    if(pos==n+1) return 0;
    if(dp[pos][pr] != -1) return dp[pos][pr];
    int ret = inf;

    for(int i=1; i<=3; i++){
        if(i!=pr){
            ret = min(ret,wt[pos][i]+fun(pos+1,i));
        }
    }
    return dp[pos][pr] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=3; j++)
                scanf("%d",&wt[i][j]);

        memset(dp,-1,sizeof(dp));
        int ans = fun(1,0);
        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}