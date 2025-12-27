#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n; scanf("%llu",&n);
         n *= 10;

         if(n%9==0)
         {
             ll x = n/9;
             printf("Case %d: %llu %llu\n",ks,x-1,x);
         }
         else
         {
             ll x = n/9;
             printf("Case %d: %llu\n",ks,x);
         }
    }

    return 0;
}
