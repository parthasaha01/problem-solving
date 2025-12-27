#include<bits/stdc++.h>
using namespace std;
int n;
double xx[15005],pp[15005];
double fun(double x)
{
    double sum = 0;
    for(int i=1; i<=n; i++)
    {
        double d = abs(xx[i]-x);
        double dp = d*pp[i];
        sum += dp;
    }

    return sum;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%lf %lf",&xx[i],&pp[i]);
        }

        double lo=0.0;
        double hi=50000.0;
        double ans = 1000000000000000000.0;
        double res;

        for(int i=1; i<=200; i++)
        {
            double A = ((2*lo)+hi)/3.0;
            double B = (lo+(2*hi))/3.0;
            double av = fun(A);
            double bv = fun(B);

            if(av<=bv)
            {
                //ans = min(ans,av);
                if(av<=ans)
                {
                    res=A;
                    ans=av;
                }
                hi = B;
            }
            else
            {
                //ans = min(ans,bv);
                if(bv<=ans)
                {
                    res=B;
                    ans=bv;
                }
                lo = A;
            }
        }
        printf("%0.7lf\n",res);
        //printf("%0.5lf %lf\n",res,ans);
        //double ss = fun(5.5);
        //printf("2.500000 %lf\n",ss);
    }

    return 0;
}
