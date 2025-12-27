#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[101], dp[101][51][23001],cnt1,cnt2;
int fun(int p, int k, int s)
{
    if(p==n+1){
        if(abs((n-k)-k)<=1)return abs(s-(sum-s));
        else return 100000000;
    }

    if(k>m)return 100000000;

    if(dp[p][k][s]!=-1)return dp[p][k][s];

    int ret1 = fun(p+1,k+1,s+a[p]);
    int ret2 = fun(p+1,k,s);
    int ret  = min(ret1,ret2);
    return dp[p][k][s] = ret;
}
void path(int p, int k, int s)
{
    if(p==n+1){
        cnt1=s;
        cnt2=sum-s;
        if(cnt1>cnt2)swap(cnt1,cnt2);
        return;
    }

    //if(k>m)return;

    int ret = fun(p,k,s);
    int ret1 = fun(p+1,k+1,s+a[p]);
    int ret2 = fun(p+1,k,s);

    if(ret==ret1)path(p+1,k+1,s+a[p]);
    else path(p+1,k,s);
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

        if(n&2)m=(n/2)+1;
        else m = n/2;

        memset(dp,-1,sizeof(dp));
//        for(int i=1; i<=n; i++){
//            for(int j=0; j<=n; j++){
//                for(int k=0; k<=sum; k++){
//                    dp[i][j][k]=-1;
//                }
//            }
//        }

        int ans = fun(1,0,0);
        //printf("%d\n",ans);
        cnt1=cnt2=0;
        path(1,0,0);

        printf("%d %d\n",cnt1,cnt2);
        if(ks<tt)printf("\n");
    }
    return 0;
}

