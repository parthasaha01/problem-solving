#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;

    for(int ks=1; ks<=t; ks++)
    {
        double n;
        cin>>n;
        double ans=0;
        ll res=0;

        if((int)n%2==0)
        {
            ans=round((n*n)/48.0);
            res=ans;
            res+=n/4;
        }
        else
        {
            ans=round(((n+3)*(n+3))/48.0);
            res=ans;
        }

        cout << "Case "<<ks<<": "<<res<<endl;
    }

    return 0;
}
