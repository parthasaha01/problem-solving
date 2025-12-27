#include<bits/stdc++.h>
using namespace std;
int main()
{
    double p,q,r,s,t,u,x;

    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6)
    {
        double x=0.0;
        double lo=0.0;
        double hi=1.0;
        double fn = 0.0;
        for(int i=1; i<=200; i++)
        {
            x = (lo+hi)/2.0;
            fn=0.0;

            fn += p/exp(x);
            fn += q*sin(x);
            fn += r*cos(x);
            fn += s*tan(x);
            fn += t*x*x;
            fn+=u;

            if(fn>0)lo=x;
            else hi=x;
        }

        if(abs(fn-0.0)<=0.000001)printf("%.4lf\n",x);
        else printf("No solution\n");
    }

    return 0;
}
