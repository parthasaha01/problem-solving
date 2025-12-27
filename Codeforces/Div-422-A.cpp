#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,b,x,ans;
    cin>>a>>b;

    x = min(a,b);

    ans = 1;

    for(ll i=1; i<=x; i++)
    {
        ans *= i;
    }

    cout << ans << endl;

    return 0;
}
