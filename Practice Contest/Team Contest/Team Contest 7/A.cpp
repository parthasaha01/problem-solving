#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define ll long long
#define FastIO ios_base::sync_with_stdio(0)
ll bigmod(ll b,ll p)
{
    ll res = 1%MOD, x = b%MOD;
    while(p)
    {
        if(p&1) res=(res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1LL;
    }
    return res;
}
int main()
{
    FastIO;
    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cout << "Case " << ks << ":" << endl;
        ll n,m; cin>>n>>m;

        for(int k=1; k<=m; k++)
        {
            string s; cin>>s;
            ll sz = s.size();

            if(sz>n){
                ll ans = 0;
                cout << ans << endl;
            }
            else{
                ll ans = (n-sz+1)*bigmod(26,n-sz);
                ans %= MOD;
                cout << ans << endl;
            }
        }

    }
    return 0;
}
