#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vv;
int main()
{
    ll n,k;
    cin>>n>>k;
    for(ll i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            vv.push_back(i);
            if((n/i)!=i)vv.push_back(n/i);
        }
    }

    sort(vv.begin(),vv.end());

    if(k>vv.size())cout << "-1" << endl;
    else cout << vv[k-1] << endl;

    return 0;
}
