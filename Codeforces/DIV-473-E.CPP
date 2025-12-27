#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    while(cin>>n)
    {
        ll ans = 0;
        ll cur = 2;
        ll v = 1;
        while(1)
        {
            ll x = n/cur;
            ll r = n%cur;
            if(r>v)x++;
            if(x<=0)break;
            ans += (x*v);
            cur *= 2;
            v *= 2;
        }

        cout << ans << endl;
    }
    return 0;
}

