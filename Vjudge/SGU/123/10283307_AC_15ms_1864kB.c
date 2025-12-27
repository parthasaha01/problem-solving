#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    ll k;
    while(cin>>k)
    {
        ll sum=0;
        if(k==1)
        {
            cout << "1" << endl;
        }
        else if(k==2)
        {
            cout << "2" << endl;
        }
        else
        {
            ll a=1;
            ll b=1;
            ll c;
            sum=2;
            for(int i=3; i<=k; i++)
            {
                c = a+b;
                sum+=c;
                a = b;
                b = c;
            }

            cout << sum << endl;
        }
    }

    return 0;
}
