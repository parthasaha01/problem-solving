#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll a[300005],b[300005];
bool cmp(ll x,ll y){return x>y;}

ll bigmod(ll b,ll p)
{
    ll res=1;
    if(p==1) return b%mod;
    if(p%2==0){
        res = (bigmod(b,p/2)%mod);
        res = ((res%mod)*(res%mod))%mod;
    }
    else res = ((bigmod(b,p-1)%mod)*(b%mod)%mod);

    return res%mod;
}

int main()
{
    ll n; scanf("%I64d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        b[i]=a[i];
    }

    sort(a+1,a+n+1);
    sort(b+1,b+n+1,cmp);

    ll x,vv,uu,ww;
    x = n-1;

    ll ans = 0;
    ll id = 1;

    while(x>0)
    {
        vv = bigmod(2,x);
        vv--;
        uu = ((vv%mod)*(b[id]%mod))%mod;
        ans += uu;
        if(ans>=mod)ans %= mod;

        ww =  ((vv%mod)*(a[id]%mod))%mod;
        ans -= ww;
        if(ans<0)ans=(ans+mod)%mod;

        //printf("x=%I64d vv=%I64d uu=%I64d ww = %I64d ans=%I64d\n",x,vv,uu,ww,ans);
        if(ans>=mod)ans %= mod;
        x--;
        id++;
    }

    printf("%I64d\n",ans);

    return 0;
}
