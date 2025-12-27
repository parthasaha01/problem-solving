#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m, n, a[10];
ll dp[10][10];
ll fun(int pos,int prev){
    if(pos==n)return 1LL;
    if(dp[pos][prev] != -1) return dp[pos][prev];
    ll ret = 0;
    for(int i=0; i<m; i++) {
        if(pos==0) {
            ret += fun(pos+1, a[i]);
        }else {
            if(abs(prev-a[i])<=2) {
                ret += fun(pos+1,a[i]);
            }
        }
    }

    return dp[pos][prev] = ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    for(int ks = 1; ks <= tt; ks++) {
        cin>>m>>n;
        for(int i = 0; i < m; i++) cin>>a[i];

        memset(dp,-1,sizeof(dp));
        ll ans =  fun(0,0);

        cout<<"Case "<<ks<<": "<<ans<<endl;
    }
    return 0;
}
