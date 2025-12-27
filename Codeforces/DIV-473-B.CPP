#include<bits/stdc++.h>
using namespace std;
#define ll long long
//map<string,ll>mp;
unordered_map<string, ll> mp;
ll a[100005],b[100005];
string s[100005],ss;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k,m; cin>>n>>k>>m;
    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    cin.ignore(); //important, must use cin.ignore();
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=k; i++){
        int x; cin>>x;
        ll minn = 100000000000000;
        for(int j=1; j<=x; j++){
            cin>>b[j];
            minn = min(minn,a[b[j]]);
        }
        for(int j=1; j<=x; j++){
            mp[s[b[j]]]=minn;
        }
    }

    ll ans = 0;
    for(int i=1; i<=m; i++){
        cin>>ss;
        ans += mp[ss];
    }

    cout << ans << endl;
    mp.clear();

    //main();

    return 0;
}
