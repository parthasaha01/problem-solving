#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b;
    while(cin>>a>>b)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        ll p,q;
        p = (2*x) + y;
        q = y + (3*z);

        ll ans = 0;
        if(p>a){
            ans += (p-a);
        }
        if(q>b){
            ans += (q-b);
        }

        cout << ans << endl;
    }

    return 0;
}
