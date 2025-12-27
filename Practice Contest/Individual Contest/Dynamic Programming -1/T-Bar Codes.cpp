#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int n,k,mx;
LL dp[51][51][51];
LL BarCodes(int pos,int bar)
{
    if(pos==0&&bar==0) return 1;
    if(pos<=0||bar<=0) return 0;

    if(dp[pos][bar][mx]!=-1)
        return dp[pos][bar][mx];

    LL ret=0;

    for(int i=1;i<=mx&&i<=pos;i++)
        ret+=BarCodes(pos-i,bar-1);

    return dp[pos][bar][mx]=ret;
}
int main()
{
    int T;
    scanf("%d",&T);

    memset(dp,-1,sizeof(dp));

    for(int test=1;test<=T;test++)
    {
        scanf("%d %d %d",&n,&k,&mx);
        LL ans = BarCodes(n,k);
        printf("Case %d: %lld\n",test,ans);
    }

    return 0;
}
