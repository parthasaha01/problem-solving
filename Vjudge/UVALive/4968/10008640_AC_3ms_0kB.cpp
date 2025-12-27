#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll G,T,A,D;
    while(scanf("%lld%lld%lld%lld",&G,&T,&A,&D))
    {
        if(G==-1&&T==-1&&A==-1&&D==-1)break;

        ll ans = 0;
        ll team = G*T;
        ans += (team*(T-1))/2;

        //cout << "ans=" << ans << endl;

        ll vv = (G*A)+D;
        ll x=1,nd=0;
        while(1)
        {
            if(x>=vv){
                nd = x-vv;
                break;
            }
            x*=2;
        }

        ll nc = (G*A)+nd+D;

        ans += (nc-1);

        printf("%lld*%lld/%lld+%lld=%lld+%lld\n",G,A,T,D,ans,nd);
    }
}
