#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll, ll>
bool vis[1000005];
vector<ll>prime,divisors;
vector<pll>factors;
void sieve()
{
    prime.push_back(2);
    for(ll i=3; i<=1000000; i+=2){
        if(!vis[i]){
            prime.push_back(i);
            for(ll j=i*i; j<=1000000; j+=2*i){
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
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return (a/gcd(a,b))*b;
}
int main()
{
    sieve();

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll a,b,Labc;
        scanf("%lld%lld%lld",&a,&b,&Labc);

        if(Labc%a!=0||Labc%b!=0){
            printf("Case %d: impossible\n",ks);
            continue;
        }

        ll Lab,c;
        Lab=lcm(a,b);

        factors.clear();
        divisors.clear();

        primeFactors(Labc);
        setDivisors(1,0);
        divisors.push_back(1);
        sort(divisors.begin(),divisors.end());

        /*for(int i=0; i<divisors.size(); i++){
            printf("%lld ",divisors[i]);
        }
        cout << endl;*/

        for(ll i=0; i<divisors.size(); i++){
            c=divisors[i];
            if((Labc*gcd(Lab,c))/Lab==c){
                break;
            }
        }

        printf("Case %d: %lld\n",ks,c);
    }

    return 0;
}
