#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[19][2][2][2];
string a,b,s,ans;
ll fun(int pos, int choto, int boro, int suru) {
    if(pos==b.size()){
        if(suru) return 1LL;
        return 0LL;
    }

    ll &ret = dp[pos][choto][boro][suru];
    if(ret != -1) return ret;
    ret = 0LL;

    int lo = 0, hi = 9;
    if(choto==0) hi = b[pos]-'0';
    if(boro==0)  lo = a[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        if(i==0 && suru==0){
            ret = max(ret, fun(pos+1, choto | (i<hi), boro | (i>lo), suru | (i>0)));
        }else{
            ret = max(ret, i*fun(pos+1, choto | (i<hi), boro | (i>lo), suru | (i>0)));
        }
    }

    return ret;
}
void path(int pos, int choto, int boro, int suru) {
    if(pos == b.size()) return;

    ll maxx = fun(pos, choto, boro, suru);

    int lo = 0, hi = 9;
    if(choto==0) hi = b[pos]-'0';
    if(boro==0)  lo = a[pos]-'0';

    for(int i=lo; i<=hi; i++) {
        ll ret;
        if(i==0 && suru==0){
            ret = fun(pos+1, choto | (i<hi), boro | (i>lo), suru | (i>0));
        }else{
            ret = i*fun(pos+1, choto | (i<hi), boro | (i>lo), suru | (i>0));
        }

        if(ret==maxx){
            s += i + '0';
            path(pos+1, choto | (i<hi), boro | (i>lo), suru | (i>0));
            break;
        }
    }
}
int main() {
    cin>>a>>b;
    while(a.size()<b.size()) a = "0" + a;

    memset(dp, -1, sizeof(dp));
    ll ret = fun(0,0,0,0);

    path(0,0,0,0);

    for(int i=0; i<s.size(); i++) {
        if(s[i]!='0'){
            for(int j=i; j<s.size(); j++) {
                ans += s[j];
            }
            break;
        }
    }

    cout<<ans<<endl;

    return 0;
}