#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
#define ll long long int
#define mod 1000000007
#define pll pair<ll, ll>
ll fac[mx+5];
bool vis[mx+5];
vector<ll>prime,divisors;
vector<pll>factors;
void sieve()
{
    prime.push_back(2);
    for(ll i=3; i<=mx; i+=2){
        if(!vis[i]){
            prime.push_back(i);
            for(ll j=i*i; j<=mx; j+=2*i){
                vis[j]=true;
            }
        }
    }
}
void primeFactors(ll n)
{
    ll expo=0;
    for(ll i=0; prime[i]*prime[i]<=n; i++)
    {
        expo=0;
        while(n%prime[i]==0){
            expo++;
            n/=prime[i];
        }
        if(expo>0){
            factors.push_back(make_pair(prime[i],expo));
        }
    }
    if(n>1){
        factors.push_back(make_pair(n,1));
    }
}
void setDivisors(ll n,ll i)
{
    for(ll j=i; j<factors.size(); j++){
        ll x=factors[j].first*n;
        for(ll k=0; k<factors[j].second; k++){
            divisors.push_back(x);
            setDivisors(x,j+1);
            x*=factors[j].first;
        }
    }
}
void factorial()
{
    fac[0]=1;
    for(ll i=1; i<=mx; i++){
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
}
ll modInv(ll n)
{
    ll r2=n, r1=mod;
    ll x2=1, y2=0;
    ll x1=0, y1=1;

    while(r1!=0)
    {
        ll q = r2/r1;
        ll r = r2%r1;
        ll x = x2-(q*x1);
        ll y = y2-(q*y1);

        r2=r1, r1=r;
        x2=x1, y2=y1;
        x1=x, y1=y;
    }

    ll x=x2%mod;
    if (x<0) x+= mod;
    return x;
}
ll bigmod(ll b,ll p)
{
    ll res=1;
    if(p==1){
        return b%mod;
    }
    if(p%2==0){
        res = bigmod(b,p/2)%mod;
        res=((res%mod)*(res%mod))%mod;
    }
    else{
        res = ((bigmod(b,p-1)%mod)*(b%mod))%mod;
    }
    return res%mod;
}
int main()
{
    sieve();
    factorial();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n;
        scanf("%lld",&n);

        if(n==1){
            printf("Case %d: 1\n",ks);
            continue;
        }

        factors.clear();
        divisors.clear();

        primeFactors(n);
        setDivisors(1,0);
        //divisors.push_back(1);
        //sort(divisors.begin(),divisors.end());

        ll ans=1;
        for(ll i=0; i<divisors.size(); i++)
        {
            ll d=divisors[i];
            ll lob=fac[n];
            ll hor=bigmod(fac[d],n/d);
            hor = ((hor%mod)*(fac[n/d]%mod))%mod;
            hor=modInv(hor);
            ll rs = ((lob%mod)*(hor%mod))%mod;
            //cout << "d=" << d << " rs=" << rs << endl;
            ans += rs;
            ans%=mod;
        }

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
