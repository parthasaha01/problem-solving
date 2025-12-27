#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int mp[51][9005],dp[51][9005];
int n,t,a[55];
int fun(int pos,int w)
{
    if(pos==n)return 0;

    if(mp[pos][w]!=-1)return mp[pos][w];

    int ret1=-1,ret2=-1;

    if(w-a[pos]>=0)ret1 = 1+fun(pos+1,w-a[pos]);
    ret2 = fun(pos+1,w);

    return mp[pos][w] = max(ret1,ret2);
}
int path(int pos,int w)
{
    if(pos==n)return 0;
    if(dp[pos][w]!=-1)return dp[pos][w];

    int ret = fun(pos,w);
    int ret1 = -1,ret2 = -1;
    if(w-a[pos]>=0)ret1 = 1+fun(pos+1,w-a[pos]);
    ret2 = fun(pos+1,w);

    //printf("pos=%d w=%d ret=%d ret1=%d ret2=%d\n",pos,w,ret,ret1,ret2);

    int sum1=-1,sum2=-1;

    if(ret==ret1)sum1 = a[pos]+path(pos+1,w-a[pos]);
    if(ret==ret2)sum2 = path(pos+1,w);

    //printf("pos=%d w=%d ret=%d ret1=%d ret2=%d sum1=%d sum2=%d\n",pos,w,ret,ret1,ret2,sum1,sum2);

    return dp[pos][w] = max(sum1,sum2);

}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d %d",&n,&t);
        int tot = 0;
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            tot+=a[i];
        }

        if(tot<=t-1){
            printf("Case %d: %d %d\n",ks,n+1,tot+678);
            continue;
        }

        //sort(a,a+n);

        memset(mp,-1,sizeof(mp));

        int maxx = fun(0,t-1);

        memset(dp,-1,sizeof(dp));

        int sum  = path(0,t-1);
//        printf("maxx=%d\n",maxx);
//        printf("sum=%d\n",sum);
        int k = maxx+1;
        int ret = sum+678;
        printf("Case %d: %d %d\n",ks,k,ret);
    }
    return 0;
}
