#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,res,cmax,amax,amin,num,rem,rem2,rem1,ser1,ser2,sum,sum1,sum2,r1;
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%lld",&n);

        cmax=(n/3)-1;
        sum=0;

        for(int i=1; i<=cmax; i++)
        {
            r1=n-i;

            amax=n-i-(i+1);

            amin=(r1/2)+1;

            num = amax-amin+1;

            sum+=num;
        }

        res=sum;

        if(kase<t)
            printf("Case %d: %lld\n\n",kase,res);
        else
             printf("Case %d: %lld\n",kase,res);
    }

    return 0;
}

