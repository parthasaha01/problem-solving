#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
ll fac[1000005];
void factorial(ll n)
{
    fac[0]=1;
    for(ll i=1; i<=n; i++){
        fac[i] = fac[i-1]*i;
        fac[i] %= MOD;
    }
}
ll BIGMOD(ll b,ll p)
{
    ll res=1%MOD, x=b%MOD;
    while(p){
        if(p&1) res = (res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1;
    }
    return res;
}
ll MODINVERSE(ll b)
{
    return BIGMOD(b,MOD-2);
}
ll nCr(ll n,ll r)
{
    ll lob = fac[n];
    ll hor = (fac[r]*fac[n-r])%MOD;
    ll invhor = MODINVERSE(hor);
    ll ncr = (lob*invhor)%MOD;
    return ncr;
}
int Excellent(ll v,ll a,ll b)
{
    while(v!=0){
        ll r = v%10;
        if(r!=a&&r!=b)return 0;
        v/=10;
    }
    return 1;
}
ll solve(ll a,ll b,ll n)
{
    factorial(n);
    ll ans = 0;
    for(ll r=0; r<=n; r++){
        ll digitsum = (a*r)+(b*(n-r));
        if(Excellent(digitsum,a,b)){
            ll tot = nCr(n,r);
            ans += tot;
            ans %= MOD;
        }
    }
    return ans;
}
int main()
{
    ll a,b,n; cin>>a>>b>>n;
    cout << solve(a,b,n) << endl;
    return 0;
}
