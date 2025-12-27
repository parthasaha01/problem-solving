#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    while(scanf("%lld",&n)==1)
    {
        ll sum = (n*(n+1))/2;

        int m; scanf("%d",&m);

        for(int i=1; i<=m; i++){
            ll x; scanf("%lld",&x);
            sum -= x;
        }
        printf("%lld\n",sum);
    }
    return 0;
}

