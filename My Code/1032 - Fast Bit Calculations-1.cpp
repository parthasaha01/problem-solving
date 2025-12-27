#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a;
ll n, dp[31][2][2][31];
ll fun(int pos,int choto, int prev,int cnt) {
    if(pos==a.size())return cnt;

    ll &ret = dp[pos][choto][prev][cnt];
    if(ret != -1 && choto) return ret;
    ret = 0;

    int lo = 0, hi = 1;
    if(choto==0) hi = a[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        ret +=  fun(pos+1, choto | (i<hi), i, cnt + (prev==1 && i==1));
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++) {
        cin>>n;
        a="";
        while(n!=0){
            int r = n%2;
            n /= 2;
            a += r+'0';
        }
        while(a.size()<31){
            a += '0';
        }
        reverse(a.begin(), a.end());

        ll ans = fun(0,0,0,0);

        cout<<"Case "<<ks<<": "<<ans<<endl;
    }

    return 0;
}

