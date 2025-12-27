#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD = 1000000007;
ll dp[101][101][128];
ll fun(int pos,int rem,int xorr){
    if(pos==0){
        if(rem==0&&xorr>0)return 1LL;
        return 0LL;
    }
    if(rem<=0)return 0LL;
    if(dp[pos][rem][xorr] != -1) return dp[pos][rem][xorr];
    ll ret = 0;
    for(int i=1; i<=rem; i++){
        ret += fun(pos-1, rem-i, xorr^i);
        ret %= MOD;
    }
    return dp[pos][rem][xorr] = ret;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int tt; scanf("%d",&tt);
    while(tt--){
        int n; scanf("%d",&n);
        ll ans = 0;
        for(int i=1; i<=n; i++){
            ll ret = fun(i,n,0);
            ans += ret;
            ans %= MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
