#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll g;
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%lld",&g);
        printf("Case %d: %lld\n",ks,g/2);
    }

    return 0;
}
