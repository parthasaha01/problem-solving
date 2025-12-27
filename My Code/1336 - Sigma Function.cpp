#include<bits/stdc++.h>
using namespace std;
#define i64 long long int
i64 calculate(i64 n)
{
    i64 d=1;
    i64 ans=sqrt(n);
    i64 x=n/2;
    while(x>=9)
    {
        i64 cnt=(sqrt(x)-1)/2LL;
        ans+=cnt;
        x/=4LL;
    }

    x=2;
    while(x<=n){
        x*=4LL;
        ans++;
    }

    return n-ans;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        i64 n;
        scanf("%lld",&n);
        i64 ans=calculate(n);
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
