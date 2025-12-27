#include<bits/stdc++.h>
using namespace std;
int n,total;
int w[25];
int fun(int pos,int sum)
{
    if(pos==n+1) return abs(2*sum-total);;

    //if(dp[pos][sum]!=-1)return dp[pos][sum];

    int ret1 = 0,ret2 = 0;

    ret1 = fun(pos+1,sum+w[pos]);
    ret2 = fun(pos+1,sum);

    return min(ret1,ret2);
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        total = 0;
        for(int i=1; i<=n; i++){
            scanf("%d",&w[i]);
            total+= w[i];
        }

        //memset(dp,-1,sizeof(dp));
        int ans = fun(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
