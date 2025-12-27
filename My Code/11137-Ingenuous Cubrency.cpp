#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll dp[25][10005];
int C[25];
ll fun(int pos,int need)
{
    if(pos==21){
        if(need==0)return 1;
        else return 0;
    }

    if(dp[pos][need]!=-1)return dp[pos][need];

    ll ret1=0,ret2=0;
    if(need-C[pos]>=0) ret1 += fun(pos,need-C[pos]);

    ret2 += fun(pos+1,need);

    return dp[pos][need] = ret1+ret2;
}
int main()
{
    for(int i=0; i<21; i++)
        C[i] = (i+1)*(i+1)*(i+1);

    memset(dp,-1,sizeof(dp));

    while(scanf("%d",&n)==1)
    {
        ll ans = fun(0,n);
        printf("%lld\n",ans);
    }
    return 0;
}

