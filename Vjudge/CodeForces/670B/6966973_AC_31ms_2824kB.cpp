#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[100005];
int main()
{
    ll n,k;

    while(scanf("%I64d%I64d",&n,&k)==2)
    {
        for(ll i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
        }

        ll b=1;
        ll e=n;
        ll val;

        while(b<=e)
        {
            ll m=(b+e)/2;
            ll midu = (m*(m+1))/2;
            ll midl = ((m*(m-1))/2)+1;

            if(k>=midl && k<=midu){
                val=m;
                break;
            }
            else if(k>midu)
            {
                b=m+1;
                //val=b;
            }
            else if(k<midl)
            {
                e=m-1;
                //val=e;
            }
        }

        ll lb=((val*(val-1))/2)+1;
        ll ub=(val*(val+1))/2;

        ll indx=(k-lb)+1;

        printf("%I64d\n",a[indx]);
    }

    return 0;
}
