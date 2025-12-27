#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
vector<pll>v;
vector<ll>ans;
ll calc(ll x, ll a, ll b, ll lcm) {
    if(lcm==a || lcm==b)return 0;
    ll  p = (x/lcm);
    ll cnt = p*(lcm-b);
    ll r = x%(lcm);
    if(r>b-1)
        cnt += (r-b+1);
    return cnt;
}
void fun(int a, int b) {
    if(a>b)swap(a,b);
    ll gcd = __gcd(a,b);
    ll lcm = (a*b)/gcd;

    ans.clear();
    for(int i=0; i<v.size(); i++) {
        ll l = v[i].first;
        ll r = v[i].second;
        if(l>r) swap(l,r);
        ll ret = calc(r, a, b,lcm);
        ret -= calc(l-1, a, b, lcm);
        ans.push_back(ret);
//        ll temp = 0;
//        for(int x=l; x<=r; x++) {
//            ll m1 = ((x%a)%b);
//            ll m2 = ((x%b)%a);
//            if(m1==m2){
//                cout<<x<<" "<<m1<<" "<<m2<<" "<<"equal"<<endl;
//            }else{
//                temp++;
//                cout<<x<<" "<<m1<<" "<<m2<<" "<<"not equal"<<endl;
//            }
//        }
//        cout<<temp<<endl;

    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--) {
        int a,b,q; cin>>a>>b>>q;
        v.clear();
        while(q--) {
            ll l,r; cin>>l>>r;
            v.push_back(make_pair(l,r));
        }
        fun(a,b);
        for(int i=0; i<ans.size(); i++) {
            if(i<ans.size()-1)cout<<ans[i]<<" ";
            else cout<<ans[i]<<endl;
        }
    }
    return 0;
}


