#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 101949191LL
#define BASE 1000117LL
ll b[1000005], h[1000005];
void pre_calculation(){
    b[0] = 1;
    for(int i=1; i<=1000000; i++ ){
        b[i] = (b[i-1]*BASE)%MOD;
    }
}
void make_hash(int m, string& s) {
    for(int i=0; i<m; i++) {
        h[i] = (h[i-1] + (s[i]*b[m-i-1]))%MOD;
    }
}
int calculation(int n, int m, string& s) {
    if(n<m) return 0;
    // Calculate the largest proper suffix that is also a prefix
    make_hash(m, s);
    int ret = 0;
    for(int i=1; i<m; i++) {
        ll hh = (h[m-1]-h[i-1])%MOD;
        if(hh<0){
            hh = (hh+MOD)%MOD;
        }
        hh = (hh*b[i])%MOD;
        if(hh == h[m-i-1]){
            ret = m-i;
            break;
        }
    }
    int ans = 1 + ((n-m)/(m-ret));
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre_calculation();
    int n;
    while(cin>>n && n!=-1){
        string s; cin>>s;
        int m = s.size();
        int ans = calculation(n, m, s);
        cout<<ans<<endl;
    }
    return 0;
}
