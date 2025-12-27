#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[10005],b[10005];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);
        ll sum=0;

        for(int i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        for(int i=0; i<m; i++)
        {
            scanf("%lld",&b[i]);
            sum+=b[i];
        }

        ll mx=max(a[n-1],b[m-1]);
        ll ans=sum-mx;

        printf("Case %d: %lld\n",ks,ans);

    }

    return 0;
}
