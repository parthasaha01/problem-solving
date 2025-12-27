#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[20];
ll LCM(ll mask)
{
    ll lcm=1;
    int i=0;
    while(mask!=0)
    {

        int r = mask%2;
        if(r==1){
            ll gcd = __gcd(lcm,a[i]);
            lcm = (lcm*a[i])/gcd;
            if(lcm>n)return n+1;
        }
        mask /= 2;
        i++;
    }
    return lcm;
}
ll solve()
{
    ll cnt=0;
    for(ll mask=1; mask<=(1<<k)-1; mask++){

        ll bit = __builtin_popcountll(mask);
        ll lcm = LCM(mask);

        if(bit%2==1)cnt+=(n/lcm);
        else cnt-=(n/lcm);

    }

    return n-cnt;
}
int main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
        for(int i=0; i<k; i++)scanf("%d",&a[i]);

        ll ans = solve();
        printf("%lld\n",ans);
    }
    return 0;
}

