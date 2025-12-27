#include<bits/stdc++.h>
using namespace std;
int n,r,k,dp[50][50][50][50];
int fun(int x,int y,int v,int p)
{
    if(x==2*n){
        if(y==0 && v==r) return 1;
        return 0;
    }

    if(v>r)return 0;

    if(dp[x][y][v][p]!=-1)return dp[x][y][v][p];

    int ret = 0;

    ret += fun(x+1,y+1,v,y);
    if(y>0){
        if(y==k && y>p) ret += fun(x+1,y-1,v+1,y);
        else ret += fun(x+1,y-1,v,y);
    }

    return dp[x][y][v][p] = ret;
}
int main()
{
    while(scanf("%d%d%d",&n,&r,&k)==3)
    {
        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0,0,0);
        //path(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}

