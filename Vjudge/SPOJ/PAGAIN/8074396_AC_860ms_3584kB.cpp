#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 65540
bool flag[mx+5];
vector<int>pr;
void sieve()
{
    pr.push_back(2);
    for(ll i=3; i<=mx; i+=2){
        if(!flag[i]){
            pr.push_back(i);
            for(ll j=i*i; j<=mx; j+=2*i)
                flag[j]=true;
        }
    }
}
bool isprime(ll n)
{
    for(int i=0;i<pr.size() && pr[i]*pr[i]<=n;i++){
        if(n%pr[i]==0)return false;
    }
    return true;
}
int main()
{
    sieve();
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n; scanf("%lld",&n);
        if(n%2==0)n++;
        while(1)
        {
            n-=2;
            bool paisi = isprime(n);
            if(paisi)break;
        }
        printf("%lld\n",n);
    }

    return 0;
}
