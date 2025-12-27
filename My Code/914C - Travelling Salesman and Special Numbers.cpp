#include<bits/stdc++.h>
using namespace std;
string s;
int n, k, step[1001],dp[1001][1001][2][2];
const int mod = 1000000007;
int fun(int pos,int cnt,int choto,int suru) {
    if(pos==n) {
        if(!suru) return 0;
        if(k == step[cnt]+1) return 1;
        return 0;
    }

    int &ret = dp[pos][cnt][choto][suru];
    if(ret != -1) return ret;
    ret = 0;

    int lo=0, hi=1;
    if(!choto) hi = s[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        ret += fun(pos+1,cnt+(i==1),choto|(i<hi),suru|(i>0))%mod;
        ret %= mod;
    }
    return ret;
}
int main() {
    step[1] = 0;
    for(int i=2; i<=1000; i++) {
        int bit = __builtin_popcount(i);
        step[i] = 1 + step[bit];
    }

    cin>>s>>k;
    n = s.size();

    memset(dp, -1, sizeof(dp));
    int ans = fun(0,0,0,0);
    if(k==0) ans = 1;
    if(k==1) ans--; // for 1
    cout<<ans<<endl;

    return 0;
}
