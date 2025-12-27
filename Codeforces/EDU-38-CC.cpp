#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll x;
        scanf("%I64d",&x);

        if(x==0)
        {
            printf("1 1\n");
            continue;
        }

        ll sq;
        sq = sqrt((double)x);

        bool flag = false;
        ll n,m;

        for(ll uu=sq+1; uu<=40000; uu++)
        {
            ll sum = uu*uu;
            ll lo = 2;
            ll hi = uu;

            while(lo<=hi)
            {
                ll vv = (lo+hi)/2;

                ll zero = (uu/vv)*(uu/vv);
                ll one = sum - zero;
                if(one==x)
                {
                    flag = true;
                    n = uu;
                    m = vv;
                    break;
                }
                else if(one>x)hi=vv-1;
                else lo = vv+1;
            }

            if(flag==true)break;

        }

        if(flag)printf("%I64d %I64d\n",n,m);
        else printf("-1\n");
    }

    return 0;
}

