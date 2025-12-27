#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,t,p;
ll dp[75][75];
ll fun(int x,int y)
{
    if(x==n+1){
        if(y==t)return 1;
        return 0;
    }

    if(dp[x][y]!=-1)return dp[x][y];

    ll ret=0;
    for(int i=p; y+i<=t; i++){
        ret += fun(x+1,y+i);
    }

    return dp[x][y]=ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d%d",&n,&t,&p);

        memset(dp,-1,sizeof(dp));
        ll ans = fun(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}
