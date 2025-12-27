#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[120005];
vector<ll>v;
map<ll,int>mp;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    v.clear();
    mp.clear();
    for(ll i=0; i<32; i++){
        v.push_back(1LL<<i);
    }
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        int f=1;
        for(int k=0; k<v.size(); k++){
            if(v[k]<=a[i])continue;
            ll x = v[k]-a[i];
            if(x==a[i]){
                if(mp[x]>1){
                    f = 0;
                    break;
                }
            }
            else{
                if(mp[x]>0){
                    f = 0;
                    break;
                }
            }
        }

        if(f){
            ans++;
            mp[a[i]]--;
        }
    }

    cout << ans << endl;
    //main();
    return 0;

}
