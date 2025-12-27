#include<bits/stdc++.h>
using namespace std;
int mm,m,n,a[101],s[101],dp[101][10205],flag,wp[101][10205];
int way(int p,int v)
{
    if(p==n+1)
    {
        if(v>2000)return 1;
        return 0;
    }

    if(wp[p][v]!=-1)return wp[p][v];

    int f=0,ff=0;

    if(v+a[p]<=mm)f  = way(p+1,v+a[p]);
    ff = way(p+1,v);

    return wp[p][v] = (f | ff);
}
int fun(int p,int v)
{
    if(p==n+1)return 0;

    if(dp[p][v]!=-1)return dp[p][v];

    int ret1=0,ret2=0,ret=0;

    int f=0,ff=0;

    if(v+a[p]<=m) f=way(p+1,v+a[p]);
    ff = way(p+1,v);

    if(f==1)ret1 = s[p]+fun(p+1,v+a[p]);
    if(ff==1)ret2 = fun(p+1,v);

    ret = max(ret1,ret2);

    return dp[p][v]=ret;
}
int fn(int p,int v)
{
    if(p==n+1)return 0;

    if(dp[p][v]!=-1)return dp[p][v];

    int ret1=0,ret2=0,ret=0;

    if(v+a[p]<=m)ret1 = s[p]+fn(p+1,v+a[p]);
    ret2 = fn(p+1,v);

    ret = max(ret1,ret2);

    return dp[p][v]=ret;
}
int main()
{
    while(scanf("%d%d",&m,&n)==2)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&a[i],&s[i]);
        }

        mm = m+200;
        memset(wp,-1,sizeof(wp));
        int ww = way(1,0);

        if(ww==1 && m>1800)
        {
            m=mm;
            memset(dp,-1,sizeof(dp));
            int ans1 = fun(1,0);
            m=m-200;
            memset(dp,-1,sizeof(dp));
            int ans2 = fn(1,0);
            int ans = max(ans1,ans2);
            printf("%d\n",ans);
        }
        else
        {
            memset(dp,-1,sizeof(dp));
            int ans = fn(1,0);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
1900 3
2000 5
1950 2
101 1

10000 5
101 5
102 5
103 5
104 5
10000 5
*/

