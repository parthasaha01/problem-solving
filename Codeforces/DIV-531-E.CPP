#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005],c[200005],b[200005];
int last[200005];
const ll mod = 998244353;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    set<int>ss;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        c[i] = a[i];
        ss.insert(a[i]);
    }
    int k = 0;
    map<int,int>mp;
    for(auto it = ss.begin(); it!=ss.end(); it++){
        mp[*it] = ++k;
    }

    for(int i=1; i<=n; i++){
        a[i] = mp[a[i]];
    }

    for(int i=1; i<=n; i++){
        last[a[i]] = i;
    }

    ll ans = 1;

    b[1] = 0;
    int cur = last[a[1]];
    for(int i=2; i<=n; i++){
        if(i>cur){
            ans *= 2;
            ans %= mod;
            cur = max(cur,last[a[i]]);
        }else{
            cur = max(cur,last[a[i]]);
        }
    }

    cout<<ans<<endl;

    return 0;
}
