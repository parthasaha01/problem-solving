#include<bits/stdc++.h>
using namespace std;
#define mod 10000007
long int dp[10005];
long int a,b,c,d,e,f;
long int fn(long int n)
{
    if(dp[n]!=-1)
        return dp[n];

    if(n==0) return a;
    if(n==1) return b;
    if(n==2) return c;
    if(n==3) return d;
    if(n==4) return e;
    if(n==5) return f;

    return dp[n] = (fn(n-1)+fn(n-2)+fn(n-3)+fn(n-4)+fn(n-5)+fn(n-6))%mod;
}
int main()
{
    long int T,N,res;
    scanf("%ld",&T);

    for(int test=1; test<=T; test++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%ld %ld %ld %ld %ld %ld %ld",&a,&b,&c,&d,&e,&f,&N);
        res=fn(N)%mod;
        printf("Case %ld: %ld\n",test,res);
    }

    return 0;
}
