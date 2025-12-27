#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n, ll p){
    for(int i=1; i<=31; i++) {
        ll x = n-(i*p);
        if(x<i)continue;
        ll cnt = __builtin_popcount(x);
        if(cnt<=i){
            return i;
        }
    }
    return -1;
}
int main() {
    ll n,p; cin>>n>>p;
    cout<<solve(n,p)<<endl;
    return 0;
}
