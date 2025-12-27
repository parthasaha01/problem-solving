#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vv;
int main()
{
    ll n; scanf("%I64d",&n);

    for(ll d=0; d<=100; d++)
    {
        ll xx = n-d;
        if(xx<0)continue;

        ll dg=0;
        ll yy = xx;
        while(yy!=0)
        {
            ll r = yy%10;
            yy /= 10;
            dg+=r;
        }

        dg += xx;

        if(dg==n)
        {
            vv.push_back(xx);
        }
    }

    ll sz = vv.size();

    if(sz==0)
    {
        printf("0\n");
    }
    else
    {
        sort(vv.begin(),vv.end());

        printf("%I64d\n",sz);

        for(ll i=0; i<sz; i++)
        {
            if(i==sz-1)printf("%I64d\n",vv[i]);
            else printf("%I64d ",vv[i]);
        }
    }

    //vv.clear();
    //main();

    return 0;
}
