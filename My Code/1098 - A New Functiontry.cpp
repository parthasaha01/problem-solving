#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll CSOD(ll n)
{
    ll ans=0;
    ll sq=sqrt((double)n);

    for(ll i=2; i<=sq; i++)
    {
        ll j = n/i;
        ll ans1 = i*(j-i);
        ll ans2 = (j*(j+1))/2;
        ll ans3 = (i*(i-1))/2;
        ll ans4=ans2-ans3;
        ans+=ans1+ans4;
        printf("i=%lld j=%lld ans1=%lld ans2=%lld ans3=%lld ans4=%lld ans1+ans4=%lld ans=%lld\n",i,j,ans1,ans2,ans3,ans4,ans1+ans4,ans);
    }

    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n;
        scanf("%lld",&n);
        ll ans=CSOD(n);
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}

