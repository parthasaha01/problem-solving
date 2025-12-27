#include<bits/stdc++.h>
using namespace std;
int n,k,m;
long long int dp[55][55][55];
long long int BarCodes(int pos,int bar,int prev,int Max,long long int sum)
{
    if(dp[pos][bar][Max]!=-1)
    {
        return dp[pos][bar][Max];
    }
    if(bar>k || Max>m){
        return sum;
    }
    if(pos==n)
    {
        if(bar==k)
            return sum+1;
        else
            return sum;
    }

    long long int ret=0;

    for(int i=0; i<=1; i++)
    {
        if(i==prev)
        {
            ret+=BarCodes(pos+1,bar,i,Max+1,sum);
        }
        else
        {
            ret+=BarCodes(pos+1,bar+1,i,1,sum);
        }
    }

    return dp[pos][bar][Max]=ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1; test<=T; test++)
    {
        scanf("%d %d %d",&n,&k,&m);
        memset(dp,-1,sizeof(dp));
        long long int result = BarCodes(1,1,1,1,0);
        printf("Case %d: %lld\n",test,result);
    }

    return 0;
}
