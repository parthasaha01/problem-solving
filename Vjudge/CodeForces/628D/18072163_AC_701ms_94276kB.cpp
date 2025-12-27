#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,temp,s;
int m,d;
int dp[2001][2001][2][3];
int mod = 1000000007;
int fun(int pos, int rem, int choto, int flag) {
    if(pos==s.size()){
        if(flag && rem==0) return 1;
        return 0;
    }

    int &ret = dp[pos][rem][choto][flag];
    if(ret != -1) return ret;
    ret = 0;
    int lo = 0, hi = 9;
    if(!choto) hi = s[pos] - '0';

    for(int i=lo; i<=hi; i++) {
        if(i==0 && flag==0) {
            ret += fun(pos+1,rem,choto|(i<hi),flag)%mod;
            ret %= mod;
        }else {
            if(i==d && (pos%2==0)) continue;
            if(i!=d && (pos%2==1)) continue;
            int nflag = flag;
            if(i==d) nflag = 2;
            if(nflag==0) nflag = 1;
            ret += fun(pos+1,((rem*10)+i)%m,choto|(i<hi),nflag)%mod;
            ret %= mod;
        }
    }

    return ret;
}
int isMagic() {
    int rem = 0;
    for(int i=0; i<a.size(); i++) {
        if(i%2==0) {
            if(d == a[i]-'0')return 0;
        }else{
            if(d != a[i]-'0')return 0;
        }
        rem = ((rem*10)+(a[i]-'0'))%m;
    }
    if(rem!=0) return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>d;
    cin>>a>>b;

    s = b;
    memset(dp,-1,sizeof(dp));
    int ans1 = fun(0,0,0,0);

    s = a;
    memset(dp,-1,sizeof(dp));
    int ans2 = fun(0,0,0,0);

    int ans = ans1 - ans2;
    if(ans<0) ans = (ans+mod)%mod;

    if(isMagic()) ans++;
    ans %= mod;
    cout << ans << endl;

    return 0;
}

