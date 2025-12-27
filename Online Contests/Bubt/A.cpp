#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll k,n;
        scanf("%lld %lld",&k,&n);
        ll T,pn,ow,rn;
        if(k==0)
        {
            T=n;
            pn=T/3LL;
            ll rem=T-pn;
            ow=rem/3LL;
            rn=rem-ow;
            printf("Case %d:\n%lld\n%lld\n%lld\n",ks,pn,rn,ow);
        }
        else
        {
            ow=n;
            rn=ow*2LL;
            ll rem=ow+rn;
            pn=rem/2LL;
            T=pn+rem;
            printf("Case %d:\n%lld\n%lld\n%lld\n",ks,pn,rn,T);
        }
    }

    return 0;
}
