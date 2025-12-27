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
int main()
{
    factors.clear();
    divisors.clear();

        primeFactors(n);
        setDivisors(1,0);   // divisors of n
        divisors.push_back(1);
        sort(divisors.begin(),divisors.end());
}
