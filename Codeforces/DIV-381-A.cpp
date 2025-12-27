#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,a,b,c;

    while(cin>>n>>a>>b>>c)
    {
        ll k=n%4;
        ll ans=0;

        if(k==0)
        {
            ans = 0;
        }
        else if(k==1)
        {
            ans = min(a*3,min(a+b,c));
        }
        else if(k==2)
        {
            ans = min(a*2,min(b,c*2));
        }
        else
        {
            ans = min(a,min(b+c,c*3));
        }

        cout << ans << endl;
    }

    return 0;
}
