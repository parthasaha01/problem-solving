#include<bits/stdc++.h>
using namespace std;
int n,dp[10][10000];
int C[]={50,25,10,5,1};
int fun(int pos,int need)
{
    if(pos==5){
        if(need==0)return 1;
        else return 0;
    }

    if(dp[pos][need]!=-1)return dp[pos][need];

    int ret1=0,ret2=0;
    if(need-C[pos]>=0) ret1 += fun(pos,need-C[pos]);

    ret2 += fun(pos+1,need);

    return dp[pos][need] = ret1+ret2;
}
int main()
{
    memset(dp,-1,sizeof(dp));

    while(scanf("%d",&n)==1)
    {
        int ans = fun(0,n);
        printf("%d\n",ans);
    }
    return 0;
}
