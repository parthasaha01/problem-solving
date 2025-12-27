#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 10000000000007
ll f[10004];
ll bigmod(ll n,ll m)
{
    ll ans=1;
    ll k=n;
    while(m)
    {

    if(m&1)
    {
        ans*=k;
        if(ans>=mod)ans%=mod;
    }
    k*=k;
    if(k>mod)
        k%=mod;
    m>>=1;
    }
    return ans;
}
ll modinv(ll b,ll m)
{
   return  bigmod(b,m-2);
}

int main()
{
    int d,n,m,t;
    scanf("%d",&t);
    int ks=0;
    while(t--)
    {
        scanf("%d%d%d",&d,&n,&m);
        int dd=d*d;
        ll ans=0LL;
        ll ttt=1;
        for(int  i=dd-n+1;i<=dd;i++)
         ttt=(ttt*i)%mod;
         ans+=ttt;
        ll cs=dd-n;
         //cout<<ttt<<endl;
        for(int i=n+1;i<=m;i++)
        {
            if(cs==0)
                cs=1;
            ttt*=cs;
            ttt%=mod;
            ans+=ttt;
            ans%=mod;
            cs--;
        }
        ans%=mod;
        printf("Case %d: %lld\n",++ks,ans);
      //  cout<<ans<<endl;
    }
}
