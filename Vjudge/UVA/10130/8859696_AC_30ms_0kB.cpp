#include<bits/stdc++.h>
using namespace std;
int n,g,dp[1005][35],P[1005],W[1005],MW[105];
int fun(int pos,int weight)
{
    if(pos>n)return 0;
    if(dp[pos][weight]!=-1)return dp[pos][weight];

    int ret1=0,ret2=0;

    if(weight-W[pos]>=0)
        ret1 = P[pos]+fun(pos+1,weight-W[pos]);
    ret2 = fun(pos+1,weight);

    return dp[pos][weight] = max(ret1,ret2);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&P[i],&W[i]);
        scanf("%d",&g);
        for(int i=1; i<=g; i++)
            scanf("%d",&MW[i]);

        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=1; i<=g; i++)
            ans += fun(1,MW[i]);

        printf("%d\n",ans);
    }
    return 0;
}
