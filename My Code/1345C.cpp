#include<bits/stdc++.h>
using namespace std;
int a[200005];
string solve(int n) {
    map<int, int>mp;
    for(int i=0; i<n; i++) {
        int r = a[i]%n;
        if(r<0){
            r = (r+n)%n;
        }
        if(mp[r]==1){
            return "NO";
        }
        mp[r] = 1;
    }
    return "YES";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    while(tt--) {
        int n; cin>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        cout<<solve(n)<<endl;
    }
    return 0;
}
