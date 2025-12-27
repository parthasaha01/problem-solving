#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
ll dp[10][2][2][83][83];
int k;
ll fun(int pos, int choto, int boro, int rem, int dsum) {
    if(pos==b.size()) {
        if(rem==0 && dsum==0) return 1LL;
        return 0LL;
    }

    ll &ret = dp[pos][choto][boro][rem][dsum];
    if(ret != -1) return ret;
    ret = 0;

    int lo = 0, hi = 9;
    if(choto==0) hi = b[pos]-'0';
    if(boro==0)  lo = a[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        ret += fun(pos+1, choto | (i<hi), boro | (i>lo), ((rem*10)+i)%k, (dsum+i)%k);
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++) {
        cin>>a>>b>>k;

        if(a.size()<b.size()) {
            int d = b.size() - a.size();
            string temp;
            while(d--) {
                temp += '0';
            }
            a = temp + a;
        }

        if(k>82) {
            cout<<"Case "<<ks<<": "<<0<<endl;
        }else{
            memset(dp, -1, sizeof(dp));
            ll ans = fun(0,0,0,0,0);

            cout<<"Case "<<ks<<": "<<ans<<endl;
        }
    }

    return 0;
}