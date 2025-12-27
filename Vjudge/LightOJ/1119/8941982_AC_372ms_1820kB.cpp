#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int n,dp[1<<15],a[25][25];
int check(int mask,int pos){
    return mask & (1<<pos);
}
int seton(int mask,int pos){
    return mask | (1<<pos);
}
int fun(int mask)
{
    if(mask==(1<<n)-1)return 0;

    if(dp[mask]!=-1)return dp[mask];

    int ret1=inf,ret=inf;
    for(int i=0; i<n; i++)
    {
        if(!check(mask,i))
        {
            int sum=a[i][i];
            for(int j=0; j<n; j++){
                if(i==j)continue;
                if(check(mask,j))sum+=a[i][j];
            }
            ret1 = sum + fun(seton(mask,i));
        }
        ret = min(ret,ret1);
    }
    return dp[mask]=ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);

        memset(dp,-1,sizeof(dp));
        int ans = fun(0);
        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}