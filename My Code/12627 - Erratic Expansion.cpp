#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[35];
ll fun(ll n,ll k,ll m)
{
    if(n==0 || k==0)return 0LL;
    ll md = (1LL<<(k-1));
    if(n<=md) return m*sum[k-1] + fun(n,k-1,m<<1LL);
    else return fun(n-md,k-1,m);
}
int main()
{
    sum[0] = 1;
    for(int i=1; i<=32; i++)sum[i] = sum[i-1]*3;

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        ll k,l,r;
        cin>>k>>l>>r;
        ll ans = 0;
        ans += (sum[k]-fun(r,k,1LL));
        if(l>1)ans -= (sum[k]-fun(l-1,k,1LL));
        cout << "Case " << ks << ": " << ans << endl;
    }

    return 0;
}

