#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
#define ll long long int
#define mod 1000000007
ll fac[mx+5];

void factorial()
{
    fac[0]=1;
    for(ll i=1; i<=mx; i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
}
ll bigmod(ll b,ll p)
{
    ll res=1;
    if(p==1)
    {
        return b%mod;
    }
    if(p%2==0)
    {
        res = bigmod(b,p/2)%mod;
        res=((res%mod)*(res%mod))%mod;
    }
    else
    {
        res = ((bigmod(b,p-1)%mod)*(b%mod))%mod;
    }
    return res%mod;
}
int main()
{
    factorial();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n;
        scanf("%lld",&n);

        if(n==1)
        {
            printf("Case %d: 1\n",ks);
            continue;
        }

        ll ans=2;
        for(ll i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
            {
                ll d=i;
                ll dv=n/d;

                ll lob=fac[n];
                ll hor=bigmod(fac[d],dv);
                hor = ((hor%mod)*(fac[dv]%mod))%mod;
                hor=bigmod(hor,mod-2);
                ll rs = ((lob%mod)*(hor%mod))%mod;
                ans += rs;
                //cout << "d=" << d << " rs=" << rs << endl;
                ans%=mod;

                if(d==dv)
                    continue;

                lob=fac[n];
                hor=bigmod(fac[dv],d);
                hor = ((hor%mod)*(fac[d]%mod))%mod;
                hor=bigmod(hor,mod-2);
                rs = ((lob%mod)*(hor%mod))%mod;
                ans += rs;
                //cout << "dv=" << dv << " rs=" << rs << endl;
                ans%=mod;
            }
        }

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
