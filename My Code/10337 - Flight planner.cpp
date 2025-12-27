#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
int s,dp[12][1005],a[12][1005];
int fun(int i,int j)
{
    if(i<1 || i>10)return inf;
    if(j>s){
        if(i==10)return 0;
        return inf;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    int ret1 = 60-a[i][j]+fun(i-1,j+1);
    int ret2 = 30-a[i][j]+fun(i,j+1);
    int ret3 = 20-a[i][j]+fun(i+1,j+1);

    int ret = min(ret1,min(ret2,ret3));
    return dp[i][j]=ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int dd; scanf("%d",&dd);

        s = dd/100;

        for(int i=1; i<=10; i++)
        {
            for(int j=1; j<=s; j++){
                scanf("%d",&a[i][j]);
            }
        }

        memset(dp,-1,sizeof(dp));

        int ans = fun(10,1);

        printf("%d\n\n",ans);
    }
    return 0;
}
