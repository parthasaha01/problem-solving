#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1000001
double a[mx];
void precalc()
{
    a[0]=0;
    for(int i=1; i<=mx; i++)
    {
        a[i] = a[i-1] + log10(i);
    }

    return;
}
ll count_digit(ll n, ll base)
{
    if(n==0)
        return 1;

    double sum = a[n]/log10(base);

    return floor(sum) + 1;
}
int main()
{
    precalc();

    int t;
    
    scanf("%lld",&t);

    ll n,base,cnt;

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%lld %lld",&n,&base);

        cnt = count_digit(n,base);

        printf("Case %d: %lld\n",kase,cnt);
    }

    return 0;
}
