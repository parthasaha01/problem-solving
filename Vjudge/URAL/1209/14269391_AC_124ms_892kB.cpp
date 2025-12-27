#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>vv;
int main()
{
    ll v = 1;
    for(ll i=0; i<=10000000; i++){
        v+=i;
        if(v>(1LL<<31LL))break;
        vv.push_back(v);
    }

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll k; scanf("%lld",&k);
        int flag = 0;
        int lo = 0,hi = vv.size()-1;

        while(lo<=hi)
        {
            int md = (lo+hi)/2;
            if(vv[md]==k){
                flag = 1;
                break;
            }
            else if(vv[md]<k)
            {
                lo=md+1;
            }
            else
            {
                hi = md-1;
            }
        }

        if(ks<tt)printf("%d ",flag);
        else printf("%d\n",flag);
    }
    return 0;
}
