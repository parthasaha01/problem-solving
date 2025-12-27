#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll l, ll r)
{
    //if(r==0)return 0;
    if(l==r)return l;

    ll n1=1,n2=1;
    if(l>0) n1 = (ll)log2(l) + 1;
    if(r>0) n2 = (ll)log2(r) + 1;

    if(((1LL<<n2)-1)==r) return r;
    if(n1<n2) return ((1LL<<(n2-1))-1);

    ll ans = 0;

    for(ll i=n1-1; i>=0; i--)
    {
        if((l&(1LL<<i))==0 && (r&(1LL<<i))!=0){
            int f = 1;
            for(ll j=i-1; j>=0; j--){
                if((r&(1LL<<j))==0){
                    f = 0;
                    break;
                }
            }

            if(f) ans = ans|(1LL<<i);

            for(ll j=i-1; j>=0; j--){
                ans = ans|(1LL<<j);
            }

            return ans;
        }

        if((l&(1LL<<i))!=0 && (r&(1LL<<i))!=0 ){
            ans = ans|(1LL<<i);
        }
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin>>tt;
    while(tt--)
    {
        ll l,r; cin>>l>>r;
        if(l>r)swap(l,r);
        ll ans = solve(l,r);
        cout << ans << endl;
    }
    return 0;
}
