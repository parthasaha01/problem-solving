#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b,m,mb;
ll fun(ll x,ll y)
{
    ll nx = (x*(x+1))/2;
    ll ny = (y*(y+1))/2;

    ll ans = (nx*(y+1)) + (ny*(x+1));

    return ans;
}
int main()
{
    cin >> m >> b;
    mb = m*b;

    ll maxx = 0;

    for(ll i=1; i<=b; i++)
    {
        ll x = m*i;
        ll y = (mb-x)/m;

        ll ans = fun(x,y);

        maxx = max(maxx,ans);
    }

    cout << maxx << endl;

    return 0;
}
