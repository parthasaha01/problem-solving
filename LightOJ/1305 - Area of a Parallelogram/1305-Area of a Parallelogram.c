#include<stdio.h>
int main()
{
    int T, test=0;
    double  x1, y1, x2, y2, x3, y3, x4, y4, area;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

        x4 = x3-(x2-x1);
        y4 = y1+(y3-y2);

        area = 0.5*( ((x1*y2)+(x2*y3)+(x3*y4)+(x4*y1)) - ((y1*x2)+(y2*x3)+(y3*x4)+(y4*x1)) );

        if(area < 0)
            area = -area;

        printf("Case %ld: %0.lf %0.lf %.0lf\n", ++test, x4, y4, area);
    }

    return 0;
}
