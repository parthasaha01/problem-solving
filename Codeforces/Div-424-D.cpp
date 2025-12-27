#include<bits/stdc++.h>
using namespace std;
#define inf 2000000100
int n,k,v;
int a[1005],b[2005],c[1005][2005],dp[1005][2005];
int fun(int i,int j)
{
    if(i>n)return 0;
    if(j>k)return inf;

    if(dp[i][j] != -1)return dp[i][j];

    int ret1 = max(c[i][j],fun(i+1,j+1));
    int ret2 = fun(i,j+1);

    return dp[i][j] = min(ret1,ret2);
}
int main()
{
    scanf("%d%d%d",&n,&k,&v);

    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    for(int i=1; i<=k; i++)scanf("%d",&b[i]);

    sort(a+1,a+n+1);
    sort(b+1,b+k+1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            c[i][j] = abs(a[i]-b[j])+abs(b[j]-v);
        }
    }

    memset(dp,-1,sizeof(dp));

    int ans = fun(1,1);

    printf("%d\n",ans);

    return 0;
}
