#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
int main()
{

    int tt; scanf("%d",&tt);

    while(tt--)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++)scanf("%lld",&a[i]);

        sort(a+1,a+n+1);
        ll ans=0;
        ll k=2;
        for(int i=1; i<n; i++){
            ans += (k*a[i]);
            k++;
        }

        ans += a[n];

        printf("%lld\n",ans);
    }

    return 0;
}
