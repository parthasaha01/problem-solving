#include<bits/stdc++.h>
using namespace std;
int n,L,C;
int dp[1005][1005], wp[1005][1005],s[1005],t[1005];
int fun(int b,int e)
{
    if(b>e)return 0;
    if(dp[b][e]!=-1)return dp[b][e];
    int ret = 1000000000;

    for(int m=b; m<=e; m++)
    {
        int v = s[m]-s[b-1];
        if(v<=L){
            ret = min(ret,1+fun(m+1,e));
        }
        else break;
    }

    return dp[b][e] = ret;
}
int path(int b,int e)
{
    if(b>e)return 0;

    if(wp[b][e]!=-1)return wp[b][e];

    int ans = fun(b,e);
    int mn = 1000000000;

    for(int m=b; m<=e; m++)
    {
        int v = s[m]-s[b-1];

        if(v<=L)
        {
            int ret = 1+fun(m+1,e);
            if(ret==ans){
                int ds;
                if(v==L)ds = 0;
                else if(L-v<=10)ds = -C;
                else ds = (L-v-10)*(L-v-10);

                mn = min(mn,ds+path(m+1,e));
            }
        }
        else break;
    }

    return wp[b][e] = mn;
}
int main()
{
    int ks=0;
    while(scanf("%d",&n) && n)
    {
        if(ks)printf("\n");

        scanf("%d%d",&L,&C);

        for(int i=1; i<=n; i++)scanf("%d",&t[i]);
        for(int i=1; i<=n; i++)s[i]=s[i-1]+t[i];

        memset(dp,-1,sizeof(dp));
        int mn = fun(1,n);

        memset(wp,-1,sizeof(wp));
        int cs = path(1,n);

        printf("Case %d:\n",++ks);
        printf("Minimum number of lectures: %d\n",mn);
        printf("Total dissatisfaction index: %d\n",cs);
    }
    return 0;
}
