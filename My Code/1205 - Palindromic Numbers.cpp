#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string s;
ll dp[18][2][2][2][18];
ll fun(int pos, int suru, int choto, int boroNisi, int backPos) {
    if(pos>backPos){
        if(choto==0 && boroNisi==1) return 0LL;
        return 1LL;
    }

    ll &ret = dp[pos][suru][choto][boroNisi][backPos];
    if(ret != -1) return ret;
    ret = 0;
    int lo = 0, hi = 9;
    if(!choto) hi = s[pos] - '0';

    for(int i=lo; i<=hi; i++) {
        if(i==0 && suru==0){
            ret += fun(pos+1, suru, choto|(i<hi), boroNisi, backPos);
        }else if(i==s[backPos]-'0') {
            ret += fun(pos+1, suru|(i>0), choto|(i<hi), boroNisi, backPos-1);
        }else{
            ret += fun(pos+1, suru|(i>0), choto|(i<hi), i>s[backPos]-'0', backPos-1);
        }
    }

    return ret;
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
    ll ret = fun(0,0,0,0,s.size()-1);
    return ret;
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
