#include<bits/stdc++.h>
using namespace std;
int n,d,offshift,cnt[30001];
int dp[30001][500];
int fun(int cur,int jump)
{
    if(cur>30000)return 0;
    if(dp[cur][jump-offshift]!=-1)return dp[cur][jump-offshift];
    int ret = 0;
    if(cur+jump-1>cur)ret = max(ret, cnt[cur]+fun(cur+jump-1,jump-1));
    ret = max(ret, cnt[cur]+fun(cur+jump,jump));
    ret = max(ret, cnt[cur]+fun(cur+jump+1,jump+1));
    return dp[cur][jump-offshift] = ret;
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++){
        int x; scanf("%d",&x);
        cnt[x]++;
    }

    offshift = d-250;

    memset(dp,-1,sizeof(dp));
    int ans = fun(d,d);
    printf("%d\n",ans);

    return 0;
}

