#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],dp[105][105];
int fun(int i,int j)
{
    if(i>n || j>m)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int ret,ret1,ret2;

    if(a[i]==b[j])ret = 1+fun(i+1,j+1);
    else{
        ret1 = fun(i+1,j);
        ret2 = fun(i,j+1);
        ret = max(ret1,ret2);
    }
    return dp[i][j]=ret;
}
int main()
{
    int ks=0;

    while(scanf("%d%d",&n,&m))
    {
        if(!n&&!m)break;

        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        for(int i=1; i<=m; i++)scanf("%d",&b[i]);

        memset(dp,-1,sizeof(dp));
        int ans = fun(1,1);

        printf("Twin Towers #%d\n",++ks);
        printf("Number of Tiles : %d\n\n",ans);
    }
    return 0;
}
