#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    while(cin>>n>>k)
    {
        ll ans= 0;

        if(k==1)
        {
            ans = n;
        }
        else
        {
            ll x;
            for(x=1; x<=n; x*=2)
            {
            }

            x--;

            ans = x;
        }

        cout << ans << endl;
    }

    return 0;
}

