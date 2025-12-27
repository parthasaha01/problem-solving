#include<bits/stdc++.h>
using namespace std;
int n,r,k,dp[50][50][50][50][2];
int fun(int x,int y,int v,int p)
{
    if(x==0){
        if(y==0 && v==0) return 1;
        return 0;
    }

    if(v<0)return 0;

    if(dp[x][y][v][k][p]!=-1)return dp[x][y][v][k][p];

    int ret = 0;

    ret += fun(x-1,y+1,v,1);
    if(y>0){
        if(y==k && p==1) ret += fun(x-1,y-1,v-1,0);
        else ret += fun(x-1,y-1,v,0);
    }

    return dp[x][y][v][k][p] = ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(scanf("%d%d%d",&n,&r,&k)==3)
    {
        int ans = fun(2*n,0,r,0);
        printf("%d\n",ans);
    }
    return 0;
}
