#include<bits/stdc++.h>
using namespace std;
#define mx 500005
#define ll long long
ll a[mx],sum[mx],tot=0,fst,scd;
vector<int>v[2];
int n;
int fun(int p)
{
    int cnt = -1;
    int lo = 0, hi = v[1].size()-1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(v[1][md]>p){
            cnt = md;
            hi = md-1;
        }
        else{
            lo = md+1;
        }
    }

    if(cnt==-1)return 0;
    return (int)v[1].size()-cnt;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>a[i];
        tot+=a[i];
    }

    if(((abs(tot)%3) != 0) || n<3){
        cout << 0 << endl;
        return 0;
    }

    fst = tot/3;
    scd = fst+fst;

    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1]+a[i];
    }

    for(int i=1; i<n-1; i++){
        if(sum[i]==fst)v[0].push_back(i);
    }

    for(int i=2; i<n; i++){
        if(sum[i]==scd)v[1].push_back(i);
    }

    ll ans = 0;
    for(int i=0; i<v[0].size(); i++)
    {
        int p = v[0][i];
        ans += fun(p);
    }

    cout << ans << endl;

    return 0;
}
