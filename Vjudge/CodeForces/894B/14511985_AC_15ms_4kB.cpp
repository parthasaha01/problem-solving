#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
ll BIGMOD(ll b,ll p)
{
    ll res=1%MOD, x=b%MOD;
    while(p){
        if(p&1) res = (res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1;
    }
    return res%MOD;
}
ll solve(ll n,ll m,ll k)
{
    if((k==-1)&&((n&1)!=(m&1)))return 0;
    return BIGMOD(BIGMOD(2,n-1),m-1);
}
int main()
{
    ll n,m,k; cin>>n>>m>>k;
    cout<<solve(n,m,k)<<endl;
    return 0;
}
