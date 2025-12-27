#include<stdio.h>
#include<math.h>
#define PI 2*acos(0)
int main()
{
    long int a,b,c;
    double s, s1, s2, T, C1, C2, S, V, R, r1, r2;

    while(scanf("%ld %ld %ld",&a,&b,&c)==3)
    {
        s=(a+b+c)/2.0;
        s1=s*(s-a)*(s-b)*(s-c);
        s2=sqrt(s1);

        T=s2;

        r1=T/s;
        C1=(PI*r1*r1);

        r2=(a*b*c)/(4.0*s2);
        C2=(PI*r2*r2);

        R=C1;
        V=(T-R);
        S=(C2-(R+V));

        printf("%.4lf %.4lf %.4lf\n",S,V,R);

    }

    return 0;
}
