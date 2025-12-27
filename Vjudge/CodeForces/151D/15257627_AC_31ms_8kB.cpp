#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007LL
ll BIGMOD(ll b,ll p)
{
    ll res = 1LL%MOD, x = b%MOD;
    while(p){
        if(p&1LL)res = (res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1LL;
    }
    return res;
}
ll solve(ll n,ll m,ll k)
{
    if(k==1 || k>n)return BIGMOD(m,n);
    if(k==n){
        if(n&1)return (BIGMOD(m,(n-1)/2)*m)%MOD;
        else return BIGMOD(m,n/2);
    }
    if(k<n){
        if(k&1)return (m*m)%MOD;
        else return m%MOD;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,m,k; cin>>n>>m>>k;
    cout<<solve(n,m,k)<<endl;
    return 0;
}
