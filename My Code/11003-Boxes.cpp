#include<bits/stdc++.h>
using namespace std;
int n,w[1005],c[1005],dp[1005][6005];
int fun(int p,int x)
{
    if(p==n+1)return 0;

    if(dp[p][x]!=-1)return dp[p][x];

    int ret1=0,ret2=0;

    if(w[p]<=x) ret1 = 1+fun(p+1,min(x-w[p],c[p]));
    ret2 = fun(p+1,x);

    return dp[p][x] = max(ret1,ret2);
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        for(int i=1; i<=n; i++){
            scanf("%d%d",&w[i],&c[i]);
        }

        w[0]=0; c[0]=6005;

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,c[0]);

        printf("%d\n",ans-1);

    }
    return 0;
}
