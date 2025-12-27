#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define mx 5000005
ll lp[mx+5],ta[mx+5],ff[mx+5],dp[mx+5];
ll tt,lf,rg;
vector<int>pr;
void sieve()
{
    //for(ll i=1; i<=mx; i++) lp[i] = 0;

    for(ll i=2; i<=mx; i++)
    {
        if(lp[i]==0)
        {
            lp[i]=i;
            pr.push_back(i);
        }

        int sz = pr.size();

        for(ll j=0; (j<sz)&&(pr[j]<=lp[i])&&(i*pr[j])<=mx; j++)
        {
            lp[i*pr[j]] = pr[j];
        }
    }
}
ll fun(ll n)
{
    if(n==1)return 0;
    if(n==2)return 1;
    if(n==3)return 3;

    if(dp[n]!=-1)return dp[n];

    ll minn = 10000000000000000;
    for(ll i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            ll j = n/i;
            ll ret1 = 0, ret2 = 0;
            if(i==1)ret1 = 1000000000000000;
            else ret1 = (((j*((i*(i-1))/2))%mod) + (fun(j)%mod))%mod;

            ret2 = (((i*((j*(j-1))/2))%mod) + (fun(i)%mod))%mod;

            minn = min(minn,min(ret1,ret2));
        }
    }

    return dp[n] = minn;
}
int main()
{
    //sieve();
    memset(dp,-1,sizeof(dp));

    while(cin >> tt >> lf >> rg)
    {

        ta[0]=1;
        for(ll i=1; i<=rg-lf; i++)
        {
            ta[i] = ta[i-1]*tt;
            ta[i] %= mod;
        }

//        for(ll i=1; i<=100; i++)
//        {
//            printf("i=%lld lp[i]=%lld\n",i,lp[i]);
//        }

        //ff[0]=0; ff[1]=0; ff[2]=1; ff[3]=3; ff[4]=3;

        for(ll i=lf; i<=rg; i++)
        {
//            ll v = i;
//            ll cnt=0;
//            while(v>1)
//            {
//                ll x = lp[v];
//                ll u = ((x*(x-1))/2) * (v/lp[v]);
//                cnt += u;
//                v = v/lp[v];
//            }

            ff[i]=fun(i);
        }

        ll ans=0;
        for(ll i=lf; i<=rg; i++)
        {
            ll cnt = ta[i-lf]*ff[i];
            cnt %= mod;
            ans += cnt;
            ans %= mod;
        }

        cout << ans << endl;
        //cout << ff[rg] << endl;

    }
    return 0;
}


