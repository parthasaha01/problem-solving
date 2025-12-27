#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string s;
ll dp[18][2][2][18];
ll fun(int pos, int suru, int choto, int backPos) {
    if(pos>backPos) return 1LL;

    ll &ret = dp[pos][suru][choto][backPos];
    if(ret != -1) return ret;
    ret = 0;
    int lo = 0, hi = 9;
    if(!choto) hi = s[pos] - '0';

    for(int i=lo; i<=hi; i++) {
        if(i==0 && suru==0){
            ret += fun(pos+1, suru, choto|(i<hi), backPos);
        }else{
            ret += fun(pos+1, suru|(i>0), choto|(i<hi), backPos-1);
        }
    }

    return ret;
}
int check() {
    int n = s.size();
    for(int i=(n-1)/2, j = (n/2); i>=0; i--,j++) {
        if(s[i] > s[j]) return 1;
        if(s[i] < s[j]) return 0;
    }
    return 0;
}
ll solve(ll x) {
    if(x<0) return 0LL;
    if(x==0) return 1LL;

    s.clear();
    while(x!=0) {
        int r = x%10;
        x /= 10;
        s += r+'0';
    }
    reverse(s.begin(), s.end());

    memset(dp,-1,sizeof(dp));
    ll ret = fun(0,0,0,s.size()-1);
    return ret - check();
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++) {
        ll a,b; cin>>a>>b;
        if(a>b) swap(a,b);

        ll ans = solve(b) - solve(a-1);
        cout << "Case " << ks << ": " << ans << endl;
    }

    return 0;
}
