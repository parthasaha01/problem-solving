#include<bits/stdc++.h>
using namespace std;
#define mx 5000005
#define ll unsigned long long int
ll phi[mx];
bool isprime[mx];
void totientPhi()
{
    for(ll i=3; i<mx; i+=2){
        phi[i]=i;
        isprime[i]=true;
    }
    for(ll i=2; i<mx; i+=2){
        phi[i]=i/2;
        isprime[i]=false;
    }

    for(ll i=3; i<mx; i+=2)
    {
        if(isprime[i])
        {
            phi[i]=i-1;
            for(ll j=i+i; j<mx; j+=i)
            {
                phi[j]=phi[j]-(phi[j]/i);
                isprime[j]=false;
            }
        }
    }

    for(ll i=2; i<mx; i++){
        phi[i]=phi[i-1]+(phi[i]*phi[i]);
    }

}
int main()
{
    totientPhi();

    ll t;
    scanf("%llu",&t);

    for(ll kase=1; kase<=t; kase++)
    {
        ll a,b;
        scanf("%llu%llu",&a,&b);
        ll ans=phi[b]-phi[a-1];
        printf("Case %llu: %llu\n",kase,ans);
    }

    return 0;
}

/*
8
6 6
8 8
2 20
2 5000000
5000000 5000000
4000000 5000000
4999999 5000000
4999999 4999999
*/

