#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    while(cin>>n)
    {
        n++;
        ll ans=0;
        if(n&1)
        {
            ans = n;
        }
        else
        {
            ans = n/2;
        }

        if(n==1)ans=0;

        cout << ans << endl;
    }
    return 0;
}
