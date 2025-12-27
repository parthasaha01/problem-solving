#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll a,b;
    cin>>a>>b;

    while(a!=0 && b!=0)
    {
        ll bb = 2*b;
        ll aa = 2*a;

        if(a>=bb)
        {
            ll d = a/bb;
            ll v = d*bb;
            a = a-v;
        }
        else if(b>=aa)
        {
            ll d = b/aa;
            ll v = d*aa;
            b = b-v;
        }
        else
        {
            break;
        }
    }

    cout << a << " " << b << endl;

    //main();

    return 0;
}
