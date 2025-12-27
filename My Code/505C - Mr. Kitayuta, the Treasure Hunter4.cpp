#include<bits/stdc++.h>
using namespace std;
int n,d,offshift,cnt[30005];
int dp[30005][505];
int fun(int cur,int jump)
{
    if(cur>30000)return 0;
    if(dp[cur][250+jump]!=-1)return dp[cur][250+jump];
    int ret = 0;
    if(d+jump-1>0)ret = max(ret, cnt[cur] + fun(cur+d+jump-1,jump-1));
    ret = max(ret, cnt[cur] + fun(cur+d+jump,jump));
    ret = max(ret, cnt[cur] + fun(cur+d+jump+1,jump+1));
    return dp[cur][250+jump] = ret;
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++){
        int x; scanf("%d",&x);
        cnt[x]++;
    }

    memset(dp,-1,sizeof(dp));
    int ans = fun(d,0);
    printf("%d\n",ans);

    return 0;
}

