#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
ll way[10][2][2], dp[10][2][2][2];
ll go(int pos, int choto, int boro) {
    if(pos<0) return 1LL;

    ll &ret = way[pos][choto][boro];
    if(ret != -1 && choto && boro) return ret;
    ret = 0;

    int lo = 0, hi = 9;
    if(choto==0) hi = b[pos]-'0';
    if(boro==0)  lo = a[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        ret += go(pos-1, choto | (i<hi), boro | (i>lo));
    }

    return ret;
}
ll fun(int pos, int choto, int boro, int suru) {
    if(pos<0) return 0;

    ll &ret = dp[pos][choto][boro][suru];
    if(ret != -1 && choto && boro) return ret;
    ret = 0;

    int lo = 0, hi = 9;
    if(choto==0) hi = b[pos]-'0';
    if(boro==0)  lo = a[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        ll cnt = 0;
        if(i==0 && suru) {
            cnt = go(pos-1, choto | (i<hi), boro | (i>lo));
        }

        ret += cnt + fun(pos-1, choto | (i<hi), boro | (i>lo), suru | (i>0));
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(way, -1, sizeof(way));
    memset(dp, -1, sizeof(dp));

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++) {
        cin>>a>>b;
        int flag = 0;
        if(a=="0") flag = 1;
        if(a.size()<b.size()) {
            int d = b.size() - a.size();
            string temp;
            while(d--) {
                temp += '0';
            }
            a = temp + a;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        //while(a.size()<10) a = "0"+a;
        //while(b.size()<10) b = "0"+b;


        ll ret = go(b.size()-1,0,0);

        ll ans = fun(b.size()-1,0,0,0) + flag;

        cout<<"Case "<<ks<<": "<<ans<<endl;
    }

    return 0;
}

