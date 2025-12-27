#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)

int main()
{
    long int T, L;
    double  W, r, area, red, green;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &L);

        W = (0.6)*L;

        area = L*W;

        r = L/5.0;

        red = PI*r*r;

        green = area-red;

        printf("%.2lf %.2lf\n", red, green);
    }

    return 0;
}
