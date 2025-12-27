#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
map<ll,ll>mp;
ll a[mx+5],b[mx+5],x[mx+5],y[mx+5];;
int main()
{
    mp.clear();
    ll ans = 0;
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%lld %lld",&a[i],&x[i]);
        mp[a[i]] = x[i];
        ans += x[i];
    }

    int m; scanf("%d",&m);
    for(int i=1; i<=m; i++){
        scanf("%lld %lld",&b[i],&y[i]);
        if(mp.find(b[i])==mp.end()){
            ans += y[i];
        }
        else{
            ans -= mp[b[i]];
            ans += max(mp[b[i]],y[i]);
        }
    }

    cout << ans << endl;
   // main();
    return 0;
}
