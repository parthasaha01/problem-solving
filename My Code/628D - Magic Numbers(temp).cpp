#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,temp,s;
int m,d;
int dp[2001][2001][2][2][2][3];
int mod = 1000000007;
int fun(int pos, int rem, int choto, int boro, int even, int flag) {
    if(pos==b.size()){
        if(flag && rem==0) return 1;
        return 0;
    }

    int &ret = dp[pos][rem][choto][boro][even][flag];
    if(ret != -1 && choto) return ret;
    ret = 0;
    int lo = 0, hi = 9;
    if(!choto) hi = b[pos] - '0';
    if(!boro)  lo = a[pos] - '0';

    for(int i=lo; i<=hi; i++) {
        if(i==0 && flag==0) {
            ret += fun(pos+1,rem,choto|(i<hi),boro|(i>lo),even,flag)%mod;
            ret %= mod;
        }else {
            if(i==d && (!even)) continue;
            if(i!=d && even) continue;
            int nflag = flag;
            if(i==d) nflag = 2;
            if(nflag==0) nflag = 1;
            ret += fun(pos+1,((rem*10)+i)%m,choto|(i<hi),boro|(i>lo),1-even,nflag)%mod;
            ret %= mod;
        }
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>d;
    cin>>a>>b;

//    if(b.size()==1) {
//        int l = a[0]-'0';
//        int r = b[0]-'0';
//        int ans = 0;
//        for(int i=l; i<=r; i++){
//            if(i%m==0 && i!=d)ans++;
//        }
//        cout<<ans<<endl;
//        return 0;
//    }

    int diff = b.size() - a.size();
    while(diff--) temp += '0';
    a = temp + a;

    memset(dp,-1,sizeof(dp));

    int ans = fun(0,0,0,0,0,0);

    cout << ans << endl;

    return 0;
}

