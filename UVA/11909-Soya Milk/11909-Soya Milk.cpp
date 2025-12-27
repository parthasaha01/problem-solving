#include<cstdio>
#include<cmath>
#define PI acos(-1)
using namespace std;
int main()
{
    double l, w, h, angle, x, y, p, volume, area;

    while(scanf("%lf %lf %lf %lf", &l, &w, &h, &angle)==4)
    {
        angle = (PI/180.0)*angle;
        x=tan(angle);
        y=l*x;

        if(y<h)
        {
            p=0.5*l*y;
            area =(h*l)-p;
            volume = area*w;
        }
        else
        {
            y=h/x;
            area = 0.5*h*y;
            volume = area*w;
        }

        printf("%.3lf mL\n", volume);
    }

    return 0;
}
