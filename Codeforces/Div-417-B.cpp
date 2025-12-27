#include<bits/stdc++.h>
using namespace std;
string s[25];
int nn,n,m,a[25][110],dp[25][5],lfft[25],rggt[25];
int fun(int p, int k) // k=0 means lfft && k=1 for rggt
{
    if(p==nn)
    {
        if(k==0)return lfft[p];
        else return rggt[p];
    }

    if(dp[p][k] != -1)return dp[p][k];

    int ret = 1000000000;

    if(k==0)
    {
        int q1 = lfft[p] + 1 + fun(p-1,0);
        int q2 = (m+1)-lfft[p]+1 + fun(p-1,1);
        ret = lfft[p] + min(q1,q2);
    }
    else
    {
        int q1 = (m+1)-rggt[p] + 1 + fun(p-1,0);
        int q2 = rggt[p] + 1 + fun(p-1,1);
        ret = rggt[p] + min(q1,q2);
    }

    dp[p][k] = ret;

    return ret;
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++)cin>>s[i];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            a[i][j] = s[i][j]-'0';
        }
    }

    for(int i=1; i<=n; i++)
    {
        rggt[i]=0;
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==1)
            {
                rggt[i]=(m-j)+1;
                break;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        lfft[i]=0;
        for(int j=m; j>=1; j--)
        {
            if(a[i][j]==1)
            {
                lfft[i]=j;
                break;
            }
        }
    }

    nn=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==1)
            {
                nn = i;
                goto label;
            }
        }
    }

    label:

    if(nn==0){
        printf("0\n");
        return 0;
    }

    memset(dp,-1,sizeof(dp));

    int ans = fun(n,0);

    printf("%d\n",ans);

    return 0;
}
