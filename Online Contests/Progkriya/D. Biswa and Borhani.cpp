#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin>>tt;
    while(tt--)
    {
        ll n; cin>>n;
        if(n==0){
            cout << 0 << endl;
            continue;
        }
        ll ans = 1;
        ll v = 1;
        ll tot=1;
        while(tot<n)
        {
            ans++;
            v*=3;
            tot+=v;
        }
        cout << ans << endl;
    }
    return 0;
}
