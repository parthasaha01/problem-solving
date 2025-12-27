#include<bits/stdc++.h>
using namespace std;
#define ll long long
double eps=0.00000001;
ll xx[5];
int main()
{
    ll a,b,c,d;
    int ks=0;
    while(scanf("%lld%lld%lld%lld",&xx[0],&xx[1],&xx[2],&xx[3])==4)
    {
        sort(xx,xx+4);
        ll ans = xx[2]+xx[3];
        //ll sum = (a*a)+(b*b)+(c*c)+(d*d);
        //double tot = (double)sum;
        //double sq = sqrt(tot);
        //ll si = (ll)sq;
        //ll ss = si*si;

        printf("Case %d: %lld\n",++ks,ans);


//        if(ss==sum)
//        {
//            printf("Case %d: %lld\n",++ks,ans);
//        }
//        else
//        {
//            si++;
//            printf("Case %d: %lld\n",++ks,ans);
//        }
    }

    return 0;
}
