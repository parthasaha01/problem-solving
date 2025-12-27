#include<bits/stdc++.h>
using namespace std;
string s,ans;
int dp[43][2];
int fun(int pos, int prev) {
    if(pos==43) return 1LL;
    if(dp[pos][prev] != -1) return dp[pos][prev];
    int ret = 0;
    ret += fun(pos+1, 0);
    if(prev!=1) ret += fun(pos+1, 1);
    return dp[pos][prev] = ret;
}
void path(int pos,int prev,int nth) {
    if(pos==43) return;

    int cnt = fun(pos+1, 0);

    if(nth <= cnt) {
        s += '0';
        path(pos+1, 0, nth);
    }else {
        s += '1';
        path(pos+1, 1, nth-cnt);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp,-1,sizeof(dp));
    int ret = fun(0,0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++) {
        int n; cin>>n;
        n++; // for zero

        s.clear();
        ans.clear();

        path(0,0,n);

        for(int i=0; i<s.size(); i++) {
            if(s[i]!='0'){
                for(int j=i; j<s.size(); j++) {
                    ans += s[j];
                }
                break;
            }
        }

        cout<<"Case "<<ks<<": "<<ans<<endl;
    }

    return 0;
}

