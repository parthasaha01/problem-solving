#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[19][4][2][2];
string a,b;
ll fun(int pos,int cnt,int choto,int boro) {
    if(pos==19)return 1LL;
    ll &ret = dp[pos][cnt][choto][boro];
    if(ret!=-1 && choto && boro) return ret;
    ret = 0;

    int lo = (boro) ? 0 : a[pos]-'0';
    int hi = (choto)  ? 9 : b[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        if(i>0 && cnt==3) continue;
        ret += fun(pos+1,cnt+(i>0),choto|(i<hi),boro|(i>lo));
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    int tt; cin>>tt;
    while(tt--){
        cin>>a>>b;
        while(a.size()<19) a.insert(a.begin(),'0');
        while(b.size()<19) b.insert(b.begin(),'0');

        ll ans = fun(0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
