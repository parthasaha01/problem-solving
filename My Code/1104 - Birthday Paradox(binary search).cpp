#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        double dn = (double)n;

        int lo = 1;
        int hi = n+1;
        int ans = 0;
        double bb = (dn-1.0)/dn;

        while(lo<=hi)
        {
            ll md = (lo+hi)/2;
            ll pw = (md*(md-1))/2;
            double q = pow(bb,pw);
            double p = 1.0-q;
            //printf("lo=%d hi=%d md=%d q=%.2lf p=%.2lf\n",lo,hi,md,q,p);

            if(p>=0.5){
                hi=md-1;
                ans = md;
            }
            else{
                //ans = md;
                lo=md+1;
            }

           printf("lo=%d hi=%d md=%lld pw=%lld bb=%0.6lf q=%.6lf p=%0.6lf ans=%d\n",lo,hi,md,pw,bb,q,p,ans);
        }

        printf("Case %d: %d\n",ks,ans);
    }
    return 0;
}

