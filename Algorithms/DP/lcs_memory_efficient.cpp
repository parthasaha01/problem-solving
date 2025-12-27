#include<bits/stdc++.h>
using namespace std;
int lb,la;
int dp[2][62505], a[62505], b[62505];
int lcs(int i, int j)
{
    memset(dp,0,sizeof(dp));

    for(int i=1; i<=la; i++)
    {
        for(int j=1; j<=lb; j++)
        {
            if(a[i]==b[j])dp[1][j]=1+dp[0][j-1];
            else dp[1][j] = max(dp[0][j],dp[1][j-1]);
        }
        for(int k=0; k<=lb; k++)dp[0][k]=dp[1][k];
    }
    return dp[1][lb];
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&la,&lb);

        for(int i=1; i<=la; i++)scanf("%d",&a[i]);
        for(int i=1; i<=lb; i++)scanf("%d",&b[i]);

        int ans = lcs(1,1);
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}
