#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD = 1000000007;
ll a[100005], cum[100005], power[100005];
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    power[0] = 1;
    for(int i=1; i<=100001; i++){
        power[i] = power[i-1]*2;
        power[i] %= MOD;
    }
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++){
        int n,q; cin>>n>>q;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            a[i] = (a[i]&1);
        }
        for(int i=1; i<=n; i++){
            cum[i] = cum[i-1]+a[i];
        }
        while(q--){
            int l,r,t; cin>>l>>r>>t;
            if(l>r)swap(l,r);
            if(t==1){
                ll odd = cum[r]-cum[l-1];
                ll tot = r-l+1;
                ll ans = power[odd];
                ans -= 1;
                if(ans<0)ans = (ans+MOD)%MOD;
                cout<<ans<<endl;
            }else{
                ll odd = cum[r]-cum[l-1];
                ll tot = r-l+1;
                ll ret = power[odd];
                ret -= 1;
                if(ret<0)ret = (ret+MOD)%MOD;
                ll ans = power[tot];
                ans -= ret;
                ans -= 1;
                if(ans<0)ans = (ans+MOD)%MOD;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
