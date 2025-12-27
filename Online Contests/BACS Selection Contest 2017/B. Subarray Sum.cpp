#include<bits/stdc++.h>
using namespace std;
#define mx 5002
int n,k,a[mx],dp[mx][mx];
int maxx;
int fun(int p,int x)
{
    //if(x>k)return -1000000000;
    if(p==0){ return 0; }

    //if(dp[p][x]!=-1)return dp[p][x];

    int ret=0;

    if(a[p]>=0)
    {
        ret = a[p] + max(0,fun(p-1,x));
    }
    else
    {
        int ret1=-1000000000,ret2=-1000000000;
        ret1 = a[p] + max(0,fun(p-1,x));
        //int ret2 = max(0,fun(p-1,x+1));
        ret = max(ret1,ret2);
    }

    dp[p][x]=ret;
    //dp[p][x]=max(ret,0);
    //maxx = max(maxx,dp[p][x]);
    return dp[p][x];
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&k);

        int ng=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<0)ng++;
        }

        if(ng<=k)
        {
            int sum=0;

            for(int i=1; i<=n; i++)
            {
                if(a[i]>0)sum+=a[i];
            }

            printf("Case %d: %d\n",ks,sum);
            continue;
        }

        printf("partha\n");

        memset(dp,-1,sizeof(dp));
        maxx=-1000000000;
        int ans = fun(n,0);
        //printf("maxx=%d\n",maxx);
        printf("Case %d: %d\n",ks,ans);
        //printf("Case %d: %d\n",ks,maxx);
    }
    return 0;
}

/*
5 1
-100 2 -100 105 -200
*/
