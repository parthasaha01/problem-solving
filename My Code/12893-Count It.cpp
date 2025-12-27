#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL fun(LL n)
{
    if(n==0) return 0;
    return fun(n/2LL)+(n%2);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n;
        scanf("%lld",&n);
        LL ans = fun(n);
        printf("%lld\n", ans);
    }

    return 0;
}
