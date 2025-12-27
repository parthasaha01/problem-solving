#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    long long n,ans;

    while(cin>>n)
    {
        ll ans=0;
        ll a = 2;
        ll b = 1;
        while(a<=n)
        {
            ans++;
            ll temp = a;
            a = a + b;
            b = temp;
        }
        cout << ans << endl;
    }
    return 0;
}

