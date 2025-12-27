#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[20];
ll LCM(ll mask)
{
    ll lcm=1;
    int i=0;
    //string s;
    //ll ms=mask;
    while(mask!=0)
    {

        int r = mask%2;
        //s+=r+'0';
        if(r==1){
            ll gcd = __gcd(lcm,a[i]);
            lcm = (lcm*a[i])/gcd;
            if(lcm>n)return n+1;
        }
        mask /= 2;
        i++;
    }
    //reverse(s.begin(),s.end());
    //cout << ms << " " << s << " " << lcm << endl;
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
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d%d",&n,&k);
        for(int i=0; i<k; i++)scanf("%d",&a[i]);

        ll ans = solve();
        printf("Case %d: %lld\n",ks,ans);
    }
    return 0;
}

