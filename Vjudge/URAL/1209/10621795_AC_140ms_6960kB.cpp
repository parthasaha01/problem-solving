#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>mp;
int main()
{
    mp[1]=1;
    ll cnt=1;
    ll sum=1;
    for(int i=1; i<=100005; i++)
    {
        sum+=cnt;
        cnt++;
        mp[sum]=1;
    }

    //cout << sum << endl;

    ll n;
    scanf("%lld",&n);

    for(int ks=1; ks<=n; ks++)
    {
        ll k;
        scanf("%lld",&k);

        if(ks==n)printf("%lld\n",mp[k]);
        else printf("%lld ",mp[k]);
    }

    return 0;
}
