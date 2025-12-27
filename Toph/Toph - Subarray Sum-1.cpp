#include<bits/stdc++.h>
using namespace std;
int n,k,a[5001], dp[5001][5001];
int fun(int pos,int cnt){
    if(pos>n)return 0;
    if(dp[pos][cnt]!=-1)return dp[pos][cnt];
    int ret = -1000000000;
    if(a[pos]<0 && cnt<k) ret = max(ret, fun(pos+1,cnt+1));
    ret = max(ret, a[pos]+fun(pos+1,cnt));
    return dp[pos][cnt] = max(ret,a[pos]);
}
int main(){
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        int ans = -1000000000;
        for(int i=1; i<=n; i++){
            ans = max(ans, a[i]);
            ans = max(ans, fun(i,0));
        }
        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}

