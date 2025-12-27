#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000009LL
char s[100005];
ll bigmod ( ll b, ll p, ll m )
{
    ll res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 )
            res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1LL;
    }
    return res;
}

int main()
{
    ll n,a,b,k;
    scanf("%I64d %I64d %I64d %I64d",&n,&a,&b,&k);
    //printf("%I64d %I64d %I64d %I64d\n",n,a,b,k);
    scanf("%s",&s);
    // printf("%s\n",s);
    ll ans = 0;

    ll d = (n+1)/k;



    if(b<a)
    {
        ll ak = bigmod(a,k,MOD);
        ll bk = bigmod(b,k,MOD);

        ll ibk = bigmod(bk,MOD-2,MOD);
        ll bak = ak*ibk;
        bak%= MOD;

        printf("bk=%lld ak=%lld ibk=%lld bak=%lld\n",bk,ak,ibk,bak);

        ll hr = bak-1;
        if(hr<0)
        {
            hr = (hr+MOD)%MOD;
        }

        ll bakd = bigmod(bak,d,MOD);
        ll lb = bakd-1;
        if(lb<0)
        {
            lb = (lb+MOD)%MOD;
        }

        ll ihr = bigmod(hr,MOD-2,MOD);
        ll val = lb*ihr;
        val %= MOD;
        printf("bakd=%lld lb=%lld hr=%lld ihr=%lld val=%lld\n",bakd,lb,hr,ihr,val);
        for(ll i=k-1; i>=0; i--)
        {
            ll xa = bigmod(a,k-i-1,MOD);
            ll xb = bigmod(b,k-i-1,MOD);

            ll ixb = bigmod(xb,MOD-2,MOD);
            ll x = xa*ixb;
            x %= MOD;

            ll cnt = x*val;
            cnt %= MOD;

            if(s[i]=='-')
            {
                ans -= cnt;
                if(ans<0)
                {
                    ans = (ans+MOD)%MOD;
                }
                ans %= MOD;
            }
            else
            {
                ans += cnt;
                if(ans<0)
                {
                    ans = (ans+MOD)%MOD;
                }
                ans %= MOD;
            }
        }


    }
    else if(b>a)
    {
        ll bk = bigmod(b,k,MOD);
        ll ak = bigmod(a,k,MOD);
        ll iak = bigmod(ak,MOD-2,MOD);
        ll bak = bk*iak;
        //printf("bk=%lld ak=%lld iak=%lld bak=%lld\n",bk,ak,iak,bak);
        bak%= MOD;

        ll hr = bak-1;
        if(hr<0)
        {
            hr = (hr+MOD)%MOD;
        }

        ll bakd = bigmod(bak,d,MOD);
        ll lb = bakd-1;
        if(lb<0)
        {
            lb = (lb+MOD)%MOD;
        }

        ll ihr = bigmod(hr,MOD-2,MOD);
        ll val = lb*ihr;
        val %= MOD;

        //printf("bakd=%lld lb=%lld hr=%lld ihr=%lld val=%lld\n",bakd,lb,hr,ihr,val);

        for(ll i=0; i<k; i++)
        {
            ll xb = bigmod(b,i,MOD);
            ll xa = bigmod(a,i,MOD);
            ll ixa = bigmod(xa,MOD-2,MOD);
            ll x = xb*ixa;
            x %= MOD;

            ll cnt = x*val;
            cnt %= MOD;

            if(s[i]=='-')
            {
                ans -= cnt;
                if(ans<0)
                {
                    ans = (ans+MOD)%MOD;
                }
                ans %= MOD;

            }
            else
            {
                ans += cnt;
                if(ans<0)
                {
                    ans = (ans+MOD)%MOD;
                }
                ans %= MOD;
            }
        }
    }
    else
    {
        for(int i=0; i<k; i++)
        {
            if(s[i]=='-')
            {
                ans -= d;
                if(ans<0)
                {
                    ans = (ans+MOD)%MOD;
                }
                ans %= MOD;
            }
            else
            {
                ans += d;
                if(ans<0)
                {
                    ans = (ans+MOD)%MOD;
                }
                ans %= MOD;
            }
        }
    }

    if(a>b){
        ll bn = bigmod(b,n,MOD);
       printf("ans=%lld bn=%lld\n",ans,bn);
        ans *= bn;
        ans %= MOD;
    }
    else{
        ll an = bigmod(a,n,MOD);
        //printf("ans=%lld an=%lld\n",ans,an);
        ans *= an;
        ans %= MOD;
    }

    printf("%I64d\n",ans);

    return 0;
}
/*
74709071 801809249 753674746 18
++++++-+-+---+-+--
*/
