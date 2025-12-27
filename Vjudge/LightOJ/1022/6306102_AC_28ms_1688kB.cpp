#include<bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
int main()
{
    int t;
    double r,a;

    cin >> t;

    for(int kase=1; kase<=t; kase++)
    {
        cin >> r;
        a = r*r*(4-pi); //a=((2*r)*(2*r)) - (pi*r*r);
        printf("Case %d: %.2lf\n",kase,a);
    }

    return 0;
}

