#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int dp[1002][15005];
int n,k,s;

int fun(int pos,int sum)
{
    if(sum<0)return 0;
    if(pos==0){
        if(sum==0)return 1;
        return 0;
    }

    if(dp[pos][sum]!=-1)return dp[pos][sum];

    int ret=0;
    ret = fun(pos,sum-1) + fun(pos-1,sum-1) - fun(pos-1,sum-k-1);

    if(ret<0)ret += mod;
    if(ret>=mod)ret -= mod;
    return dp[pos][sum] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d%d",&n,&k,&s);

        memset(dp,-1,sizeof(dp));

        int ans = fun(n,s);

        printf("Case %d: %d\n",ks, ans);
    }
    return 0;
}

