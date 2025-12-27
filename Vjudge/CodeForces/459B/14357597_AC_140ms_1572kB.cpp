#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    ll maxx = 0, minn = 100000000000LL;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        maxx = max(maxx,a[i]);
        minn = min(minn,a[i]);
    }

    ll mx = 0, mn = 0;

    for(int i=1; i<=n; i++){
        if(a[i]==maxx)mx++;
        if(a[i]==minn)mn++;
    }

    if(maxx==minn) cout << maxx-minn << " " << (mx*(mx-1))/2LL << endl;
    else cout << maxx-minn << " " << mx*mn << endl;

    return 0;
}
