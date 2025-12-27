#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[55][55],row[55][2],col[55][2];

int main()
{
    ll n,m; cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            row[i][a[i][j]]++;
            col[j][a[i][j]]++;
        }
    }

    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans += ((1LL<<row[i][0])-1);
        ans += ((1LL<<row[i][1])-1);
    }
    for(int j=1; j<=m; j++){
        ans += ((1LL<<col[j][0])-1);
        ans += ((1LL<<col[j][1])-1);
    }
    ans -= (n*m);

    cout<<ans<<endl;

    return 0;
}
