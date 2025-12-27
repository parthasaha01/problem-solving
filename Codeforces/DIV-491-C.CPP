#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll check(ll k,ll n)
{
    ll sum = 0;
    ll minn = (n/2)+(n%2);
    while(n>0)
    {
        sum += min(n,k);
        n -= min(n,k);
        n -= (n/10);
    }

    if(sum>=minn)return 1;
    else return 0;
}
int main()
{
    //ios :: sync_with_stdio(false); cin.tie(0);
    ll n;
    while(cin>>n)
    {
        ll lo = 1, hi = n;
        ll ans = n;
        while(lo<=hi)
        {
            ll md = (lo+hi)/2;
            if(check(md,n)){
                ans = md;
                hi = md-1;
            }
            else{
                lo = md+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

