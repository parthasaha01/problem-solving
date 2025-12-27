#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll y; scanf("%lld",&y);

        ll ans = 0;

        for(ll b=1; b<=700; b++)
        {
            ll yy = y-b;
            if(yy<=0)break;

            ll cnt = sqrt(yy);

            ans += cnt;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
