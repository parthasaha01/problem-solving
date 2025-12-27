#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)
int main()
{
    long int T, i=0;
    double r, area;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%lf", &r);

        area = r*r*(4-PI);              /* area = (4*r*r) - (PI*r*r)  */

        printf("Case %ld: %.2lf\n", ++i, area);
    }

    return 0;
}
