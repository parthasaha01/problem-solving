#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
int m,d;
int dp[2001][2001][2][2];
int mod = 1000000007;
int fun(int pos, int rem, int choto, int boro) {
    if(pos==b.size()){
        if(rem==0) return 1;
        return 0;
    }

    int &ret = dp[pos][rem][choto][boro];
    if(ret != -1) return ret;
    ret = 0;

    int lo = 0, hi = 9;
    if(!choto) hi = b[pos] - '0';
    if(!boro)  lo = a[pos] - '0';

    for(int i=lo; i<=hi; i++) {
        if(pos%2==0 && i==d) continue;
        if(pos%2==1 && i!=d) continue;
        ret += fun(pos+1, ((rem*10)+i)%m, choto|(i<hi), boro|(i>lo))%mod;
        ret %= mod;
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>d;
    cin>>a>>b;

    memset(dp,-1,sizeof(dp));
    int ans = fun(0,0,0,0);
    cout << ans << endl;

    return 0;
}

