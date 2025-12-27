#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000005
bool flag[mx+5];
vector<ll>pr;
ll ss,ff;
void sieve()
{
    pr.push_back(2);

    for(ll i=3; i<=mx; i+=2)
    {
        if(!flag[i]){
            pr.push_back(i);
            for(ll j=i*i; j<=mx; j+=(i+i)){
                flag[j]=true;
            }
        }
    }
}
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll divisor(ll n)
{
    ll ans=1;
    ll sz = pr.size();

    for(int i=0; i<sz && pr[i]*pr[i]<=n; i++)
    {
        ll cnt=0;
        while(n%pr[i]==0)
        {
            cnt++;
            n/=pr[i];
        }

        ans*=(cnt+1);
    }

    if(n>1)ans*=2;

    return ans;
}
int main()
{
    sieve();

    while(scanf("%lld%lld",&ss,&ff)==2)
    {
        ll gd  = gcd(ss,ff);

        ll ans = divisor(gd);

        ans--;

        if(gd==ss || gd==ff)ans--;

        if(ans<=0)printf("-1\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
