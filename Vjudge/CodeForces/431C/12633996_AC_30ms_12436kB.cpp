#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
#define ll long long
int m,d,k;
ll dp[110][110][110];
ll fun(int n,int state,int len)
{
    if(n>m)
        return 0;
    if(n==m)
    {
        if(state==1)
            return 1LL;
        else
            return 0LL;
    }
    if(dp[n][state][len]!=-1)
    {
        return dp[n][state][len];
    }

    ll sum=0;
    for(int i=1; i<=k; i++)
    {
        int nstate = state;
        if(i>=d) nstate=1;
        if((n+i)<=m){
            sum +=(fun(n+i,nstate,len+1))%MOD;
            sum %= MOD;
        }
    }
    return dp[n][state][len]=sum;
}

int main()
{
    scanf("%d%d%d",&m,&k,&d);
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",fun(0,0,0));
    return 0;
}

