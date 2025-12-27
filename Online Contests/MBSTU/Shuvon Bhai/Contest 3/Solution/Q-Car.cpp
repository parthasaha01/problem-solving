#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    long int j=0;
    double i, u, v, t, a, s;

    while(scanf("%lf", &i)==1 && i != 0.0)
    {
        if(i == 1.0)
        {
            scanf("%lf %lf %lf", &u, &v, &t);

            a = (v-u)/t;

            s = (v*v - u*u) / (2*a);

            if(s<0.0)
                s = -s;

            printf("Case %ld: %.3lf %.3lf\n", ++j, s, a);

        }
        else if(i == 2.0)
        {
            scanf("%lf %lf %lf", &u, &v, &a);

            s = (v*v - u*u) / (2*a);

            if(s<0.0)
                s = -s;

            t = (v-u)/a;

            if(t<0.0)
                t = -t;

            printf("Case %ld: %.3lf %.3lf\n", ++j, s, t);

        }
        else if(i == 3.0)
        {
            scanf("%lf %lf %lf", &u, &a, &s);

            v = sqrt( (u*u) + (2*a*s) );

            t = (v-u)/a;

            if(t<0.0)
                t = -t;

            printf("Case %ld: %.3lf %.3lf\n", ++j, v, t);

        }
        else
        {
            scanf("%lf %lf %lf", &v, &a, &s);

            u = sqrt( (v*v) - (2*a*s) );

            t = (v-u)/a;

            if(t<0.0)
                t = -t;

            printf("Case %ld: %.3lf %.3lf\n", ++j, u, t);

        }
    }

    return 0;
}
