#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    double x, y, r, length, Min, Max;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%lf %lf %lf", &x, &y, &r);

        length = sqrt((x*x)+(y*y));

        Min = r-length;
        Max = r+length;

        printf("%0.2lf %0.2lf\n", Min, Max);
    }

    return 0;
}
