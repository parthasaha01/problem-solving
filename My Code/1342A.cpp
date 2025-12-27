#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll x, ll y, ll a, ll b) {
    ll cost = 0;
    cost += (y-x)*a;
    if(b>(2*a)) {
        cost += 2*x*a;
    }else{
       cost += x*b;
    }
    return cost;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--) {
        ll x, y; cin>>x>>y;
        ll a, b; cin>>a>>b;
        cout<<fun(min(x,y), max(x,y), a, b)<<endl;
    }
    return 0;
}
