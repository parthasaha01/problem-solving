#include<bits/stdc++.h>
using namespace std;
int n,dp[16][1<<16],a[16][16];
int check(int mask,int j){
    return mask & (1<<j);
}
int seton(int mask, int j){
    return mask | (1<<j);
}
int fun(int pos,int mask)
{
    if(pos==n)return 0;

    if(dp[pos][mask]!=-1)return dp[pos][mask];

    int ret=0,ret1=0;
    for(int j=0; j<n; j++)
    {
        ret1=0;
        if(!check(mask,j)){
            ret1 = a[pos][j] + fun(pos+1,seton(mask,j));
        }
        ret = max(ret,ret1);
    }

    return dp[pos][mask]=ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d",&a[i][j]);
            }
        }

        memset(dp,-1,sizeof(dp));

        int ans = fun(0,0);

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
