#include<bits/stdc++.h>
using namespace std;
#define i64 long long int
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        i64 n;
        scanf("%lld",&n);
        i64 odd=(int)sqrt(n)+(int)sqrt(n/2);
        i64 even=n-odd;
        printf("Case %d: %lld\n",ks,even);
    }

    return 0;
}

