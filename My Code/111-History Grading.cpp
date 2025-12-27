#include<bits/stdc++.h>
using namespace std;
int a[25],b[25],n,x,dp[25][25];
int fun(int i,int j)
{
    if(i==n+1 || j==n+1)return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ret=0;
    if(a[i]==b[j]) ret = 1+fun(i+1,j+1);
    else ret = max(fun(i+1,j), fun(i,j+1));

    return dp[i][j] = ret;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&x);
            a[x]=i;
        }

        while(scanf("%d",&x)==1)
        {
            b[x]=1;
            for(int i=2; i<=n; i++){
                scanf("%d",&x);
                b[x]=i;
            }

            memset(dp,-1,sizeof(dp));
            int ans = fun(1,1);
            printf("%d\n",ans);
        }
    }
    return 0;
}

