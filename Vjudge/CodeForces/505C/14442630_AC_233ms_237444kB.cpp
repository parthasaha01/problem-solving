#include<bits/stdc++.h>
using namespace std;
int n,d,offshift,cnt[30005];
int dp[30005][2005];
int go(int cur,int jump)
{
    if(cur>30000)return 0;
    if(dp[cur][jump]!=-1)return dp[cur][jump];
    int ret = 0;
    if(cur+jump-1>cur)ret = max(ret, cnt[cur] + go(cur+jump-1,jump-1));
    ret = max(ret, cnt[cur] + go(cur+jump,jump));
    ret = max(ret, cnt[cur] + go(cur+jump+1,jump+1));
    return dp[cur][jump] = ret;
}
int gogo(int cur,int jump)
{
    if(cur>30000)return 0;
    int ret = 0;
    if(cur+jump-1>cur)ret = max(ret, cnt[cur] + gogo(cur+jump-1,jump-1));
    ret = max(ret, cnt[cur] + gogo(cur+jump,jump));
    ret = max(ret, cnt[cur] + gogo(cur+jump+1,jump+1));
    return ret;
}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++){
        int x; scanf("%d",&x);
        cnt[x]++;
    }

    if(d<=2000){
        memset(dp,-1,sizeof(dp));
        int ans = go(d,d);
        printf("%d\n",ans);
    }
    else{
        int ans = gogo(d,d);
        printf("%d\n",ans);
    }

    return 0;
}
