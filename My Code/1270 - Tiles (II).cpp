#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
string s[105];
vector<char>v[105];
ll solve(int r, int c) {

}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++) {
        int n,m; cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        if(n>=m) {
            for(int i=0; i<n; i++) {
                v[i].clear();
                for(int j=0; j<m; j++){
                    v[i].push_back(s[i][j]);
                }
            }
        }
        if(n<m){
            for(int j=0; j<m; j++) {
                v[j].clear();
                for(int i=0; i<n; i++){
                    v[j].push_back(s[i][j]);
                }
            }
        }

        int r = max(n,m);
        int c = min(n,m);
//        for(int i=0; i<r; i++){
//            for(int j=0; j<c; j++) {
//                cout<<v[i][j];
//            }
//            cout<<endl;
//        }

        ll ans = solve(r, c);
        cout<<"Case "<<ks<<": "<<ans<<endl;
    }
    return 0;
}
