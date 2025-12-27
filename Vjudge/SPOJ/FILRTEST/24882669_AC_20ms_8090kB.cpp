#include<bits/stdc++.h>
using namespace std;
int f[1000005];
void failure_function(int m, string& s) {
    f[0] = 0;
    for(int j=0, i=1; i<m; i++) {
        if(s[i] == s[j]){
            j++;
        }else {
            while(j>0) {
                j = f[j-1];
                if(s[i] == s[j]) {
                    j++;
                    break;
                }
            }
        }
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
