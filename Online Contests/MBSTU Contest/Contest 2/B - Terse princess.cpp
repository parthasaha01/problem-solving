#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v;
int main()
{
    ll n,a,b,sz,diff;
    while(cin >> n >> a >> b)
    {
        if(a==n-1 && a+b>0)
        {
            cout << "-1" << endl;
            v.clear();
            continue;
        }

        ll sum=0;
        ll val=1;
        sum+=val;
        v.push_back(val);

        for(int i=0; i<b; i++)
        {
            val = sum+1;
            v.push_back(val);
            sum += val;
        }

        diff=n-(a+b)-1;
        for(int i=0; i<diff; i++)
        {
            v.push_back(val);
            //sum+=val;
        }

        for(int i=0; i<a; i++)
        {
            val += 1;
            v.push_back(val);
        }

        sz=v.size();
        cout << v[0];
        for(int i=1; i<sz; i++)
        {
            cout << " " << v[i];
        }
        cout << endl;
        v.clear();
    }

    return 0;
}
