#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int T;
    double r1, r2, r3, a, b, c, s, area, angle1, angle2, angle3;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%lf %lf %lf", &r1, &r2, &r3);

        a = r1+r2;
        b = r1+r3;
        c = r2+ r3;

        s = (a+b+c)/2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));

        angle1 = acos((a*a+b*b-c*c)/(2*a*b));
        angle2 = acos((a*a+c*c-b*b)/(2*a*c));
        angle3 = acos((b*b+c*c-a*a)/(2*b*c));

        area -= 0.5* r1*r1*angle1;
        area -= 0.5* r2*r2*angle2;
        area -= 0.5* r3*r3*angle3;

        printf("%.6lf\n", area);

    }

    return 0;
}
