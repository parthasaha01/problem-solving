#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int T, test=1;
    double d, v, u, diff;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%lf %lf %lf", &d, &v, &u);

        if(u<=v || v==0)
        {
            printf("Case %d: can't determine\n", test++);
        }
        else
        {
            diff = d*( (1/sqrt(u*u - v*v)) - (1/u) );
            printf("Case %d: %.3lf\n", test++, diff);
        }
    }

    return 0;
}
