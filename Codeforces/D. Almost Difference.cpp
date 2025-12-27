#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>mp;
ll a[200005];
int main()
{
    ll n; scanf("%I64d",&n);

    for(int i=1; i<=n; i++){
        scanf("%I64d",&a[i]);
    }

    ll ans = 0;

    ll gun=n-1;
    ll p = 1;
    for(int k=1; k<=(n/2); k++)
    {
        ans -= (gun*a[p]);
        ans += (gun*a[n-p+1]);
        p++;
        gun-=2;
        //cout << (gun*a[p]) << " " << (gun*a[n-p+1]) << endl;
    }

    //printf("ans=%I64d\n",ans);

    for(int i=1; i<=n; i++)
    {
        ll v = a[i];
        v--;
        ans -= (mp[v]);
        v+=2;
        ans += (mp[v]);
        mp[a[i]]++;
    }

    printf("%I64d\n",ans);

    return 0;
}
