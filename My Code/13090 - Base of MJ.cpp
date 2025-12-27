#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    long long int BMAX,D,T,res;

    scanf("%lld",&T);

    for(ll test=1; test<=T; test++)
    {
        scanf("%lld %lld",&BMAX,&D);

        res=(BMAX-1)/D;

        printf("Case %lld: %lld\n",test,res);
    }

    return 0;
}
