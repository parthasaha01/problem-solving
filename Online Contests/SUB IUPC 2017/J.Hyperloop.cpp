#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
const double mx = 1000000000000000001.0;
const double mn = 0.000000001;
double aa,dd;
double time(double r)
{
    return ((4*PI*r)+ dd) / (2*sqrt(PI*r*aa));
}
double fun()
{
    double lo = mn;
    double hi = mx;

    for(int i=1; i<=200; i++){
        double x1 = (2*lo+hi)/3.0;
        double x2 = (lo+2*hi)/3.0;

        if(time(x1)<time(x2)) hi = x2;
        else lo = x1;
    }

    return lo;
}
int main()
{
    int tt; scanf("%d",&tt);

    while(tt--)
    {
        scanf("%lf%lf",&aa,&dd);

        double ans = fun();

        printf("%.11lf\n",ans);
    }

    return 0;
}
