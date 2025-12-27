#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n,ll s1,ll v1,ll s2,ll v2)
{

}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n,s1,v1,s2,v2;
        scanf("%lld %lld %lld %lld %lld",&n,&s1,&v1,&s2,&v2);

        ll ans = solve(n,s1,v1,s2,v2);

        printf("Case #%d: %lld\n",ks,ans);
    }
    return 0;
}
