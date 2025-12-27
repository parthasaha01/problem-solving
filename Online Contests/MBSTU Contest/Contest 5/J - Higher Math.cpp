#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;

    ll lhs,rhs;
    ll a[3];

    for(int kase=1; kase<=t; kase++)
    {
        cin >> a[0] >> a[1] >> a[2];

        sort(a,a+3);

        lhs = (a[0]*a[0]) + (a[1]*a[1]);
        rhs = a[2]*a[2];

        if(lhs==rhs)
            cout << "Case " << kase << ": yes" << endl;
        else
            cout << "Case " << kase << ": no" << endl;
    }

    return 0;
}
