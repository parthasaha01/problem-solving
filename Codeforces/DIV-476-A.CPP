#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005

int main()
{
    ll k,n,s,p;
    while(cin>>k>>n>>s>>p)
    {
        ll ss = (n/s);
        if(n%s!=0)ss++;
        ll sum = k*ss;
        ll ans = sum/p;
        if(sum%p!=0)ans++;
        cout << ans << endl;

    }

    return 0;
}
