#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[101], wp[101][51],dp[101][45001],cnt1,cnt2;
int fun(int p, int k)
{
    if(k>m)return 0;
    if(abs((p-1)-k)>m)return 0;
    if(p==n+1)return 1;

    if(wp[p][k]!=-1)return wp[p][k];

    int ret1 = fun(p+1,k+1);
    int ret2 = fun(p+1,k);
    int ret  = ret1|ret2;
    return wp[p][k] = ret;
}
int path(int p, int s, int k)
{
    if(p==n+1)return abs(2*s-sum);

    if(dp[p][s]!=-1)return dp[p][s];

    int ret1=1000000,ret2=1000000;
    int flag1 = fun(p+1,k+1);
    int flag2 = fun(p+1,k);

    if(flag1==1) ret1 = path(p+1,s+a[p],k+1);
    if(flag2==1) ret2 = path(p+1,s,k);

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
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            sum += a[i];
        }

        if(n&1)m=(n/2)+1;
        else m = n/2;

        memset(wp,-1,sizeof(wp));
        int ff = fun(1,0);

        memset(dp,-1,sizeof(dp));
        int dd = path(1,0,0);

        int cnt1 = (sum-dd)/2;
        int cnt2 = cnt1+dd;

        printf("%d %d\n",cnt1,cnt2);
        if(ks<tt)printf("\n");
    }
    return 0;
}

/*
A
10

5
100
200
300
1000
5000

3
1
100000
1

3
1
1
100000

3
100000
1
1

*/

