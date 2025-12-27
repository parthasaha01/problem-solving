#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
ll a[mx+5];
int main()
{

    ll n,k;

    while(scanf("%I64d%I64d",&n,&k)==2)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
        }

        ll ans=0;

        for(int i=1; i<=n; i++)
        {
            ll x = a[i];

            ll rm;
            if(a[i]%k==0)
            {
                rm = a[i]/k;
            }
            else
            {
                rm = (a[i]/k)+1;
            }

            ans+=rm;
        }

        if(ans%2==0)ans/=2;
        else ans = (ans/2)+1;

        printf("%I64d\n",ans);
    }

    return 0;
}
