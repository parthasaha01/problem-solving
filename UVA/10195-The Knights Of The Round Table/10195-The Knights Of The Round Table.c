#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,s,s1,T,r;

    while(scanf("%lf %lf %lf",&a,&b,&c)==3)
    {
        if(a == 0.0 && b == 0.0 && c == 0.0)
            printf("The radius of the round table is: 0.000\n");

        else

        {
            s=(a+b+c)/2.0;

            s1=s*(s-a)*(s-b)*(s-c);

            T=sqrt(s1);

            r=(2*T)/(a+b+c);

            printf("The radius of the round table is: %.3lf\n",r);
        }

    }

    return 0;
}
