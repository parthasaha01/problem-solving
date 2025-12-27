#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long
int ar[mx+5];
vector<int>factor;
void sieve()
{
    for(int i=1; i<=mx; i+=2) ar[i] = i;
    for(int i=2; i<=mx; i+=2) ar[i] = 2;

    for(ll i=3; i<=mx; i+=2){
        if(ar[i]==i){
            for(ll j=i*i; j<=mx; j+=2*i){
                ar[j] = i;
            }
        }
    }
}
int main()
{
    sieve();

    int n;
    while(scanf("%d",&n) && n)
    {
        if(n==1){
            printf("1 = 1\n");
            continue;
        }
        if(n==-1){
            printf("-1 = -1 x 1\n");
            continue;
        }
        int m=n;
        if(n<0) n = -n;
        factor.clear();
        while(n!=1){
            factor.push_back(ar[n]);
            n /= ar[n];
        }
        sort(factor.begin(),factor.end());
        if(m<0) printf("%d = -1 x %d",m,factor[0]);
        else printf("%d = %d",m,factor[0]);
        for(int i=1; i<factor.size(); i++){
            printf(" x %d",factor[i]);
        }
        printf("\n");
    }
    return 0;
}
