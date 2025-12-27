#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a;
    double angle = sin(108*M_PI/180.0) / sin(63*M_PI/180.0);

    while(scanf("%lf",&a)==1)
    {
        double res= angle*a;

        printf("%.10lf\n",res);
    }
    return 0;
}
