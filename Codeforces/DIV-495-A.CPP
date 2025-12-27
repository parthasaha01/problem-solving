#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int n,d,a[105];
vector<int>v;
set<int>s;
int possible(int p)
{
    for(int i=1; i<=n; i++)
    {
        int r = abs(a[i]-p);
        if(r<d)return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>n>>d;
    for(int i=1; i<=n; i++)cin>>a[i];

    sort(a+1,a+n+1);

    for(int i=1; i<=n; i++){
        s.insert(a[i]-d);
        s.insert(a[i]+d);
    }

    for(auto it=s.begin(); it!=s.end(); it++){
        v.push_back(*it);
    }

    int ans = 0;
    for(int i=0; i<v.size(); i++)
    {
        int p = v[i];
        if(possible(p))ans++;
    }

    cout << ans << endl;

    return 0;
}
