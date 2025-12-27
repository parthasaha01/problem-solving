#include<bits/stdc++.h>
using namespace std;
int a[55];
int dp[55][55];
int mcm(int b, int e)
{
    if(b+1==e)
        return 0;

    if(dp[b][e]!=-1){
        return dp[b][e];
    }

    int minn=100005;

    for(int i=b+1; i<e; i++){
        int cost = mcm(b,i) + mcm(i,e) + (a[e]-a[b]);
        minn = min(minn,cost);
    }

    return dp[b][e]=minn;
}
int main()
{
    int L;

    while(scanf("%d",&L) && L)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        a[0]=0;
        a[n+1]=L;

        memset(dp,-1,sizeof(dp));

        int minn=mcm(0,n+1);

        printf("The minimum cutting is %d.\n",minn);
    }

    return 0;
}
