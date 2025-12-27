#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 10000007
ll a[6];
ll dp[10005];
ll fn(ll n)
{
    if(n<6)
        return a[n]%m;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n] = (fn(n-1)%m +fn(n-2)%m +fn(n-3)%m +fn(n-4)%m +fn(n-5)%m +fn(n-6)%m)%m;
}
int main()
{
    ll t,n;
    cin >> t;

    for(int kase=1; kase<=t; kase++)
    {
        for(int i=0; i<6; i++){
            cin >> a[i];
        }
        cin >> n;
        memset(dp,-1,sizeof(dp));
        cout << "Case " << kase << ": " << fn(n) << endl;
    }

    return 0;
}
