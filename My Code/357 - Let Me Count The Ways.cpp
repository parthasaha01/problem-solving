#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[7][30005];
int a[] = {1,5,10,25,50};
ll fun(int p, int v)
{
    if(v==0)return 1;
    if(p>4)return 0;

    if(dp[p][v]!=-1)return dp[p][v];

    ll ret1=0, ret2=0;
    if(v-a[p]>=0)ret1 += fun(p,v-a[p]);
    ret2 += fun(p+1,v);

    return dp[p][v] = ret1+ret2;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    while(scanf("%d",&n)==1)
    {
        ll ans = fun(0,n);

        if(ans==1) printf("There is only %lld way to produce %d cents change.\n",ans,n);
        else printf("There are %lld ways to produce %d cents change.\n",ans,n);
    }
    return 0;
}
