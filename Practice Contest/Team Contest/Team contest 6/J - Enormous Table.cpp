#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b;
    cin>>a>>b;

    ll n = (a+b)-1LL;


    if(n&1)
    {
        ll v = ((n*(n-1))/2)+1LL;
        ll ans = v + (n-a);
        cout << ans << endl;
    }
    else
    {
        ll v = ((n*(n-1))/2)+1LL;
        ll ans = v + (a-1);
        cout << ans << endl;
    }

    //main();

    return 0;
}
