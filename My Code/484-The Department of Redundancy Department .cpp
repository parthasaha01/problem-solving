#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll>vis;
map<ll,ll>fre;
vector<ll>v;
int main()
{
    ll x;

    while(cin >> x)
    {
        fre[x]++;
        if(vis[x]==0)
        {
            v.push_back(x);
            vis[x]=1;
        }
    }

    long int sz = v.size();

    for(int i=0; i<sz; i++)
    {
        cout << v[i] << " " << fre[v[i]] << endl;
    }

    v.clear();
    vis.clear();
    fre.clear();

    return 0;
}

