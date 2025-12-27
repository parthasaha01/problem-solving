#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,temp,s;
int m,d;
int dp[2001][2001][2][2][2][2];
int mod = 1000000007;
int fun(int pos, int rem, int choto,int suru, int flag,int even) {
    if(pos==s.size()){
        if(suru==0) return 0;
        if(d==0 && rem==0) return 1LL;
        if(rem==0 && flag) return 1LL;
        return 0LL;
    }

    int &ret = dp[pos][rem][choto][suru][flag][even];
    if(ret != -1 && choto) return ret;
    ret = 0;
    int lo = 0, hi = 9;
    if(!choto) hi = s[pos] - '0';

    for(int i=lo; i<=hi; i++) {
        if(i==0 && suru==0) {
            ret += fun(pos+1,rem,choto|(i<hi),suru,flag,even)%mod;
            ret %= mod;
        }else {
            if(i==d && (!even)) continue;
            if(i!=d && even) continue;
            ret += fun(pos+1,((rem*10)+i)%m,choto|(i<hi),suru|(i>0),flag|(i==d),1-even)%mod;
            ret %= mod;
        }
    }

    return ret;
}
int isMagic() {

    if(a.size()==1){
        int x = a[0]-'0';
        if(x%m==0 && x!=d) return 1;
        return 0;
    }

    int rem = 0;
    for(int i=0; i<a.size(); i++) {
        rem = (rem*10)+(a[i]-'0');
        rem %= m;
    }
    if(rem!=0)return 0;
    if(d==0) {
        for(int i=0; i<a.size(); i+=2){
            if(a[i]=='0') return 0;
        }
        for(int i=1; i<a.size(); i+=2){
            if(a[i]!='0') return 0;
        }
        return 1;
    }else {
        for(int i=0; i<a.size(); i+=2){
            if(a[i]==d+'0') return 0;
        }
        int f = 0;
        for(int i=1; i<a.size(); i+=2){
            if(a[i]==d+'0'){
                f = 1;
                break;
            }
        }

        if(!f)return 0;

        for(int i=1; i<a.size(); i+=2){
            if(a[i]!=d+'0') return 0;
        }
        return 1;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>d;
    cin>>a>>b;
    int diff = b.size() - a.size();
    while(diff--) temp += '0';
    temp = temp + a;

    if(b.size()==1) {
        int l = a[0]-'0';
        int r = b[0]-'0';
        int ans = 0;
        for(int i=l; i<=r; i++){
            if(i%m==0 && i!=d)ans++;
        }
        cout<<ans<<endl;
        return 0;
    }

    memset(dp,-1,sizeof(dp));

    s = b;
    int ans1 = fun(0,0,0,0,0,0);
    //cout<<"ans1="<<ans1<<endl;

    int ans2 = 0;
    if(a.size()==1){
        int x = a[0]-'0';
        for(int i=1; i<=x; i++){
            if(i%m==0 && i!=d){
                ans2++;
                //cout<<i<<" ";
            }
        }
    }else {
        s = temp;
        ans2 = fun(0,0,0,0,0,0);
    }
    //cout<<"ans2="<<ans2<<endl;

    //cout<<ans1<<" "<<ans2<<endl;

    int ans = ans1 - ans2;
    if(ans<0) ans = (ans+mod);
    if(isMagic()) ans++;
    ans %= mod;

    cout << ans << endl;
    //main();
    return 0;
}

