#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define ppll pair< pair<ll,ll>, ll>
#define MOD 1000000007LL
#define MOD1 104282401LL
#define MOD2 101949191LL
#define BASE1 1000117LL
#define BASE2 10000103LL
#define N 1000005
map< pair< pair<ll,ll>, ll>, ll>mp;
ll subset[N], ans[N], base1[N], base2[N];

int main(){
    base1[0] = base2[0] = 1LL;
    for(ll i=1,x=1; i<=1000000; i++){
        x = (x<<1LL);
        x %= MOD;
        subset[i] = x-1LL;
        if(subset[i]<0) subset[i]+=MOD;
        //subset[i]%=MOD;

        base1[i] = (base1[i-1]*BASE1)%MOD1;
        base2[i] = (base2[i-1]*BASE2)%MOD2;
    }

    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        int m; scanf("%d",&m);
        ll val1 = 0, val2 = 0;
        for(int k=1; k<=m; k++){
            ll x; scanf("%lld",&x);
            val1 = (val1+x*base1[k-1])%MOD1;
            //val1 %= MOD1;
            val2 = (val2+x*base2[k-1])%MOD2;
            //val2 %= MOD2;
            ppll val = make_pair(make_pair(val1,val2),k);
            mp[val]++;
            //printf("i=%d k=%d x=%lld val1=%lld val2=%lld, mp=%lld\n",i,k,x,val1,val2,mp[val]);
        }
    }

    ans[0] = subset[n]%MOD;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        ll cnt = (ll)it->second;
        ppll val = it->first;
        ll len = val.second;
        //printf("len=%lld cnt=%lld\n",len,cnt);
        ans[len] += subset[cnt];
        ans[len] %= MOD;
    }

    int q; scanf("%d",&q);
    for(int ks=1; ks<=q; ks++){
        int k; scanf("%d",&k);
        printf("Case %d: %lld\n",ks,ans[k]);
    }

    return 0;
}


