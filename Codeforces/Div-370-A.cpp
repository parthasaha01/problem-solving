#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
ll a[mx+5],b[mx+5];
int main()
{
    ll n;
    while(scanf("%I64d",&n)==1)
    {
        for(ll i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
        }

        for(ll i=1; i<n; i++){
            b[i]=a[i]+a[i+1];
        }
        b[n]=a[n];

        for(ll i=1; i<n; i++)
        {
            printf("%I64d ",b[i]);
        }
        printf("%I64d\n",b[n]);
    }

    return 0;
}
