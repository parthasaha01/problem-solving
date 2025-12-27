#include<bits/stdc++.h>
using namespace std;
#define mod 100000000
int n1,n2,k1,k2,dp[101][101][11][11];

int fun(int p1,int p2,int q1,int q2)
{
    if(p1==n1 && p2==n2)return 1;
    if(p1>n1 || p2>n2)return 0;

    if(dp[p1][p2][q1][q2]!=-1)return dp[p1][p2][q1][q2];

    int ret1=0,ret2=0;
    if(q1<k1)ret1 = fun(p1+1,p2,q1+1,0)%mod;
    if(q2<k2)ret2 = fun(p1,p2+1,0,q2+1)%mod;

    return dp[p1][p2][q1][q2]=(ret1+ret2)%mod;
}
int main()
{
    while(scanf("%d%d%d%d",&n1,&n2,&k1,&k2)==4)
    {
        memset(dp,-1,sizeof(dp));

        int ans = fun(0,0,0,0);

        printf("%d\n",ans);
    }

    return 0;
}
