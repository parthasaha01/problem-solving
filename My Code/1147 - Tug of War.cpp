#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[101],dp[101][100001],cnt1,cnt2;
bool wp[101][51],vs[101][51];
bool fun(int p, int k)
{
    if(k>m)return false;
    if(abs((p-1)-k)>m)return false;
    if(p==n+1)return true;

    if(vs[p][k]==true)return wp[p][k];

    bool ret1 = fun(p+1,k+1);
    bool ret2 = fun(p+1,k);
    vs[p][k]=true;
    return wp[p][k] = ret1|ret2;
}
int path(int p, int s, int k)
{
    if(p==n+1)return abs(2*s-sum);

    if(dp[p][s]!=-1)return dp[p][s];

    int ret1=10000000,ret2=10000000;
    bool flag1 = fun(p+1,k+1);
    bool flag2 = fun(p+1,k);

    if(flag1==true) ret1 = path(p+1,s+a[p],k+1);
    if(flag2==true) ret2 = path(p+1,s,k);

    int ret = min(ret1,ret2);
    return dp[p][s]=ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d",&n);

        sum=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }

        if(n&1)m=(n/2)+1;
        else m = n/2;

        memset(vs,false,sizeof(vs));
        int ff = fun(1,0);

        memset(dp,-1,sizeof(dp));
        int dd = path(1,0,0);

        int cnt1 = (sum-dd)/2;
        int cnt2 = cnt1+dd;

        printf("Case %d: %d %d\n",ks,cnt1,cnt2);
    }
    return 0;
}




