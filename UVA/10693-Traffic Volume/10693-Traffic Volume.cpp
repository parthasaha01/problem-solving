#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double L, f, v, vol;

    while(scanf("%lf %lf", &L, &f)==2)
    {
        if(!L && !f)
            break;

        v = sqrt(2*f*L);
        vol = (v*1800)/L;    // volume = (v*3600) / (2*L)

        printf("%.8lf %.8lf\n", v, vol);
    }

    return 0;
}
