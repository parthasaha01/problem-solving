#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll ans = 0;
    ll n; cin>>n;

    ll cur = 1;
    while(cur<=n)
    {
        ans++;
        cur*=2;
        if(cur>n)break;
    }

    cout << ans << endl;

    //main();

    return 0;
}
