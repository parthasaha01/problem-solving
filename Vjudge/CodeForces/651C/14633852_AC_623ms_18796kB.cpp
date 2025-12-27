#include<bits/stdc++.h>
using namespace std;
struct dt{
    int x,y;
}a[200005];
map< pair<int,int>, int >mp;
map<int,int>xx;
map<int,int>yy;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i].x>>a[i].y;
        mp[make_pair(a[i].x,a[i].y)]++;
        xx[a[i].x]++;
        yy[a[i].y]++;
    }

    long long ans = 0;
    for(int i=1; i<=n; i++){
        int x = a[i].x;
        int y = a[i].y;
        auto xy = make_pair(a[i].x,a[i].y);
        ans += xx[x]-mp[xy];
        ans += yy[y]-mp[xy];
        ans += mp[xy]-1;
    }
    ans/=2;

    cout<<ans<<endl;

    return 0;
}
