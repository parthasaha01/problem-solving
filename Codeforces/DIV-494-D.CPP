#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,a[200005],cnt[32];
map<int,int>mp;
int solve(int v)
{
    int ans = 0;
    for(int i=30; i>=0; i--)
    {
        int x = (1<<i);
        if(cnt[i]<=0)continue;
        if(x>v)continue;

        int r = v/x;
        if(cnt[i]>=r){
            ans += r;
            v -= (r*x);
        }
        else{
            ans += cnt[i];
            v -= (cnt[i]*x);
        }

        if(v==0)return ans;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    for(ll i=0; i<=30; i++) mp[1<<i] = i;

    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        cnt[mp[a[i]]]++;
    }

    while(q--)
    {
        int v; cin>>v;
        int ans = solve(v);
        cout << ans << endl;
    }
    return 0;
}
