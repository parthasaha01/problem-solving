#include<bits/stdc++.h>
using namespace std;
int c,n,a[25][25],dp[25][205],sz[25];
int fun(int p,int x)
{
    if(p==n+1)return 0;
    if(dp[p][x]!=-1)return dp[p][x];

    int ret = 0;
    for(int j=1; j<=sz[p]; j++){
        int ret1=0;
        if(x+a[p][j]<=c)ret1=a[p][j]+fun(p+1,x+a[p][j]);
        ret = max(ret,ret1);
    }
    return dp[p][x] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&c,&n);

        for(int i=1; i<=n; i++){
            scanf("%d",&sz[i]);
            for(int j=1; j<=sz[i]; j++){
                scanf("%d",&a[i][j]);
            }
        }

        int s = 0;
        for(int i=1; i<=n; i++){
            int mn=10000000;
            for(int j=1; j<=sz[i]; j++){
                mn = min(mn,a[i][j]);
            }
            s += mn;
        }

        if(s>c){
            printf("no solution\n");
            continue;
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
