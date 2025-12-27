#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t,flag;
    scanf("%d",&t);
    ll w,n,d,a,b;

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%lld",&w);
        flag=0;

        if(w%2==0)
        {
            n=w;
            d=1;
            while(n!=0)
            {
                n=n/2;
                d=d*2;
                if(n%2==1)
                {
                    flag=1;
                    a=n;
                    b=d;
                    break;
                }
            }
        }

        if(flag)
        {
            printf("Case %d: %lld %lld\n",kase,a,b);
        }
        else
        {
            printf("Case %d: Impossible\n",kase);
        }
    }

    return 0;
}
