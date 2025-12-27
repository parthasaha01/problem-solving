#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)
int main()
{
    double s, a, chord, arc, rad;
    char str[10];

    while(scanf("%lf %lf %s", &s, &a, str)==3)
    {
        s += 6440;

        if(a > 180)
            a=360-a;

        if(!strcmp(str, "min"))
            a = a/60.0;

        rad=(PI*a)/180.0;

        arc = s*rad;
        chord = 2*s*sin(rad/2.0);

        printf("%0.6lf %0.6lf\n", arc, chord);
    }

    return 0;
}
