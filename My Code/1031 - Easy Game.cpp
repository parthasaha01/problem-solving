#include<bits/stdc++.h>
using namespace std;
int n,a[101],sum[101],dp[101][101],vs[101][101];
int fun(int i,int j)
{
    if(i>j)return 0;
    if(vs[i][j]==1)return dp[i][j];
    vs[i][j]=1;

    int ret = -1000000000;
    for(int k=i; k<=j; k++){
        ret = max(ret, (sum[k]-sum[i-1]) - fun(k+1,j));
        ret = max(ret, (sum[j]-sum[k-1]) - fun(i,k-1));
    }
    return dp[i][j]=ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
        memset(vs,0,sizeof(vs));
        int ans = fun(1,n);
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
