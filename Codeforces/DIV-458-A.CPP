#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1005];
int main()
{
    int n; cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    sort(a+1, a+n+1);

    ll ans = -10000000;

    for(int i=n; i>=1; i--)
    {
        double x = a[i];
        double sq = sqrt(x);
        ll p = sq;
        ll pp = p*p;

        if(pp!=a[i])
        {
            ans = a[i];
            break;
        }
    }

    //printf("%I64d\n",ans);
    cout << ans << endl;

    //main();

    return 0;
}
