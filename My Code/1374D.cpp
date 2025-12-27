#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll, ll>mp;
vector<ll>v;
ll solve(ll k){
    mp.clear();
    ll ans = 0;

    for(int i=0; i<v.size(); i++) {
        ll d = (v[i]/k);
        ll need = ((d+1)*k)-v[i];
        if(mp[need]==0){
            mp[need] = need;
        }else{
            mp[need] = mp[need]+k;
        }
        ans = max(ans, mp[need]);
    }
    if(ans>0)ans++;
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int t=1; t<=tt; t++){
        ll n, k; cin>>n>>k;
        v.clear();
        for(int i=0; i<n; i++){
            ll x; cin>>x;
            if(x%k != 0){
                v.push_back(x);
            }
        }

        sort(v.begin(), v.end());

        cout<<solve(k)<<endl;
    }
    return 0;
}




