#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll modulas(ll num)
{
    if(num>0) return num%mod;
    if(num==0) return 0;

    num = (-1)*num;
    ll mm = num%mod;
    if(mm==0) return 0;
    return mod-mm;
}
ll bigmod(ll b,ll p)
{
    ll res=1;
    if(p==1){
        return b%mod;
    }

    if(p%2==0){
        res = (bigmod(b,p/2)%mod);
        res = ((res%mod)*(res%mod))%mod;
    }
    else{
        res = ((bigmod(b,p-1)%mod)*(b%mod)%mod);
    }
    return res%mod;

}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n,b; scanf("%lld %lld",&n,&b);
        ll a;
        if(n%2==1) a = b;
        else a = (b*b)%mod;

        ll bb = (b*b)%mod;
        ll y = (n+1)/2;

        ll hor = bb-1;
        hor %= mod;
        hor = bigmod(hor,mod-2);

        ll lob = a*(bigmod(bb,y)-1);
        lob %= mod;

        ll p = ((lob%mod) * (hor%mod))%mod;

        lob = p-y;
        lob = modulas(lob);

        hor = b-1;
        hor %= mod;
        hor = bigmod(hor,mod-2);

        ll ans = ((lob%mod) * (hor%mod))%mod;

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
