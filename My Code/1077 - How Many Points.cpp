#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll ax,ay,bx,by;
        scanf("%lld %lld %lld %lld",&ax,&ay,&bx,&by);
        ll x = abs(ax-bx);
        ll y = abs(ay-by);

        ll ans = __gcd(x,y)+1;
        printf("Case %d: %lld\n",ks,ans);
    }
    return 0;
}
