#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200005
struct dt{
    ll l,r;
}st[mx];
ll n,ans[2*mx],a[2*mx],sum[2*mx];
map<ll,int>mp;
map<int,ll>vp;
set<ll>ss;
bool cmp(dt x,dt y)
{
    if(x.l!=y.l)return x.r < y.r;
    return x.l < y.l;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    cin>>n;

    for(int i=1; i<=n; i++){
        ll l,r; cin>>l>>r;
        if(l>r)swap(l,r);
        st[i].l = l;
        st[i].r = r;
        ss.insert(l);
        ss.insert(r+1);
    }

    sort(st+1,st+n+1,cmp);

    int k = 0;
    for(auto it=ss.begin(); it!=ss.end(); it++)
    {
        mp[(ll)*it] = ++k;
        vp[k] = (ll)*it;
    }

    for(int i=1; i<=n; i++)
    {
        ll l = st[i].l;
        ll r = st[i].r;

        a[mp[l]] += 1;
        a[mp[r+1]] -= 1;
    }

    for(int i=1; i<=k; i++){
        sum[i] += sum[i-1]+a[i];
    }

    for(int i=1; i<k; i++)
    {
        ans[sum[i]] += vp[i+1] - vp[i];
    }

    for(int i=1; i<=n; i++)
    {
        if(i<n)cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }

    return 0;
}
