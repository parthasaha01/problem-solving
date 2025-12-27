#include<bits/stdc++.h>
using namespace std;
int n,dp[1005],sum[1005];
struct dt{
    int V,K,C,L;
}a[1005];
bool cmp(dt x,dt y){
    return x.V<y.V;
}
int fun(int pos)
{
    if(pos==n+1)return 0;
    if(dp[pos]!=-1)return dp[pos];

    int ret = 1000000000;
    for(int i=pos; i<=n; i++){
        int cost = a[i].K + ((sum[i]-sum[pos-1])*a[i].C);
        ret = min(ret,cost+fun(i+1));
    }
    return dp[pos] = ret;
}
int main()
{
    while(scanf("%d",&n))
    {
        if(n==0)break;

        for(int i=1; i<=n; i++){
            scanf("%d%d%d%d",&a[i].V,&a[i].K,&a[i].C,&a[i].L);
        }

        sort(a+1,a+n+1,cmp);

        sum[0]=0;
        for(int i=1; i<=n; i++){
            sum[i] = sum[i-1]+a[i].L;
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(1);
        printf("%d\n",ans);
    }
    return 0;
}
