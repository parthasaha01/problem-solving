#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long
ll sum[mx+5],phi[mx+5],res[mx+5];
void totient()
{
    for(int i=1; i<=mx; i++)phi[i]=i;
    for(int i=2; i<=mx; i++){
        if(phi[i]==i){
            for(int j=i; j<=mx; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}
void precalculation()
{
    for(int d=1; d<=mx/2; d++)
        for(int i=2; i*d<=mx; i++)
            res[i*d] += d*phi[i];

    for(int i=1; i<=mx; i++)
        sum[i]=sum[i-1]+res[i];
}
int main()
{
    totient();
    precalculation();

    ll n;
    while(scanf("%lld",&n) && n)
    {
        printf("%lld\n",sum[n]);
    }
    return 0;
}
