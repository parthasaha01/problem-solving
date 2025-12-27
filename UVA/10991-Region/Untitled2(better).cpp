#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
double get_triangle_area( double a, double b, double c)
{
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
double circle_angle(double a, double b, double c)
{
    return acos( (a*a + b*b - c*c) / (2*a*b) );
}
int main()
{
    int T;
    double r1, r2, r3, a, b, c, tri_area, area1, area2, area3, area, angle1, angle2, angle3;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%lf %lf %lf", &r1, &r2, &r3);

        a = r1+r2;
        b = r1+r3;
        c = r2+ r3;

        tri_area = get_triangle_area( a, b, c);

        angle1 = circle_angle( a, b, c);
        angle2 = circle_angle( a, c, b);
        angle3 = circle_angle( b, c, a);

        area1 = 0.5* r1*r1*angle1;      // area = (PI*r1*r1)*( angle1 / 2*PI)
        area2 = 0.5* r2*r2*angle2;
        area3 = 0.5* r3*r3*angle3;

        area = tri_area-(area1+area2+area3);

        printf("%.6lf\n", area);

    }

    return 0;
}
