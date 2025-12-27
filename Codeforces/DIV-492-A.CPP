#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[] = {1,5,10,20,100};
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    ll n; cin>>n;
    ll ans = 0;

    for(int i=4; i>=0 && n>0; i--)
    {
        if(n>=a[i]){
            ans += (n/a[i]);
            n %= a[i];
        }
    }

    cout << ans << endl;

    main();

    return 0;
}
