#include<bits/stdc++.h>
using namespace std;
int f[1000005];
void failure_function(int m, string& s) {
    for(int i=1,j=0; i<m; i++) {
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) ++j;
        f[i] = j;
    }
    return;
}
int calculation(int n, int m, string& s) {
    if(n<m) return 0;
    failure_function(m, s);
    int ans = 1 + ((n-m)/(m-f[m-1]));
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    string s;
    while(cin>>n>>s){
        if(n==-1 && s=="*")break;
        int m = s.size();
        int ans = calculation(n, m, s);
        cout<<ans<<endl;
    }
    return 0;
}
