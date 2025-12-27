#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
int main()
{
    ll n;

    while(scanf("%I64d",&n)==1)
    {
        ll sum=0;
        ll maxx=0;
        for(ll i=0; i<n; i++)
        {
            ll a;
            scanf("%I64d",&a);
            maxx=max(maxx,a);
            sum+=a;
        }

        ll res=abs(maxx-(sum-maxx))+1;

        printf("%I64d\n",res);
    }

    return 0;
}
