#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define MOD 1000000007LL
#define MOD1 104282401LL
#define MOD2 101949191LL
#define BASE1 1000117LL
#define BASE2 10000103LL
#define N 1000005
map< pair<ll,ll>, ll>mp[N];
ll subset[N];

int main(){
    for(ll i=1,x=1; i<=1000000; i++){
        x = (x<<1LL);
        x %= MOD;
        subset[i] = x-1LL;
        if(subset[i]<0) subset[i]+=MOD;
        subset[i]%=MOD;
    }

    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int m; scanf("%d",&m);
        ll val1 = 0, val2 = 0;
        for(int k=1; k<=m; k++){
            ll x; scanf("%lld",&x);
            //val1 += (x*base1[k-1])%MOD1;
            //val1 %= MOD1; // Cause TLE
            //val2 += (x*base2[k-1])%MOD2;
            //val2 %= MOD2; // Cause TLE
            val1 = (val1*BASE1+x)%MOD1;
            val2 = (val2*BASE2+x)%MOD2;
            pll val = make_pair(val1,val2);
            mp[k][val]++;
        }
    }
    mp[0][make_pair(0,0)] = n;

    int q; scanf("%d",&q);
    for(int ks=1; ks<=q; ks++){
        int k; scanf("%d",&k);
        ll ans = 0;
        for(auto it: mp[k]){
            ll cnt = it.second;
            ans += subset[cnt];
            ans %= MOD;
        }
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
