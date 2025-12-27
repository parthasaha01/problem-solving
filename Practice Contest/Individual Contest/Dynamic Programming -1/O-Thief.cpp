#include<bits/stdc++.h>
using namespace std;
int n,cap;
int dp[105][10005];
int cost[105],need[105],weight[105];
int knapsack(int i, int w)
{
    if(i==n+1)
        return 0;

    if(dp[i][w]!=-1)
        return dp[i][w];

    int profit1=0,profit2=0;

    if(w+weight[i]<=cap)
        profit1=cost[i]+knapsack(i,w+weight[i]);
    else
        profit1=0;

    profit2=knapsack(i+1,w);

    return dp[i][w]=max(profit1,profit2);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1; test<=T; test++)
    {
        scanf("%d %d",&n,&cap);
        int TW=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d",&cost[i],&need[i],&weight[i]);
            TW+=(need[i]*weight[i]);
        }

        if(TW>cap)
        {
            printf("Case %d: Impossible\n",test);
        }
        else
        {
            cap=cap-TW;
            memset(dp,-1,sizeof(dp));
            int MaxProfit=knapsack(1,0);
            printf("Case %d: %d\n",test,MaxProfit);
        }
    }

    return 0;
}
