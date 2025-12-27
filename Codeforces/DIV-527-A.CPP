#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt;cin>>tt;
    for(int ks=1; ks<=tt; ks++){
        int n,k; cin>>n>>k;

        int cur = 0;
        string s;
        for(int i=0; i<n; i++){
            s += cur+'a';
            cur++;
            if(cur==k)cur=0;
        }
        cout << s << endl;
    }
    return 0;
}
