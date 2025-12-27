#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n; scanf("%lld",&n);
    ll ans = (n/3)+(n%3!=0);
    printf("%lld\n",ans);
    //main();
    return 0;
}

