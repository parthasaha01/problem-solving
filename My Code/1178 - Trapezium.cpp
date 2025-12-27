#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,d;
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(a<c)swap(a,c);

        double x = a-c;
        double s = (b+d+x)/2.0;
        double triangle = sqrt(s*(s-b)*(s-d)*(s-x));
        double h = (2*triangle)/x;
        //double parallelogram = h*a;
        //double trapezium = parallelogram - triangle;
        double trapezium = 0.5*(a+c)*h;
        printf("Case %d: %0.9lf\n",ks,trapezium);
    }
    return 0;
}
