#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int tt; cin>>tt;
    while(tt--){
        ll k,x; cin>>k>>x;
        ll ans = (k-1)*9 + x;
        cout<<ans<<endl;
    }
    return 0;
}
