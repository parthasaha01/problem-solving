#include<stdio.h>
#include<math.h>
#define PI 2*acos(0.0)
int main()
{
    double r,n,p;

    while(scanf("%lf %lf",&r,&n)==2)
    {
        p=( n*r*r*sin( (2*PI) / n) )/2.0;
        printf("%.3lf\n",p);
    }

    return 0;
}
